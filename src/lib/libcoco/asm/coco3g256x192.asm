* 256x192 graphics mode for CoCo 3
PMODE	BSR	VSYNC
	LDA	#76
	STA	65424
	LDA	#128
	STA	65432
	LDA	#8
	STA	65433
	CLR	65434
	CLR	65435
	CLR	65436
	LDD	#$E1C0
	STD	65437
	CLR	65439
	LDD	#$0037		black,yellow
	STD	65456
	RTS
