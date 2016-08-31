************************************************
* Mandelbrot Explorer interface for Color Computer 3 
* copyright Chris Lomont 2006 www.lomont.org
************************************************

************************************************
* Interface state variables
* here we store state variables for the interface
************************************************
Interface_X1	fdb	120	box positions
Interface_Y1	fdb	 75
Interface_XW	fdb	 80	box size
Interface_YW	fdb	 50
Interface_Color	fcb	 13	color
Interface_Store	rmb	1680	320*4+200*2	space for storage
Interface_Reset	fcb	0	reset button count

************************************************
* Interface_GetBoxCoords - get the box coords
* REGX x1 coord 0-319 upper left
* REGU x2 coord 0-319 lower right
* REGA y1 coord 0-199 upper left
* REGB y2 coord 0-199 lower right
* Registers changed: REGX, REGU, REGA, REGB
************************************************
Interface_GetBoxCoords
	ldx	Interface_X1	x1
	ldd	Interface_X1
	addd	Interface_XW
	tfr	d,u		x2
	lda	Interface_Y1+1	y1
	tfr	a,b
	addb	Interface_YW+1	y2
	rts

************************************************
* Interface_Run - handle the keyboard interface
* REGA returns a command:
*	0 - continue as usual
*	1 - do new position
*       2 - reset region to default
* Registers changed: REGA
************************************************
BoxMinX	equ	#32		32x20 pixel box minimal
BoxMinY	equ	#20		
Interface_Run
	pshs	u,y,x,b
	
	clr	Interface_Reset		count set to 0
	
intloop				
	* draw box
	
	lda	Interface_Color
	anda	#$F
	pshs	a			color	
	ldx	Interface_X1		x start
	ldy	Interface_Y1		y start
	ldu	Interface_XW		width
	ldd	Interface_YW		height
	lbsr	Interface_StoreBox	
	lbsr	Interface_DrawBox
	puls	a

	inc	Interface_Color		next color

	* delay, then restore image
	ldd	#$2000
!	subd	#1
	bne	<

	* restore box
	ldx	Interface_X1		x start
	ldy	Interface_Y1		y start
	ldu	Interface_XW		width
	ldd	Interface_YW		height
	lbsr	Interface_RestoreBox	

	
	* handle box keys
	lda	#VK_SHIFT
	lbsr	Keyboard_IsKeyDown
	bne	noshift@
	lda	#VK_UP
	lbsr	Keyboard_IsKeyDown
	bne	>
	ldd	Interface_YW
	cmpd	#BoxMinY
	ble	>
	subd	#1
	std	Interface_YW	
!	lda	#VK_DOWN
	lbsr	Keyboard_IsKeyDown
	bne	>
	ldd	Interface_YW
	addd	Interface_Y1
	cmpd	#199
	bge	>
	ldd	Interface_YW
	addd	#1
	std	Interface_YW	
!	lda	#VK_LEFT
	lbsr	Keyboard_IsKeyDown
	bne	>
	ldd	Interface_XW
	cmpd	#BoxMinX
	ble	>
	subd	#1
	std	Interface_XW
!	lda	#VK_RIGHT
	lbsr	Keyboard_IsKeyDown
	bne	keydone@
	ldd	Interface_X1
	addd	Interface_XW
	cmpd	#319
	bge	keydone@
	ldd	Interface_XW
	addd	#1
	std	Interface_XW	
	bra	keydone@
noshift@ lda	#VK_DOWN 		non shifted keys
	lbsr	Keyboard_IsKeyDown
	bne	>
	ldd	Interface_YW
	addd	Interface_Y1
	cmpd	#199
	bge	>
	ldd	Interface_Y1
	addd	#1
	std	Interface_Y1	
!	lda	#VK_UP
	lbsr	Keyboard_IsKeyDown
	bne	>
	ldd	Interface_Y1
	cmpd	#0
	beq	>
	subd	#1
	std	Interface_Y1	
!	lda	#VK_RIGHT
	lbsr	Keyboard_IsKeyDown
	bne	>
	ldd	Interface_X1
	addd	Interface_XW
	cmpd	#319
	bge	>
	ldd	Interface_X1
	addd	#1
	std	Interface_X1
!	lda	#VK_LEFT
	lbsr	Keyboard_IsKeyDown
	bne	keydone@
	ldd	Interface_X1
	cmpd	#0
	beq	keydone@
	subd	#1
	std	Interface_X1	
keydone@

	* todo +- keys
	lda	#VK_PLUS
	lbsr	Keyboard_IsKeyDown
	* todo - action
	lda	#VK_MINUS
	lbsr	Keyboard_IsKeyDown
	* todo - action
	
	
	* check for exit
	clrb				assume nothing to do	
	lda	#VK_ESC
	lbsr	Keyboard_IsKeyDown
	beq	intexit			

	clrb				assume nothing to do	
	lda	#VK_SPACE
	lbsr	Keyboard_IsKeyDown
	beq	intexit			

	ldb	#1			assume new image to draw 	
	lda	#VK_ENTER
	lbsr	Keyboard_IsKeyDown
	beq	intexit			

	lda	#VK_R
	lbsr	Keyboard_IsKeyDown
	bne	>			
	* increment reset counter, flash screen, and see if time to reset
*	inc	Interface_Reset	
*	bsr	Interface_InvertScreen	
*	bsr	Interface_InvertScreen	
*	ldb	Interface_Reset
*	cmpb	#3
*	blt	>
			 
	ldb	#2			reset drawing to main
	bra	intexit			reset screen

!	lbra	intloop			continue
			
intexit		
	* b holds return action
	* a holds keycode that caused exit
	
!	lbsr	Keyboard_IsKeyDown
	beq	<			loop till key depressed			

	* delay, to let key come up
	* todo - add delay function somewhere with 32 bit cycle count
	pshs	b			save return action
*	ldd	#$4000			
*!	nop				delay to avoid key bounce
*	nop
*	subd	#1
*	bne	<
	puls	a			restore return action

	puls	u,y,x,b
	rts

************************************************
* TODO - make all box saving, restoring, and drawing
* go through same function to remove duplicate code (and bugs)
************************************************

************************************************
* TODO - move these functions to graphics lib
* TODO - needs major speedups - do in graphics lib
************************************************

************************************************
* Interface_InvertScreen - invert all screen colors
* Registers changed: None 
************************************************
Interface_InvertScreen
	pshs	x,y,a
	ldx	#0
	ldy	#0
loopx@	lbsr	GetPixel
	coma	
	anda	#15
	lbsr	SetPixel
	leax	1,x
	cmpx	#320
	blt	loopx@
	ldx	#0
	leay	1,y
	cmpy	#200
	blt	loopx@
	puls	x,y,a	
	rts


************************************************
* Interface_HLine - draw horiz line
* REGX - x coord left
* REGY - y coord left
* REGU - length going to right
* REGA - color 
* Registers changed: None 
************************************************
Interface_HLine
	pshs	x,u
loop@	lbsr	SetPixel
	leax	1,x
	leau	-1,u
	cmpu	#0
	bne	loop@
	puls	x,u
	rts

************************************************
* Interface_VLine - draw vert line
* REGX - x coord top
* REGY - y coord top
* REGU - length going to bottom
* REGA - color 
* Registers changed: None 
************************************************
Interface_VLine
	pshs	u,y,x,d		ptr:10,s u:6,s, y:4,s x:2,s d:,s
	tfr	u,d		length counter
	lbsr	GetPixelAddress	dest in REGU
	tfr	d,y		length
	tfr	x,d		x coord
	lda	,s		color byte	
	pshs	a		save this
	andb	#1		was x odd?
	bne	oddx@		yes
	ldb	#$0F		bit mask
	lsla			color to high nibble 
	lsla		
	lsla
	lsla
	sta	,s		save this
	bra	loop@
oddx@	ldb	#$F0		bit mask		
loop@	tfr	b,a		copy mask
	anda	,u		mask pixel byte
	ora	,s		set pixel
	sta	,u		save byte
	leau	160,u		next line
	leay	-1,y
	cmpy	#0
	bne	loop@
	puls	a		clear stack
	puls	u,y,x,d
	rts

************************************************
* Interface_Box - draw rectangle
* REGX - x coord left
* REGY - y coord left
* REGU - length to right
* REGD - length to bottom
* ,s   - color (on stack) 
* Registers changed: none 
************************************************
Interface_DrawBox
	pshs	u,y,x,d		color:10,s u:6,s y:4,s x:2,s d:,s
	
	lda	10,s		get color
	bsr	Interface_HLine (x,y,u,a)	
	ldu	,s		height	
	bsr	Interface_VLine
	
	ldd	2,s
	addd	6,s		right x value
	tfr	d,x
	ldu	,s		height
	lda	10,s		color
	bsr	Interface_VLine

	ldd	4,s
	addd	,s		bottom y value
	tfr	d,y
	ldx	2,s
	ldu	6,s		height
	lda	10,s		color
	bsr	Interface_HLine
	
	puls	u,x,y,d
	rts


************************************************
* Interface_SaveHLine - store horiz line pixels in buffer
* REGX - x coord left
* REGY - y coord left
* REGU - length going to right
* ,s   - color buffer pointer 
* Registers changed: None 
************************************************
Interface_SaveHLine
	pshs	u,y,x,d		ptr:10,s u:6,s y:4,s, x:2,s d:,s
	tfr	u,d		length	
	lbsr	GetPixelAddress	src in REGU	
	addd	#2		round up
	lsra			divide by two
	rorb
	tfr	u,x		source addr
	ldy	10,s		ptr to buffer
	lbsr	memcpy
	pshs	y
	addd	,s
	puls	y
	std	10,s		update pointer	
	puls	u,y,x,d
	rts

************************************************
* Interface_SaveVLine - store horiz line pixels in buffer
* REGX - x coord top
* REGY - y coord top
* REGU - length going to bottom
* ,s   - color buffer pointer 
* Registers changed: None 
************************************************
Interface_SaveVLine
	pshs	u,y,x,d	ptr:10,s u:6,s y:4,s x:2,s d:,s
	tfr	u,d		length
	lbsr	GetPixelAddress	src in REGU
	tfr	d,y		length
loop@	lda	,u		get byte containing pixel
	sta	[10,s]		save it here
	ldd	10,s		increment dest pointer
	addd	#1
	std	10,s	
	leau	160,u		next line
	leay	-1,y		done?
	cmpy	#0
	bne	loop@
	puls	u,y,x,d	
	rts
	

************************************************
* Interface_RestoreHLine - restore horiz line pixels from buffer
* REGX - x coord left
* REGY - y coord left
* REGU - length going to right
* ,s   - color buffer pointer 
* Registers changed: None 
************************************************
Interface_RestoreHLine
	pshs	u,y,x,d		ptr:10,s u:6,s y:4,s, x:2,s d:,s
	tfr	u,d		length	
	lbsr	GetPixelAddress	src in REGU	
	addd	#2		round up
	lsra			divide by two
	rorb
	ldx	10,s		src ptr to buffer
	tfr	u,y		dest addr
	lbsr	memcpy
	pshs	x
	addd	,s
	puls	x
	std	10,s		update pointer	
	puls	u,y,x,d
	rts
	

************************************************
* Interface_RestoreVLine - restore horiz line pixels from buffer
* REGX - x coord top
* REGY - y coord top
* REGU - length going to bottom
* ,s   - color buffer pointer 
* Registers changed: None 
************************************************
Interface_RestoreVLine
	pshs	u,y,x,d	ptr:10,s u:6,s y:4,s x:2,s d:,s
	tfr	u,d		length
	lbsr	GetPixelAddress	src in REGU
	tfr	d,y		length
loop@	lda	[10,s]		get byte containing pixel
	sta	,u		save it here
	ldd	10,s		increment dest pointer
	addd	#1
	std	10,s	
	leau	160,u		next line
	leay	-1,y		done?
	cmpy	#0
	bne	loop@
	puls	u,y,x,d	
	rts



************************************************
* Interface_StoreBox - store pixels about
* to be drawn over by box
* REGX - x coord left
* REGY - y coord left
* REGU - length to right
* REGD - length to bottom
* Registers changed: none 
************************************************
Interface_StoreBox
	pshs	u,y,x,d		
	
	ldd	#Interface_Store buffer
	pshs	d		save buffer space u:8,s y:6,s x:4,s d:2,s
		
	lbsr	Interface_SaveHLine (x,y,u)	
	ldu	2,s		height	
	lbsr	Interface_SaveVLine	
	ldd	4,s
	addd	8,s		right x value
	tfr	d,x
	ldu	2,s		height
	lbsr	Interface_SaveVLine
	ldd	6,s
	addd	2,s		bottom y value
	tfr	d,y
	ldx	4,s
	ldu	8,s		height
	lbsr	Interface_SaveHLine
	
	puls	d		restore stack	
	
	puls	u,x,y,d
	rts

************************************************
* Interface_RestoreBox - store pixels about
* to be drawn over by box
* REGX - x coord left
* REGY - y coord left
* REGU - length to right
* REGD - length to bottom
* Registers changed: none 
************************************************
Interface_RestoreBox
	pshs	u,y,x,d		
	
	ldd	#Interface_Store buffer
	pshs	d		buffer space u:8,s y:6,s x:4,s d:2,s
		
	lbsr	Interface_RestoreHLine (x,y,u)	
	ldu	2,s		height	
	lbsr	Interface_RestoreVLine	
	ldd	4,s
	addd	8,s		right x value
	tfr	d,x
	ldu	2,s		height
	lbsr	Interface_RestoreVLine
	ldd	6,s
	addd	2,s		bottom y value
	tfr	d,y
	ldx	4,s
	ldu	8,s		height
	lbsr	Interface_RestoreHLine
	
	puls	d		restore stack	
	
	puls	u,x,y,d
	rts


* end - Interface.asm