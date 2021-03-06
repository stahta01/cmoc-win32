* CoCo 3 definitions

* GIME Register Names
GR_INIT0		equ	$FF90	65424
GR_INIT1		equ	$FF91	65425
GR_IRQENR		equ	$FF92	65426
GR_FIRQENR	equ	$FF93	65427
GR_TIMERMSB	equ	$FF94
GR_TIMERLSB	equ	$FF95
GR_VMODE		equ	$FF98	65432
GR_VRES		equ	$FF99	65433
GR_BRDR		equ	$FF9A	65434
GR_DISTO_VBANK	equ	$FF9B	65435
GR_VSC		equ	$FF9C	65436
GR_VOFFSET	equ	$FF9D
GR_HOFFSET	equ	$FF9F
GR_TASK1_BANK0	equ	$FFA0
GR_TASK1_BANK1	equ	$FFA1
GR_TASK1_BANK2	equ	$FFA2
GR_TASK1_BANK3	equ	$FFA3
GR_TASK1_BANK4	equ	$FFA4
GR_TASK1_BANK5	equ	$FFA5
GR_TASK1_BANK6	equ	$FFA6
GR_TASK1_BANK7	equ	$FFA7
GR_TASK2_BANK0	equ	$FFA8
GR_TASK2_BANK1	equ	$FFA9
GR_TASK2_BANK2	equ	$FFAA
GR_TASK2_BANK3	equ	$FFAB
GR_TASK2_BANK4	equ	$FFAC
GR_TASK2_BANK5	equ	$FFAD
GR_TASK2_BANK6	equ	$FFAE
GR_TASK2_BANK7	equ	$FFAF
GR_TASK1_0000	equ	$FFA0
GR_TASK1_2000	equ	$FFA1
GR_TASK1_4000	equ	$FFA2
GR_TASK1_6000	equ	$FFA3
GR_TASK1_8000	equ	$FFA4
GR_TASK1_A000	equ	$FFA5
GR_TASK1_C000	equ	$FFA6
GR_TASK1_E000	equ	$FFA7
GR_TASK2_0000	equ	$FFA8
GR_TASK2_2000	equ	$FFA9
GR_TASK2_4000	equ	$FFAA
GR_TASK2_6000	equ	$FFAB
GR_TASK2_8000	equ	$FFAC
GR_TASK2_A000	equ	$FFAD
GR_TASK2_C000	equ	$FFAE
GR_TASK2_E000	equ	$FFAF
GR_PALETTE_BORDER	equ	GR_BRDR
GR_PALETTE_COLOR0	equ	$FFB0
GR_PALETTE_COLOR1	equ	$FFB1
GR_PALETTE_COLOR2	equ	$FFB2
GR_PALETTE_COLOR3	equ	$FFB3
GR_PALETTE_COLOR4	equ	$FFB4
GR_PALETTE_COLOR5	equ	$FFB5
GR_PALETTE_COLOR6	equ	$FFB6
GR_PALETTE_COLOR7	equ	$FFB7
GR_PALETTE_COLOR8	equ	$FFB8
GR_PALETTE_COLOR9	equ	$FFB9
GR_PALETTE_COLOR10	equ	$FFBA
GR_PALETTE_COLOR11	equ	$FFBB
GR_PALETTE_COLOR12	equ	$FFBC
GR_PALETTE_COLOR13	equ	$FFBD
GR_PALETTE_COLOR14	equ	$FFBE
GR_PALETTE_COLOR15	equ	$FFBF
GR_NORMALCLOCK	equ	$FFD8	write for ~1mhz CPU
GR_FASTCLOCK	equ	$FFD9	write for ~2mhz CPU
GR_ENABLEROM	equ	$FFDE	write to switch ROMs into memory map
GR_DISABLEROM	equ	$FFDF	write to switch ROMs out of memory map (all-RAM)
GR_ALLRAM		equ	$FFDF	write to switch ROMs out of memory map (all-RAM)

INT_TMR		equ	%00100000
INT_HBORD		equ	%00010000
INT_VBORD		equ	%00001000
INT_EI2		equ	%00000100
INT_EI1		equ	%00000010
INT_EI0		equ	%00000001

GR_VIDEOMODE	equ	GR_VMODE
INT_TIMER		equ	INT_TMR
INT_HORIZONTALBORDERequ	INT_HBORD
INT_HSYNC		equ	INT_HBORD
INT_VERTICALBORDER	equ	INT_VBORD
INT_VSYNC		equ	INT_VBORD
INT_SERIALDATA	equ	INT_EI2
INT_SERIAL	equ	INT_EI2
INT_KEYBOARD	equ	INT_EI1
INT_CARTRIDGE	equ	INT_EI0
INT_CART		equ	INT_EI0
INT_ROMPAK	equ	INT_EI0

GR_TIMER		equ	GR_TIMERMSB
GR_BORDER		equ	GR_BRDR
GR_VERTICALSCROLL	equ	GR_VSC
GR_PAGE		equ	GR_VOFFSET
GR_PALETTE	equ	GR_PALETTE_COLOR0
GR_1MHZCLOCK	equ	GR_NORMALCLOCK
GR_2MHZCLOCK	equ	GR_FASTCLOCK
GR_ALLRAMMODE	equ	GR_DISABLEROM
GR_ROMMODE	equ	GR_ENABLEROM

GI_COCO		equ	%10000000
GI_COCO1		equ	%10000000
GI_COCO2		equ	%10000000
GI_COCO3		equ	%00000000
GI_MMUENABLED	equ	%01000000
GI_IRQENABLED	equ	%00100000
GI_FIRQENABLED	equ	%00010000
GI_VECTORPAGE	equ	%00001000
GI_STANDARDSCS	equ	%00000100
GI_16KROMMAP	equ	%00000000
GI_32KROMMAP	equ	%00000010
GI_INTERNALROM	equ	%00000000
GI_EXTERNALROM	equ	%00000001

* VMODE, $FF98, 65432
VM_GRAPHICS	equ	%10000000
VM_TEXT		equ	%00000000
VM_50HZ		equ	%00001000
VM_60HZ		equ	%00000000
VM_MONOCHROME	equ	%00010000
VM_COLORBURST	equ	%00000000
VM_1LINEPERROW	equ	%00000000
VM_2LINESPERROW	equ	%00000010
VM_8LINESPERROW	equ	%00000011
VM_9LINESPERROW	equ	%00000100
VM_10LINESPERROW	equ	%00000101
VM_11LINESPERROW	equ	%00000110
VM_1LINEPERSCREEN	equ	%00000111

* VRES, $FF98, 65433
VR_192SCANLINES	equ	%00000000
VR_200SCANLINES	equ	%00100000
VR_0SCANLINES	equ	%01000000
VR_225SCANLINES	equ	%01100000
VR_16BYTESPERROW	equ	%00000000
VR_20BYTESPERROW	equ	%00000100
VR_32BYTESPERROW	equ	%00001000
VR_40BYTESPERROW	equ	%00001100
VR_64BYTESPERROW	equ	%00010000
VR_80BYTESPERROW	equ	%00010100
VR_128BYTESPERROW	equ	%00011000
VR_160BYTESPERROW	equ	%00011100
VR_2COLORS	equ	%00000000
VR_4COLORS	equ	%00000001
VR_16COLORS	equ	%00000010
VR_256COLORS	equ	%00000011
VR_8PIXELSPERBYTE	equ	%00000000
VR_4PIXELSPERBYTE	equ	%00000001
VR_2PIXELSPERBYTE	equ	%00000010
VR_1PIXELPERBYTE	equ	%00000011

* combined graphics modes (shortcuts)
* ofcourse, there's more possibilities
GM_640X192Y4C	equ	VR_192SCANLINES!VR_160BYTESPERROW!VR_4PIXELSPERBYTE
GM_640X192Y2C	equ	VR_192SCANLINES!VR_80BYTESPERROW!VR_8PIXELSPERBYTE
GM_640X200Y4C	equ	VR_200SCANLINES!VR_160BYTESPERROW!VR_4PIXELSPERBYTE
GM_640X200Y2C	equ	VR_200SCANLINES!VR_80BYTESPERROW!VR_8PIXELSPERBYTE
GM_640X225Y4C	equ	VR_225SCANLINES!VR_160BYTESPERROW!VR_4PIXELSPERBYTE
GM_640X225Y2C	equ	VR_225SCANLINES!VR_80BYTESPERROW!VR_8PIXELSPERBYTE
GM_512X192Y4C	equ	VR_192SCANLINES!VR_128BYTESPERROW!VR_4PIXELSPERBYTE
GM_512X192Y2C	equ	VR_192SCANLINES!VR_128BYTESPERROW!VR_8PIXELSPERBYTE
GM_512X200Y4C	equ	VR_200SCANLINES!VR_128BYTESPERROW!VR_4PIXELSPERBYTE
GM_512X200Y2C	equ	VR_200SCANLINES!VR_128BYTESPERROW!VR_8PIXELSPERBYTE
GM_512X225Y4C	equ	VR_225SCANLINES!VR_128BYTESPERROW!VR_4PIXELSPERBYTE
GM_512X225Y2C	equ	VR_225SCANLINES!VR_128BYTESPERROW!VR_8PIXELSPERBYTE
GM_320X192Y16C	equ	VR_192SCANLINES!VR_160BYTESPERROW!VR_2PIXELSPERBYTE
GM_320X192Y4C	equ	VR_192SCANLINES!VR_80BYTESPERROW!VR_4PIXELSPERBYTE
GM_320X192Y2C	equ	VR_192SCANLINES!VR_40BYTESPERROW!VR_8PIXELSPERBYTE
GM_320X200Y16C	equ	VR_200SCANLINES!VR_160BYTESPERROW!VR_2PIXELSPERBYTE
GM_320X200Y4C	equ	VR_200SCANLINES!VR_80BYTESPERROW!VR_4PIXELSPERBYTE
GM_320X200Y2C	equ	VR_200SCANLINES!VR_40BYTESPERROW!VR_8PIXELSPERBYTE
GM_320X225Y16C	equ	VR_225SCANLINES!VR_160BYTESPERROW!VR_2PIXELSPERBYTE
GM_320X225Y4C	equ	VR_225SCANLINES!VR_80BYTESPERROW!VR_4PIXELSPERBYTE
GM_320X225Y2C	equ	VR_225SCANLINES!VR_40BYTESPERROW!VR_8PIXELSPERBYTE
GM_256X192Y16C	equ	VR_192SCANLINES!VR_128BYTESPERROW!VR_2PIXELSPERBYTE
GM_256X192Y4C	equ	VR_192SCANLINES!VR_64BYTESPERROW!VR_4PIXELSPERBYTE
GM_256X192Y2C	equ	VR_192SCANLINES!VR_32BYTESPERROW!VR_8PIXELSPERBYTE
GM_256X200Y16C	equ	VR_200SCANLINES!VR_128BYTESPERROW!VR_2PIXELSPERBYTE
GM_256X200Y4C	equ	VR_200SCANLINES!VR_64BYTESPERROW!VR_4PIXELSPERBYTE
GM_256X200Y2C	equ	VR_200SCANLINES!VR_32BYTESPERROW!VR_8PIXELSPERBYTE
GM_256X225Y16C	equ	VR_225SCANLINES!VR_128BYTESPERROW!VR_2PIXELSPERBYTE
GM_256X225Y4C	equ	VR_225SCANLINES!VR_64BYTESPERROW!VR_4PIXELSPERBYTE
GM_256X225Y2C	equ	VR_225SCANLINES!VR_32BYTESPERROW!VR_8PIXELSPERBYTE
GM_160X192Y16C	equ	VR_192SCANLINES!VR_80BYTESPERROW!VR_2PIXELSPERBYTE
GM_160X192Y4C	equ	VR_192SCANLINES!VR_40BYTESPERROW!VR_4PIXELSPERBYTE
GM_160X192Y2C	equ	VR_192SCANLINES!VR_20BYTESPERROW!VR_8PIXELSPERBYTE
GM_160X200Y16C	equ	VR_200SCANLINES!VR_80BYTESPERROW!VR_2PIXELSPERBYTE
GM_160X200Y4C	equ	VR_200SCANLINES!VR_40BYTESPERROW!VR_4PIXELSPERBYTE
GM_160X200Y2C	equ	VR_200SCANLINES!VR_20BYTESPERROW!VR_8PIXELSPERBYTE
GM_160X225Y16C	equ	VR_225SCANLINES!VR_80BYTESPERROW!VR_2PIXELSPERBYTE
GM_160X225Y4C	equ	VR_225SCANLINES!VR_40BYTESPERROW!VR_4PIXELSPERBYTE
GM_160X225Y2C	equ	VR_225SCANLINES!VR_20BYTESPERROW!VR_8PIXELSPERBYTE
GM_128X192Y16C	equ	VR_192SCANLINES!VR_64BYTESPERROW!VR_2PIXELSPERBYTE
GM_128X192Y4C	equ	VR_192SCANLINES!VR_32BYTESPERROW!VR_4PIXELSPERBYTE
GM_128X192Y2C	equ	VR_192SCANLINES!VR_16BYTESPERROW!VR_8PIXELSPERBYTE
GM_128X200Y16C	equ	VR_200SCANLINES!VR_64BYTESPERROW!VR_2PIXELSPERBYTE
GM_128X200Y4C	equ	VR_200SCANLINES!VR_32BYTESPERROW!VR_4PIXELSPERBYTE
GM_128X200Y2C	equ	VR_200SCANLINES!VR_16BYTESPERROW!VR_8PIXELSPERBYTE
GM_128X225Y16C	equ	VR_225SCANLINES!VR_64BYTESPERROW!VR_2PIXELSPERBYTE
GM_128X225Y4C	equ	VR_225SCANLINES!VR_32BYTESPERROW!VR_4PIXELSPERBYTE
GM_128X225Y2C	equ	VR_225SCANLINES!VR_16BYTESPERROW!VR_8PIXELSPERBYTE
