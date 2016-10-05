* plot a line (requires 256-wide 2-color screen)
* entry:	xa,ya=starting point
*		xb,yb=ending point
@count	rmb	1
@ya	rmb	1
@xa	rmb	1
@xb	rmb	1
@yb	rmb	1
@yy	rmb	1
@xx	rmb	1
@md	rmb	2
@nd	rmb	2
@bmap2	FDB	$7FBF
	FDB	$DFEF
	FDB	$F7FB
	FDB	$FDFE
LINE	PSHS	X
	LDD	@ya
	STD	@yy
	LDX	#@incx
	LDA	@xb
	SUBA	@xa
	BHS	LIN010
	NEGA
	LDX	#@decx
LIN010	STA	@md+1
	CLR	@md
	LDY	#@incy
	LDA	@yb
	SUBA	@ya
	BHS	LIN020
	NEGA
	LDY	#@decy
LIN020	STA	@nd+1
	CLR	@nd
	LDD	@md
	CMPD	@nd
	BHS	LIN025
	EXG	X,Y
	LDU	@nd
	STD	@nd
	STU	@md
LIN025	LDD	@md
	STB	@count
	LSRB
	LDA	@md+1
	ANDA	#1
	BEQ	LIN028
	CMPX	#@decx
	BLO	LIN028
	DECB
LIN028	CLRA
LIN030	PSHS	D,X,Y
	LDX	#SCREEN
	LDB	@yy
	LDA	#32
	MUL
	LEAX	D,X
	LDB	@xx
	TFR	B,A
	LSRB
	LSRB
	LSRB
	ABX
	ANDA	#7
	LDY	#bmap2
	LDB	,X
	ANDB	A,Y
	STB	,X
	PULS	D,X,Y
	JSR	,X
	ADDD	@nd
	CMPD	@md
	BLO	LIN050
	SUBD	@md
	JSR	,Y
LIN050	DEC	@count
	BNE	LIN030
	PULS	X,PC
@incx	INC	@xx
	RTS
@incy	INC	@yy
	RTS
@decx	DEC	@xx
	RTS
@decy	DEC	@yy
	RTS