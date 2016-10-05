* draw a line
* entry:	lin_xa, lin_ya = starting point
*	lin_xb, lin_yb = ending point

screen	equ	3584	graphics screen start
scr_size	equ	6144

line	pshs	x
	ldd	lin_ya
	std	lin_yy
	ldx	#lin_incx
	lda	lin_xb
	suba	lin_xa
	bhs	>
	nega
	ldx	#lin_decx
!	sta	lin_md+1
	clr	lin_md
	ldy	#lin_incy
	lda	lin_yb
	suba	lin_ya
	bhs	>
	nega
	ldy	#lin_decy
!	sta	lin_nd+1
	clr	lin_nd
	ldd	lin_md
	cmpd	lin_nd
	bhs	>
	exg	x,y	delta routines
	LDU	lin_nd
	STD	lin_nd
	STU	lin_md
!	LDD	lin_md
	incb		added by RT
	stb	lin_count
	lsrb
	lda	lin_md+1
	anda	#1
	BEQ	>
	CMPX	#lin_decx
	BLO	>
	decb
!	clra
@loop	PSHS	D,X,Y
	LDX	#screen
	LDB	lin_yy
	LDA	#32
	MUL
	LEAX	D,X
	LDB	lin_xx
	TFR	B,A
	LSRB
	LSRB
	LSRB
	ABX
	ANDA	#7
	LDY	#lin_bmap2
	ldb	,X
*	comb
	orb	a,y
	STB	,X
	PULS	D,X,Y
	jsr	,x	move delta x
	ADDD	lin_nd
	CMPD	lin_md
	BLO	>
	SUBD	lin_md
	jsr	,y	move delta y
!	dec	lin_count
	bne	@loop
	PULS	X,PC
lin_incx	INC	lin_xx
	RTS
lin_incy	INC	lin_yy
	RTS
lin_decx	DEC	lin_xx
	RTS
lin_decy	DEC	lin_yy
	RTS

lin_bmap2	fcb	%10000000
	fcb	%01000000
	fcb	%00100000
	fcb	%00010000
	fcb	%00001000
	fcb	%00000100
	fcb	%00000010
	fcb	%00000001
lin_ya	fcb	0
lin_xa	fcb	0
lin_xb	fcb	255
lin_yb	fcb	191

lin_count	rmb	1
lin_yy	rmb	1
lin_xx	rmb	1
lin_md	rmb	2
lin_nd	rmb	2

	end	line
