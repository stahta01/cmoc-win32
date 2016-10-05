
// By Pierre Sarrazin <http://sarrazip.com/>.
// This file is in the public domain.
//
// Converted to C for WinCMOC by Derek Evans 2016

// Unsigned division by seven
// Input: an unsigned byte (0..255) in A
// Output: Computes A/7
//         quotient (0..36) in B
//         remainder (0..6) in A
// Using (8a+b)/7 = a + (a+b)/7
// where a = higher five bits and b = lower three bits
// Source: DIVIDE7 on http://mirrors.apple2.org.za/ground.icaen.uiowa.edu/MiscInfo/Programming/div7

asm void _static_(void)
{
    asm {
        DIV8BY7: export

        DIV8BY7:
        tfr     A,B
        anda    #7
        pshs    A                               // low bits (b)
        tfr     B,A
        lsra
        lsra
        lsra
        tfr     A,B                             // high bits, divided by 8 (a)
        andcc   #$FE                            // clear carry
        adca    ,S+                             //a + b. here we know carry is low.

        DIV8BY7_010:
        incb                                    // the loop is executed between 1 and 6 times
        sbca    #7                              // since A is at most 38
        bcc     DIV8BY7_010
        adda    #7
        decb
        //PAUL    EQU 12 // Unsure why this was here
    }
}

