* enter with reg.a=Video Resolution
* for shortcut, use a constant named (GM_??)

goVideo	ldb	#VM_GRAPHICS
	stb	GR_VIDEOMODE
	clr	GR_BORDER
	clr	GR_DISTO_VBANK
	clr	GR_VSC
	clr	GR_HOFFSET
	jsr	vsync
	sta	GR_VRES
	rts
goPage	bsr	vsync
	std	GR_PAGE		point to graphics page
vsync	tst	65282		reset vertical sync flag
@v	tst	65283		check for sync signal
	bpl	@v		wait until bit 7 is high
	rts
