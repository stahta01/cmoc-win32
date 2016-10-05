************************************************
* Keyboard code Color Computer 3 
* copyright Chris Lomont 2006 www.lomont.org
************************************************

************************************************
*Keyboard layout for reference - uses registers $FF00 and $FF02
* two characters mean left one is shifted
*                  $FF02
*  LSB                                MSB
*   0    1    2    3    4    5    6    7
*------------------------------------------------------------------------
*
*   @    A    B    C    D    E    F    G        0      LSB
*
*   H    I    J    K    L    M    N    O        1
*                                                        $
*   P    Q    R    S    T    U    V    W        2        F
*                                                        F
*   X    Y    Z    up   dn   lf   rt   space    3        0
*                                                        0
*   0   !/1  "/2   #/3  $/4  %/5  &/6  '/7      4
*
*  (/8  )/9  */:   +/;  </,  =/-  >/.  ? /      5
*            
* enter clr esc/br   alt  ctrl  F1  F2   shifts   6      MSB
*            
*
************************************************

************************************************
* Keycodes used to detect if keys are down or pressed
* high nibble is bit in FF02, low nibble is from FF00
************************************************
VK_UP		equ	$33
VK_DOWN		equ	$43
VK_LEFT		equ	$53
VK_RIGHT	equ	$63
VK_SHIFT	equ	$76
VK_ESC		equ	$26
VK_SPACE	equ	$73
VK_ENTER	equ	$06
VK_R		equ	$22
VK_PLUS		equ	$35	todo - needs shift? - add another bit
VK_MINUS	equ	$55
VH_H		equ	$01

************************************************
* Keyboard_IsKeyDown 
* Input	REGA has a VK_key code to look for
* returns condition 0 is matches, else nonzero
* Registers changed: none
************************************************
keyTbl	fcb	1,2,4,8,16,32,64,128	powers of two table
Keyboard_IsKeyDown
	pshs	x,d	
	ldx	#keyTbl
	tfr	a,b
	lsrb
	lsrb
	lsrb
	lsrb
	abx
	ldb	,x		byte to send in
	
	exg	a,b
	
	coma			invert to check bits
	sta	$FF02		set column strobe
	lda	$FF00		read output
	coma			reverse bits to high to see what was pressed
	anda	#$7F		strip unused high bit
	
	andb	#$0F
	ldx	#keyTbl
	abx
	cmpa	,x		is it what we want?

	puls	x,d
		
	rts



************************************************
* Keyboard_KeyCode - returns keycode in REGD
* 0 is no key down, else return $FF00 after 
* setting all lines
* Registers changed: REGA
************************************************
	
* PIA0 is used for the keyboard. Data register B is programmed
* as output, and is used to strobe keyboard columns. The first
* seven bits of data register A are programmed as inputs and 
* are used to read keyboard rows. Bits 2 and 3 are also used as
* fire button inputs for the joysticks.
Keyboard_KeyCode	
	lda	#$0		ground all bits
	sta	$FF02		set column strobe
	lda	$FF00		read output
	coma			reverse bits to high to see what was pressed
	anda	#$7F		strip unused high bit
	rts
	
************************************************
* Keyboard_Enable - sets hardware registers for reading keyboard
* Registers changed: none
************************************************
Keyboard_Enable
	pshs	d
	clr	$FF01		clear control register A
	clr	$FF03		clear control register B
	clr	$FF00		set side PIA0 side A to input
	ldd	#$FF34
	sta	$FF02		set PIA0 side B to output
	stb	$FF01	
	stb	$FF03
	puls	d
	rts	
	
************************************************
* Keyboard_Test - does some testing of the keyboard
* Registers changed: all
************************************************
Keyboard_Test
	lbsr	Keyboard_Enable

kloop	lbsr	Keyboard_KeyCode
	sta	$400		* value returned
	inc	$402		show movement
	
	ldb	#0		do 8 bits
	pshs	b		save on stack
shift
	ldx	#keyTbl
	abx
	lda	,x
	coma	
	sta	$FF02
	lda	$FF00		get values
	coma			invert
	anda	#$7F		strip high bit
	
	* prepare to write out value 
	ldx	#$460
	lslb
	lslb
	abx	dest

	tfr	a,b
	andb	#15
	cmpb	#$10
	bge	alpha1@
	addb	#$2F 		hex for ASCII '0' minus 1
alpha1@	addb	#1		hex for 'A'		
	stb	1,x
	lsra
	lsra
	lsra
	lsra
	cmpa	#10
	bge	alpha2@
	adda	#$2F
alpha2@	adda	#1 
	sta	,x
	inc	,s
	ldb	,s
	cmpb	#7
	ble	shift

	
	puls	,b
	
	
	clr	$420
	clr	$421
	clr	$422
	clr	$423
	lda	#VK_LEFT
	lbsr	Keyboard_IsKeyDown
	bne	noleft@
	inc	$420	
noleft@	
	lda	#VK_RIGHT
	lbsr	Keyboard_IsKeyDown
	bne	nor@
	inc	$421	
nor@	
	lda	#VK_UP
	lbsr	Keyboard_IsKeyDown
	bne	nou@
	inc	$422	
nou@	
	lda	#VK_DOWN
	lbsr	Keyboard_IsKeyDown
	bne	nodn@
	inc	$423	
nodn@	

	* delay, then jump back
	ldd	#3000
!	subd	#1
	bne	<	
	lbra	kloop


	rts	
	
	
* end - Keyboard.asm