* vertical SYNC function

vsync	tst	65282		reset vertical sync flag
@v	tst	65283		check for sync signal
	bpl	@v		wait until bit 7 is high
	rts
	