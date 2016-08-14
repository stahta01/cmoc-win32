*/
*/	Fast 6-bit CoCo ADC successive approximation routine
*/	For audio or joystick sampling
*/	Copyright (c) 2008 by Roger Taylor
*/
DPSAM	LDB	#128
	STB	65312
	LDA	65280
	BMI	G@
	SUBB	#64
	STB	65312
	LDA	65280
	BMI	H@
B@	SUBB	#32
	STB	65312
	LDA	65280
	BMI	I@
C@	SUBB	#16
	STB	65312
	LDA	65280
	BMI	J@
D@	SUBB	#8
	STB	65312
	LDA	65280
	BMI	K@
E@	SUBB	#4
	STB	65312
	LDA	65280
	BMI	L@
F@	SUBB	#2
	BRA	Z@
G@	ADDB	#64
	STB	65312
	LDA	65280
	BPL	B@
H@	ADDB	#32
	STB	65312
	LDA	65280
	BPL	C@
I@	ADDB	#16
	STB	65312
	LDA	65280
	BPL	D@
J@	ADDB	#8
	STB	65312
	LDA	65280
	BPL	E@
K@	ADDB	#4
	STB	65312
	LDA	65280
	BPL	F@
L@	ADDB	#2
	BRA	Z@
Z@	EQU	*


*/
*/	Fast 6-bit CoCo ADC successive approximation routine
*/	For audio or joystick sampling
*/	Copyright (c) 2008 by Roger Taylor
*/
EPSAM	LDB	#128
	STB	65312
	LDA	65280
	BMI	G@
	SUBB	#64
	STB	65312
	LDA	65280
	BMI	H@
B@	SUBB	#32
	STB	65312
	LDA	65280
	BMI	I@
C@	SUBB	#16
	STB	65312
	LDA	65280
	BMI	J@
D@	SUBB	#8
	STB	65312
	LDA	65280
	BMI	K@
E@	SUBB	#4
	STB	65312
	LDA	65280
	BMI	L@
F@	SUBB	#2
	BRA	Z@
G@	ADDB	#64
	STB	65312
	LDA	65280
	BPL	B@
H@	ADDB	#32
	STB	65312
	LDA	65280
	BPL	C@
I@	ADDB	#16
	STB	65312
	LDA	65280
	BPL	D@
J@	ADDB	#8
	STB	65312
	LDA	65280
	BPL	E@
K@	ADDB	#4
	STB	65312
	LDA	65280
	BPL	F@
L@	ADDB	#2
	BRA	Z@
Z@	EQU	*

