VDGSCR	equ $0400	; 32-column VDG screen @1024-1535

* Color BASIC data
BLKTYP	equ $007C	; used by BLKOUT
BLKLEN	equ $007D	; used by BLKOUT
CBUFAD	equ $007E	; used by BLKOUT
DEVNUM	equ $006F	; used by CHROUT
*	0=screen -2=printer
POTVAL	equ $015A	; used by JOYIN
*	15A right joystick, X axis
*	15B right joystick, Y axis
*	15C left joystick, X axis
*	15D left joystick, Y axis

* Color BASIC subroutines
POLCAT	equ $A000	; Polls Keyboard for a Character
CHROUT	equ $A002	; Outputs a Character to Device
CSRDON	equ $A004	; Starts Cassette
BLKIN	equ $A006	; Reads a Block from Cassette
BLKOUT	equ $A008	; Writes a Block to Cassette
JOYIN	equ $A00A	; Samples Joystick Pots
WRTLDR	equ $A00C	; Turns Cassette On and Writes a Leader

INTCNV	equ $B3ED	; Convert USR Argument to Integer
GIVABF	equ $B4F4	; Return .d as the Result of USR

* Possible values for BLKTYP
NAMBLK	equ $00
DATBLK	equ $01
EOFBLK	equ $FF

* Values for the file type byte in a cassette namefile block
BASFIL	equ $00		; BASIC program
DATFIL	equ $01		; Data
MACFIL	equ $02		; Machine language

* Values for the ASCII flag byte in a cassette namefile block
BINFLG	equ $00		; Binary
ASCFLG	equ $FF		; ASCII

* Values for the gap flag byte in a cassette namefile block
* The tech manual claims that the value for "continuous"
* is 01, but examination of saved binaries shows that it
* actually uses 00.
CONFLG	equ $00		; Continuous
GAPFLG	equ $FF		; Gaps

* CoCo hardware
PIA0AD	equ $FF00	; PIA 1 side A data register
PIA0AC	equ $FF01	; PIA 1 side A control register
PIA0BD	equ $FF02	; PIA 1 side A data register
PIA0BC	equ $FF03	; PIA 1 side A control register
PIA1AD	equ $FF20	; PIA 1 side A data register
PIA1AC	equ $FF21	; PIA 1 side A control register
PIA1BD	equ $FF22	; PIA 1 side A data register
PIA1BC	equ $FF23	; PIA 1 side A control register


* SAM addresses
SAMVDG	equ $FFC0	; video display mode
SAM_V0	equ $FFC0
SAM_V1	equ $FFC2
SAM_V2	equ $FFC4
SAMDIS	equ $FFC6	; display address offset
SAM_F0	equ $FFC6
SAM_F1	equ $FFC8
SAM_F2	equ $FFCA
SAM_F3	equ $FFCC
SAM_F4	equ $FFCE
SAM_F5	equ $FFD0
SAM_F6	equ $FFD2
SAMPAG	equ $FFD4	; page #1
SAM_P1	equ $FFD4
SAMRAT	equ $FFD6	; cpu rate
SAM_R0	equ $FFD6
SAM_R1	equ $FFD8
SAMSIZ	equ $FFDA	; memory size
SAM_M0	equ $FFDA
SAM_M1	equ $FFDC
SAMTYP	equ $FFDE	; memory map type
SAM_TY	equ $FFDE


* bitmask for PIA1AC
CASMOT	equ $08		; cassette motor control bit

* lower-right corner of screen in standard text mode
* (location for an activity indicator)
ACTIND	equ $05FF

* 6809 definitions
IRQ	equ $10
FIRQ	equ $40

	list
