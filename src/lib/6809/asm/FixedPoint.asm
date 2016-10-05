************************************************
* Fixed point math code Color Computer 3 
* copyright Chris Lomont 2006 www.lomont.org
************************************************

************************************************
* Fixed point rountines - 
* values stored as 2's complement, 8.24 mode, 4 bytes
* todo - make arbitrary length - would be sweet :)
************************************************

************************************************
* FPAdd - Fixed point Add 
* REGX - point to operand1
* REGY - point to operand2
* REGU - point to answer
* all registers are allowed to point to same spots
* Registers changed: none
************************************************
FPAdd
	pshs	a	
	lda	3,x		Least sig byte
	adda	3,y
	sta	3,u
	lda	2,x
	adca	2,y
	sta	2,u
	lda	1,x
	adca	1,y
	sta	1,u
	lda	,x		most sig byte
	adca	,y
	sta	,u
	puls	a
	rts
	
************************************************
* FPClear - zero out fp value 
* REGX - point to operand
* Registers changed: none
************************************************
FPClear
	clr	,x+
	clr	,x+
	clr	,x+
	clr	,x+
	leax	-4,x
	rts

************************************************
* FPCopy - copy one value to another 
* REGX - point to source
* REGY - point to dest
* Registers changed: none
************************************************
FPCopy
	pshs	a
	lda	,x+
	sta	,y+
	lda	,x+
	sta	,y+
	lda	,x+
	sta	,y+
	lda	,x
	sta	,y
	leax	-3,x
	leay	-3,y
	puls	a
	rts


************************************************
* FPNeg - Fixed point negate 
* REGX - point to operand
* Registers changed: none
************************************************
FPNeg
	pshs	y,u
	com	3,x		2's complement, complement and add one
	com	2,x
	com	1,x
	com	,x
	ldy	#FPEps
	tfr	x,u		dest same
	bsr	FPAdd	
	puls	y,u
	rts
FPEps	fcb	0,0,0,1		8.24 fixed point smallest positive value

************************************************
* FPMulu - Fixed point multiply of positive numbers 
* REGX - point to operand1
* REGY - point to operand2
* REGU - point to answer
* all registers are allowed to point to same spots
* Registers changed: none
************************************************
FPMulu
	pshs	u,y,x,b,a	order PC,U,Y,X,DP,B,A,CC high(?) byte first, S pre-decremented
	ldu	#FPTempU	temp storage
	ldd	#0		*clrd todo - this is a 6309 only opcode - how to make ccasm warn me?
	std	,u++		zero temp storage
	std	,u++		
	std	,u++
	std	,u
	ldd	#$0303		counters for x bytes and y bytes	
	pshs	d		x pos byte, y pos byte counter, each goes 3 down to 0

loop	ldb	,s		x counter
	lda	1,s		y counter
	ldx	4,s		x base
	ldy	6,s		y base
	ldu	#FPTempU
	abx			x byte to mult
	leay	a,y		y byte to mult
	adda	,s		total offset space
	leau	a,u		where to write answer
		
	lda	,x		read one byte to mult		
	ldb	,y		read other byte to mult
	mul			multiply the bytes
	addd	,u		store in location
	std	,u
	bcc	next		no carry
carry	lda	,-u		prepare to add with carry to prev byte	
	cmpu	#FPTempU	add carries to top of temp
	blt	next		no more bytes left
	inca			add in carry
	sta	,u
	bcs	carry		more carry to do

next	dec	1,s		decrement two counters, fall through when done		
	bge	loop
	ldb	#3	
	stb	1,s
	dec	,s
	bge	loop
	
	puls	d		clean stack
	
	ldx	#FPTempU+1	answer is shifted off one
	ldu	6,s		original u value for answer
	
	ldd	,x++		copy 4 bytes
	std	,u++
	ldd	,x++		
	std	,u++
	
	puls	u,y,x,b,a
	rts
FPTempU	fcb	1,2,3,4,5,6,7,8	eight bytes temp space - todo - 6 enough? start placing all temp on stack
************************************************
* FPMul - Fixed point multiply 
* REGX - point to operand1
* REGY - point to operand2
* REGU - point to answer
* Registers changed: none
************************************************
FPMul
	pshs	y,x,b,a
	lda	,x		get signs
	ldb	,y		get signs

* if x < 0 or x==y or x==u then copy x to new location	
	bita	#$80		check sign on x
	bne	movex
	cmpx	4,s		see if x and y point to same space
	beq	movex
	cmpx	6,s		see if x and u point to same space
	bne	xdone
	
movex	ldy	#FPTemp1	move x to another spot
	lbsr	FPCopy		get copy
	ldx	#FPTemp1	point here
	bita	#$80
	beq	xdone
	lbsr	FPNeg		negate this copy

xdone	ldy	4,s		get y
	bitb	#$80		check sign on y
	bne	movey
	cmpy	2,s		see if x and y point to same space
	beq	movey
	cmpy	6,s		see if x and u point to same space
	bne	ydone
	
movey	pshs	x		save this for copy
	tfr	y,x		source
	ldy	#FPTemp2	dest
	lbsr	FPCopy		copy
	puls	x		restore
	bitb	#$80		check sign on y
	beq	ydone		jump if nonnegative
	exg	x,y		save regs
	lbsr	FPNeg		negate y value
	exg	x,y		restore regs
	
ydone	lbsr	FPMulu		both positive now, so mult them

	pshs	b
	eora	,s		compute final sign
	puls	b
	bita	#$80
	beq	anspos
	
	tfr	u,x
	lbsr	FPNeg		negate answer
		
anspos	puls	y,x,b,a
	rts
FPTemp1 fcb	1,2,3,4,5,6,7,8	eight bytes temp space
FPTemp2 fcb	1,2,3,4,5,6,7,8	eight bytes temp space

************************************************
* Some useful fixed point values 
************************************************
FPNegFour	fcb	$FC,0,0,0	-4 in FP
FPHalf		fcb	0,128,0,0
FPOne		fcb	1,0,0,0
FPTwo		fcb	$2,0,0,0	 2 in FP



	if 0

AFPTemp1	fcb	0,0,0,0
AFPTemp2	fcb	0,0,0,0
AFPTemp3	fcb	0,0,0,0

Root2		fcb 	254,244,170,122		value is negative 16th root of 2

AFPTempA	fcb	12,34,56,78
AFPTempB	fcb	3,45,89,120  	
AFPTempC	fcb	253,45,89,120  	
AFPTempD	rmb 	4

TestFPCode
	ldx	#Root2
	tfr	x,y
	ldu	#AFPTempD
	lbsr	FPMul
	tfr	u,y
	ldb	#14		do 14 more times
!	lbsr	FPMul
	decb
	bne	<		should have 2,0,0,0 in AFPTempD when done
	bra	TestFPCode
	



	* test the FP code
!	ldx	#AFPTempA
	ldy	#AFPTempB
	ldu	#AFPTempD
	lbsr	FPMulu		should be 38, 140, 234, 101 = $26,8C,EA,65
	ldy	#AFPTempC
	ldu	#AFPTempD
	lbsr	FPMul		should be 221, 191, 152, 146 = DD,BF,98,92
	bra	<		
	

	ldx	#FPOne
	ldy	#AFPTemp1
	lbsr	FPCopy		1 in temp1
	ldx	#AFPTemp1
	lbsr	FPNeg		-1 in temp1
	ldy	#FPTwo
	ldu	#AFPTemp2
	lbsr	FPMul		-2 in temp2
	ldy	#AFPTemp2
	ldu	#AFPTemp3
	lbsr	FPMul		2 in temp3
*	bra	TestFPCode
	
		
	lbsr	FPMul		0.5 in temp1
	
	
	
	ldx	#FPOne
	ldy	#FPHalf	
	ldu	#AFPTemp1
	lbsr	FPMul		0.5 in temp1
	
	ldx	#AFPTemp1
	ldy	#AFPTemp2	
	lbsr	FPCopy		0.5 in temp2
	
	ldx	#AFPTemp1
	lbsr	FPNeg		-0.5 in temp1

	ldx	#AFPTemp1
	ldy	#AFPTemp2	
	ldu	#AFPTemp3
	lbsr	FPMul		-0.25 in temp3

	ldx	#AFPTemp3
	ldy	#AFPTemp2	
	ldu	#AFPTemp1
	lbsr	FPAdd		0.25 in temp1


	ldx	#AFPTemp1
	ldy	#AFPTemp1	
	ldu	#AFPTemp1
	lbsr	FPAdd		0.5 in temp1

	ldx	#FPTwo	
	ldy	#AFPTemp3
	ldu	#AFPTemp2
	lbsr	FPMul		-0.5 in temp2
	
	ldx	#AFPTemp1	
	ldy	#AFPTemp2
	ldu	#AFPTemp3
	lbsr	FPAdd		0

	rts
	endif


* end - FixedPoint.asm