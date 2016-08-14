* SIGNED DIVIDE
* 16-bit by 8-bit
* from the TRS-80 Color Computer Assembly Language Programming book

sdiv lda divdnd
 eora divsor
 pshs cc
 ldd divdnd
 bpl sdi010
 ldd #0
 subd divdnd
sdi010 tfr d,x
 lda divsor
 bpl sdi020
 nega
sdi020 bsr div168
 puls cc
 bpl div16x8_ex
 pshs a,x
 ldd #0
 subd +1,s
 tfr d,x
 puls a,y
 nega
div16x8_ex rts

divdnd fdb 0
divsor fcb 0

********************************************************
* DIVIDE 16 BY 8 SUBROUTINE, UNSIGNED                  *
*    ENTRY: (X)=16-BIT DIVIDEND                        *
********************************************************
div168 pshs x,a
 clra
 ldb +1,s
 bsr divide
 stb +1,s
 ldb +2,s
 bsr divide
 stb +2,s
 puls b,x
endex rts

divide ldx #8
div010 lslb
 rola
 orb #1
 bcc div015
 suba +2,s
 bra div020
div015 suba +2,s
 bhs div020
 andb #$fe
 adda +2,s
div020 leax -1,x
 bne div010
 rts
