************************************************
* Graphics code Color Computer 3 
* copyright Chris Lomont 2006 www.lomont.org
************************************************

************************************************
* Variables for current graphics state
************************************************
vidstart	rmd	1	video start page for drawing	


************************************************
* DrawFilledBox - draw a filled box on the screen
* REGX	x coord 0-319
* REGY	y coord 0-199
* REGB	height
* REGU	width
* REGA 	color 0-15
* todo - unify graphics functions, inputs, etc.
* registers changed: none
************************************************
DrawFilledBox
	pshs	u,y,x,b,a	
	pshs	u,y,x,b		current values	
	* stack:  u:13,s y:11,s x:9,s b:8,s a:7,s 
	* current cu:5,s cy:3,s cx:1,s cb: ,s
outer@	ldx	13,s		original width
	stx	5,s		current width
	ldx	9,s		original x
	stx	1,s		current x		  
inner@	ldx	1,s		current x
	ldy	3,s		current y
	lda	7,s		original color
	lbsr	SetPixel 	(x,y,a)
	leax	1,x		next pixel
	stx	1,s		current x
	ldd	5,s		current width
	subd	#1
	std	5,s
	bne	inner@		some left to do
	leay	1,y		next y value
	sty	3,s		current y
	ldb	,s		current height
	decb
	stb	,s
	bne	outer@
	puls	u,y,x,b		pop current vals	
	puls	x,y,u,a,b	pop stored vals
	rts

************************************************
* Get a pixel address in 320x200x16 color mode
* REGX	x coord 0-319
* REGY	y coord 0-199
* Return address of pixel in REGU
* Registers changed: REGU
************************************************
GetPixelAddress
	pshs	x,y,d		save these
	tfr	y,d		want 160*y todo - faster with shift and add tricks?
	lda	#160
	mul	
	addd	vidstart	
	pshs	d		save this	
	tfr	x,d	
	lsra			divide by two to get byte offset
	rorb
	addd	,s		add back rest		
	tfr	d,u		final byte pointer in u
	puls	d
	puls	x,y,d
	rts

************************************************
* Set a pixel in 320x200x16 color mode
* REGA 	color 0-15
* REGX	x coord 0-319
* REGY	y coord 0-199
* Registers changed: none
************************************************
SetPixel
	*clamp pixels for safety? todo: or add outer clamping rountine
	cmpx	#320
	bge	pixext@		out of bounds
	cmpy	#200
	bge	pixext@		out of bounds
	pshs	u,y,x,d		save these
	bsr	GetPixelAddress final byte offset in REGU
	lda	,s 		get pixel color value
	anda	#$0F		clamp
	ldb	3,s		get x low nibble
	andb	#1
	beq	even@	
	ldb	#$F0		mask
	bra	write@	
even@	ldb	#$0F		mask
	lsla			shift to high nibble
	lsla
	lsla
	lsla
write@	andb	,u		mask out
	stb	,u
	ora	,u		write pixel
	sta	,u
	puls	u,x,y,d		restore from stack
pixext@	rts

************************************************
* Get a pixel in 320x200x16 color mode
* REGX	x coord 0-319
* REGY	y coord 0-199
* return REGA 	color 0-15
* Registers changed: REGA
************************************************
GetPixel
	clra			default
	cmpx	#320
	bge	pixext@		out of bounds
	cmpy	#200
	bge	pixext@		out of bounds	
	pshs	u,x,y,b		save these
	bsr	GetPixelAddress final byte offset in REGU
*	tfr	y,d		want 160*y todo - faster with shift and add tricks?
*	lda	#160
*	mul	
*	addd	vidstart	
*	pshs	d		save this	
*	tfr	x,d	
*	lsra			divide by two to get byte offset
*	rorb
*	addd	,s		add back rest		
*	tfr	d,y		final byte pointer in y
*	puls	d		restore stack	
	lda	,u 		get pixel value
	ldb	2,s		get x low nibble
	andb	#1
	beq	even@
	anda	#$0F		clamp
	bra	done@	
even@	lsra			shift to low nibble
	lsra
	lsra
	lsra
done@	puls	u,x,y,b		restore from stack
pixext@	rts



************************************************
* Set graphics memory - sets 32K in 0x8000-0xFFFF 
* from MMU pages 0x60000 on up 
* interrupts should be disabled to use this
* REGA - first page to load (nice start pages are 48 and 52)
* Registers changed: REGX,REGD
************************************************
SetGraphicsMem2
	* set graphics screen to $2000-$3FFF
*	lda	#48		first block of graphics at $60000
	ldx	#$FFA4		mapped to $8000-$9FFF, then more
	ldb	#4		
!	sta	,x+
	inca	
	decb
	bne	<		
	ldd	#$8000
	std	vidstart
	rts		

************************************************
* Set a graphics  mode 320x200x16 color mode
* from GIME docs: HR2 HR1 HR0 CR1 CR0
*                  1   1   1   1   0    320 pixels, 16 colors
* TODO REGX contains 16 bit address for video start, aligned on 8 byte boundary
************************************************
SetGr320 
	lda 	#%01001100 	Coco3, MMU on, DRAM constant, standard SCS 16K internal 16K external ROM
	sta 	$FF90
	lda	#%10000000	
	sta	$FF98 		graphics mode, 60 hz, normal burst
	lda	#%00111110 	width 320, height 200
	sta	$FF99 	
	clr	$FF9C		low 4 bits are vertical scroll
	
	ldd	#$C000		first block of graphics screen at $60000 / 8
	std	$FF9D		vidstart offset
	clr	$FF9F		clear horiz scroll
	
	lda	#48		this page default
	jsr	SetGraphicsMem2	set the memory pages

	ldx	#$FFB0		set some palette entries
	ldy	#palette
	ldb	15
!	lda	,y+
	sta	,x+
	decb	
	bne	<
			
	rts

* default palette
palette	
	fcb	%00000000,%00000111,%00111000,%00111111
	fcb	%00000100,%00100000,%00100100
	fcb	%00000010,%00010000,%00010010
	fcb	%00000001,%00001000,%00001001
	fcb	%00110110,%00101101,%00011011

************************************************
* Set a palette entry (RGB Monitor mode - todo - map to TV mode also)
* REGA is color bits (0,0,RH,GH,BH,RL,GL,BL)
* REGB is color index to set 0-15
* Registers changed: REGX, REGD 
************************************************
SetPaletteEntry
	andb	#15	
	ldx	#$FFB0
	abx
	sta	,x	
	rts

************************************************
* Set a graphics mode
* Registers changed: REGA 
************************************************
SetPMODE4
	clr 	$ffc0
	clr 	$ffc3
	clr 	$ffc5 	gives RG6 (PMODE4)
	lda 	$ff
	sta 	$ff22
	rts

************************************************
* Set text mode
************************************************
TextMode
	clr 	$ffc0
	clr 	$ffc2
	clr 	$ffc4 	gives text mode
	lda 	#8
	sta 	$ff22
	rts

************************************************
* EnableGraphicsPage - set one of the two 320x200x16 pages
* into visible memory at vidstart
* REGA is 0 or 1
* Registers changed: None
************************************************
EnableGraphicsPage
	pshs	x,d
	tsta	
	bne	>
	lda	#48
	lbsr	SetGraphicsMem2
	bra	exit@
!	cmpa	#1
	bne	exit@
	lda	#52	
	lbsr	SetGraphicsMem2	
exit@	puls	x,d		
	rts

************************************************
* TestHiColor - test a hi color image
* assmues already in 320x200x16 mode
* Registers changed: None
************************************************
TestHiColor 
	ldx	#0
	ldy	#0
	ldu	#10
	ldb	#30
	lda	#0
!	lbsr	DrawFilledBox
!	bra	<
	exg	d,x
	addd	#15
	cmpd	#320
	bge	>
	exg	d,x
	inca			next color
	bra	<
!	bra	<
	rts

* REGX	x coord 0-319
* REGY	y coord 0-199
* REGB	height
* REGU	width
* REGA 	color 0-15
* todo - unify graphics functions, inputs, etc.


* end of file - Graphics.asm