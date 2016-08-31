************************************************
* Mandelbrot Explorer for Color Computer 3 
* copyright Chris Lomont 2006 www.lomont.org
* main file
************************************************

* push S order: PC,U,Y,X,DP,B,A,CC low byte first, S pre-decremented 

	if 0
	org	356	disk basic autostart - replace jump vectors
	lbra	start
	lbra	start
	lbra	start
	endif

	org	$E00		3584 decimal		
************************************************
* Program starts here
************************************************
start	clr	$FFD9		high speed poke (todo - undo at end?)
	lbsr	IntroScreen
*	lbsr	TestFPCode
	lbsr	DisableInterrupts	interrupts puke once we replace top of ram
	lbsr	SetGr320	320x200x16 mode

	if 0
	* test the set pixel funcs function
	lda	#$44		sample color
	lbsr	ClearScreen
	ldx	#0
	ldy	#10
	lda	#8
top@	lbsr	SetPixel
	leax	1,x
	cmpx	#320
	bge	done@
	leay	1,y
	cmpy	#30
	blt	top@
	leay	-2,y	
top2@	lbsr	SetPixel
	leax	1,x
	cmpx	#320
	bge	done@
	leay	-1,y
	cmpy	#10
	bgt	top2@
	bra	top@
done@	bra	done@	

	* mandel brot block 190-200 x 20-30 should be all zeros	
	ldx	#200
	ldy	#20
	lbsr	MandelbrotComputePoint	should return 0
	
	* mandel brot block 190-200 x 20-30 should be all zeros	
	ldx	#190
	ldy	#20
!	lbsr	MandelbrotComputePoint
	cmpd	#0
	bne	error
	leax	1,x
	cmpx	#200
	blt	<
	ldx	#190
	leay	1,y
	cmpy	#30
	blt	<
ok	bra	ok
	
error	bra	error	
	endif
	
	
*	lbsr	TestHiColor
	
*	lbsr	TestingRoutines

	lda	#$11		sample color
	bsr	ClearScreen
	
	ldd	#0	*clrd 	- todo - 6309 only? 

	* test upper corner, and orientation
	lda	#3		pixel color,x,y
	ldx	#0
	ldy	#0
	lbsr	SetPixel
	leax	1,x
	leay	1,y
	lbsr	SetPixel

	* test lower corner	
	lda	#6
	ldx	#319
	ldy	#199
	lbsr	SetPixel

	* draw diagonal line
	lda	#3
	ldx	#5
	ldy	#5
	ldb	#170
!	lbsr	SetPixel
	leax	1,x
	leay	1,y
	inca
	decb	
	bne	<	

	* wait till no key pressed
keytest@ lbsr	Keyboard_KeyCode
	tsta
	bne	keytest@


	* compute mandelbrot color for every pixel
startMandel 		
	bsr	ResetPixelPos
mndloop	lbsr	DrawMandelbrotPixel
	bsr	ProcessKeys	
	lbsr	IncrementPixelPos2
	tsta		
	bne	mndloop		not done

	* todo - only run keypress routines here?
kloop@	bsr	ProcessKeys
	tsta
	beq	kloop@

	bra	startMandel 	keep doing

			
* todo - enable cleanup rountines
	rts			return?!	

* check for keys pressed, and process them
* returns REGA = 0 if nothing to do, else REGA != 0 
ProcessKeys
	* if a key is pressed, do the interface 
	lbsr	Keyboard_KeyCode
	tsta
	beq	nokey@
	lbsr	Interface_Run
	tsta	
	beq	nokey@		nothing to do
	pshs	a		save this
	bsr	HandleCommand	
	puls	a
nokey@	rts



* Clear the screen, with color in REGA (both nibbles!)
ClearScreen 	
	pshs	x,y
	ldx	vidstart	clear screen
	ldy	#32000		this is 320*200/2 bytes, i.e. screensize
	lbsr	memset
	puls	x,y
	rts		

* handle a key command in REGA
* changes all regs
*	0 - continue as usual
*	1 - do new position
*       2 - reset region to default
HandleCommand
	cmpa	#1		 	is it new position?
	bne	>
	ldd	#50			iterations - todo - obtain elsewhere
	tfr	d,y
	lbsr	Interface_GetBoxCoords
	lbsr	MandelbrotZoom
	bra	clear@
!	cmpa	#2			is it reset region?
	bne	return@			nothing to do
	lbsr	MandelbrotReset 	reset region
clear@	bsr	ResetPixelPos		reset pixel position
	lda	#$11
	bsr	ClearScreen		clear screen
return@	rts


************************************************
* Mandelbrot pixel coords and funcs
* 
************************************************
MandelXPixel	fcb	0,0	current x pixel to draw
MandelYPixel	fcb	0,0	current y pixel to draw
MandelSkipPix	fcb	8	pixel skip for current pass
ResetPixelPos	
	ldd	#0
	std	MandelXPixel
	std	MandelYPixel
	lda	#8
	sta	MandelSkipPix		
	rts
	
************************************************
* IncrementPixelPos - next pixel values set, 
* simple linear ordering of pixels returned in variables
* Modifies all registers
* returns REGA = 0 if wraps around, else REGA != 0 
************************************************
IncrementPixelPos
	ldd	MandelYPixel
	addd	#8
	std	MandelYPixel
	cmpd	#200
	blt	exit@
	ldd	#0
	std	MandelYPixel
	ldd	MandelXPixel
	addd	#8
	std	MandelXPixel
	cmpd	#320
	blt	exit@
	ldd	#0
	std	MandelXPixel
	lda	#1		assume never done
exit@	rts
	
************************************************
* IncrementPixelPos2 - next pixel values set, 
* subdividing ordering of pixels, draws faster rough image
* Modifies all registers
* returns REGA = 0 if wraps around, else REGA != 0 
************************************************
IncrementPixelPos2	
	lda	#1
	pshs	a		return code default nonzero
	ldd	MandelXPixel
	addb	MandelSkipPix
	adca	#0
	cmpd	#320
	bge	>
	std	MandelXPixel
	bra	done@
!	ldd	#0		x overflow, clear it
	std	MandelXPixel
	ldd	MandelYPixel
	addb	MandelSkipPix
	adca	#0
	cmpd	#200
	bge	>
	std	MandelYPixel
	bra	done@
!	ldd	#0
	std	MandelYPixel
	lda	MandelSkipPix	screen done, shrink skip, and do more
	lsra
	beq	>
	sta	MandelSkipPix
	bra	done@						
!	lda	#8		start at top - todo- mark as finished
	sta	MandelSkipPix
	clr	,s
done@	lda	MandelSkipPix	finally, if (x%(skip*2))==0 and (y%(skip*2))==0 and skip != 8, do again
	cmpa	#8
	beq	exit@
	lsla			2*skip
	deca			make mask
	tfr	a,b
	anda	MandelXPixel+1	check lower byte
	bne	exit@
	andb	MandelYPixel+1	check lower byte
	bne	exit@
	bsr	IncrementPixelPos2	already did this pixel, go to next
exit@	puls	a			return code
	rts

************************************************
* DrawMandelbrotPixel - compute current mandelbrot 
* color, then draws a pixel or box, based on coord and size  
* Modifies all registers
************************************************
DrawMandelbrotPixel
	ldx	MandelXPixel
	ldy	MandelYPixel
	lbsr	MandelbrotComputePoint	get color in REGD
	tfr	d,u			store color
	ldb	MandelSkipPix
	cmpb	#1
	beq	>			use SetPixel if skip size 1 todo - use bne here
	clra
	exg	d,u			d has color, u has width
	tfr	b,a			a has color
	ldb 	MandelSkipPix		b has height
	lbsr	DrawFilledBox		
	bra	done@
!	tfr	u,d
	tfr	b,a			color to REGA
	lbsr	SetPixel
done@	rts		

************************************************
* TestingRoutines - place routines here for some testing
* modifies all registers
************************************************
TestingRoutines
*	lbsr	TestProfiler
*	lbsr	Keyboard_Test
	lbsr	TestPixels

	* testing for mandelbrot speed fixing
!	lbsr	EnableProfiler
	lbsr	StartProfiler

	ldx	#160
	ldy	#100
	lbsr	MandelbrotComputePoint

	lbsr	StopProfiler		REGD now has approx cycle count of $759
	lbsr	DisableProfiler
	bra	<	

*	lbsr	TestFPCode
	rts


TestPixels
	lda	#7
	ldx	#1
	ldy	#0
	lbsr	SetPixel
	clra
	lbsr	GetPixel

	lda	#11
	ldx	#49
	ldy	#50
	lbsr	SetPixel
	clra
	lbsr	GetPixel

	lda	#13
	ldx	#49
	ldy	#49
	lbsr	SetPixel
	clra
	lbsr	GetPixel

	lda	#3
	ldx	#50
	ldy	#49
	lbsr	SetPixel
	clra
	lbsr	GetPixel

	rts



************************************************
* memset - fill memory
* REGX = start address
* REGY = length
* REGA = filler byte
* modifies REGX, REGY
************************************************
memset
!	sta	,x+	
	leay	-1,y
	bne	<
	rts

************************************************
* memcpy - copy non-overlapping memory
* REGX = source address
* REGY = dest address
* REGD = length
* Registers modified: none
************************************************
memcpy
	pshs	x,y,d	
!	pshs	a
	lda	,x+
	sta	,y+	
	puls	a
	subd	#1
	bne	<
	puls	x,y,d
	rts
	
************************************************
* Disable/Enable interrupts 
************************************************
DisableInterrupts
	orcc	#$50		disable interrupts
	rts
	
EnableInterrupts	
	andcc	#$AF		enable interrupts
	rts	
	
	
************************************************
* Splash screen 32x16
************************************************
* todo - better instructions, version
splash	fcc	"  COCO MANDELBROT RENDERER V0.5 "	
	fcc	"        CHRIS LOMONT 2006       "	
	fcc	"          WWW.LOMONT.ORG        "	
	fcc	"================================"	
	fcc	"PRESS ANY KEY TO ENTER SELECT   "
	fcc	"MODE.                           "
	fcc	"ARROWS MOVE SELECT BOX.         "	
	fcc	"SHIFT-ARROWS SIZE BOX.          "	
	fcc	"ENTER - SELECTS.                "	
	fcc	"ESC   - CANCELS.                "	
	fcc	"R     - RESETS.                 "	
	fcc	"                                "
	fcc	"                                "
	fcc	"                                "
	fcc	"                                "
*	fcc	"+/- SETS ITERATION MAX*         "	
*	fcc	"H-256 COLOR*  G-REFINE REGION*  "
*	fcc	"I-RENDER INFO*       E-SAVE*    "
*	fcc	"* - NOT IMPLEMENTED             "	
	fcc	"     PRESS ANY KEY TO START     "

************************************************
* Draw splash screen, wait for keypress
************************************************
IntroScreen
	* todo - make uppercase
	ldx	#splash
	ldy	#$400
	ldd	#512
	lbsr	memcpy
			
	* wait till no key pressed, then key pressed, then no key pressed
key1@ 	lbsr	Keyboard_KeyCode
	tsta
	bne	key1@
key2@ 	lbsr	Keyboard_KeyCode
	tsta
	beq	key2@
key3@ 	lbsr	Keyboard_KeyCode
	tsta
	bne	key3@	
	rts
	

	include Profiler.asm		include an instruction count profiler
	include Keyboard.asm		supports keyboard reading and interrupts
	include FixedPoint.asm		fixed point math routines
	include Mandelbrot.asm	 	mandelbrot rendering functions
	include Interface.asm 		the interface handling code
	include Graphics.asm		basic graphics routines

	end	start

* end - Mandelbrot.asm