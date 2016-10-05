* clear the CoCo palette, border, whole screen

PALCLR	pshs	d,x
	jsr	VSYNC
	ldx	#GR_PALETTE
	lda	#0		color to clear with
	ldb	#16		total colors
	sta	GR_PALETTE_BORDER
@c	sta	,x+
	decb
	bne	@c
	jsr	VSYNC
	puls	d,x,pc
	