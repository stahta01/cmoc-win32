
// This file was created by WinCMOC (CMOC 6809 C Compiler for Windows)
//
// WinCMOC:  https://sourceforge.net/projects/cmoc-win32/
// CMOC:     http://perso.b2b2c.ca/~sarrazip/dev/cmoc.html

// Translated from "dosdefs.asm"
//
// This file is in the public domain

#ifndef _SUPERDOS_DOSDEFS_H
#define _SUPERDOS_DOSDEFS_H

// Decimal 0 (0x0) [Value] - Restore to track 0
#ifndef _WDCMDRESTORE
#define _WDCMDRESTORE 0
#endif

// Decimal 16 (0x10) [Value] - Seek to track command
#ifndef _WDCMDSEEK
#define _WDCMDSEEK 16
#endif

// Decimal 128 (0x80) [Value] - Read sector command
#ifndef _WDCMDREADSEC
#define _WDCMDREADSEC 128
#endif

// Decimal 160 (0xA0) [Value] - Write sector command
#ifndef _WDCMDWRITESEC
#define _WDCMDWRITESEC 160
#endif

// Decimal 192 (0xC0) [Value] - Read address mark
#ifndef _WDCMDREADADDR
#define _WDCMDREADADDR 192
#endif

// Decimal 208 (0xD0) [Value] - Force inturrupt
#ifndef _WDCMDFORCEINT
#define _WDCMDFORCEINT 208
#endif

// Decimal 244 (0xF4) [Value] - Write (format) track
#ifndef _WDCMDWRITETRACK
#define _WDCMDWRITETRACK 244
#endif

// Decimal 0 (0x0) [Value] - Restore to track 0
#ifndef _WDCMDRESTORE
#define _WDCMDRESTORE 0
#endif

// Decimal 0 (0x0) [Value] - Seek to track command
#ifndef _WDCMDSEEK
#define _WDCMDSEEK 0
#endif

// Decimal 0 (0x0) [Value] - Read sector command
#ifndef _WDCMDREADSEC
#define _WDCMDREADSEC 0
#endif

// Decimal 0 (0x0) [Value] - Write sector command
#ifndef _WDCMDWRITESEC
#define _WDCMDWRITESEC 0
#endif

// Decimal 0 (0x0) [Value] - Read address mark
#ifndef _WDCMDREADADDR
#define _WDCMDREADADDR 0
#endif

// Decimal 0 (0x0) [Value] - Force inturrupt
#ifndef _WDCMDFORCEINT
#define _WDCMDFORCEINT 0
#endif

// Decimal 0 (0x0) [Value] - Write (format) track
#ifndef _WDCMDWRITETRACK
#define _WDCMDWRITETRACK 0
#endif

// Decimal 0 (0x0) [Value] - 6ms step rate
#ifndef _STEPRATE6MS
#define _STEPRATE6MS 0
#endif

// Decimal 1 (0x1) [Value] - 12ms step rate
#ifndef _STEPRATE12MS
#define _STEPRATE12MS 1
#endif

// Decimal 2 (0x2) [Value] - 20ms step rate
#ifndef _STEPRATE20MS
#define _STEPRATE20MS 2
#endif

// Decimal 3 (0x3) [Value] - 30ms step rate
#ifndef _STEPRATE30MS
#define _STEPRATE30MS 3
#endif

// Decimal 2 (0x2) [Value] - Default
#ifndef _SEEPRATEDEFAULT
#define _SEEPRATEDEFAULT 2
#endif

// Decimal 16 (0x10) [Value] - Track to enable precomp if greater
#ifndef _TRACKPRECOMP
#define _TRACKPRECOMP 16
#endif

// Decimal 18 (0x12) [Value] - Sectors per track
#ifndef _SECTORSPERTRACK
#define _SECTORSPERTRACK 18
#endif

// Decimal 4 (0x4) [Value] - Maximum valid drive no
#ifndef _MAXDRIVENO
#define _MAXDRIVENO 4
#endif

// Decimal 14 (0xE) [Value] - Max filename length, DriveNo:Filename.EXT
#ifndef _MAXFILENAMELEN
#define _MAXFILENAMELEN 14
#endif

// Decimal 3 (0x3) [Value] - Boot sector is track 0 sector 3
#ifndef _BOOTFIRSTSECTOR
#define _BOOTFIRSTSECTOR 3
#endif

// Decimal 18 (0x12) [Value] - Last sector of boot
#ifndef _BOOTLASTSECTOR
#define _BOOTLASTSECTOR 18
#endif

// Decimal 20307 (0x4F53) [Value] - Boot signature 'OS'
#ifndef _BOOTSIGNATURE
#define _BOOTSIGNATURE 20307
#endif

// Decimal 9728 (0x2600) [Value] - Boot area load address.
#ifndef _BOOTLOADADDR
#define _BOOTLOADADDR 9728
#endif

// Decimal 9730 (0x2602) [Value] - Boot entry address
#ifndef _BOOTENTRYADDR
#define _BOOTENTRYADDR 9730
#endif

// Decimal 20 (0x14) [Value] - Primary dir track is track 20
#ifndef _DIRPRIMARY
#define _DIRPRIMARY 20
#endif

// Decimal 16 (0x10) [Value] - Backup on track 16
#ifndef _DIRBACKUP
#define _DIRBACKUP 16
#endif

// Decimal 255 (0xFF) [Value] - Auto re-number flag, if $613=this then auto enter basic lines
#ifndef _AUTOFLAG
#define _AUTOFLAG 255
#endif

// Decimal 234 (0xEA) [Value] - Location of hardware IO byte
#ifndef _DOSHWBYTE
#define _DOSHWBYTE 234
#endif

// Decimal 235 (0xEB) [Value] - Last active drive number
#ifndef _LASTACTIVEDRV
#define _LASTACTIVEDRV 235
#endif

// Decimal 236 (0xEC) [Value] - Disk track no
#ifndef _DSKTRACKNO
#define _DSKTRACKNO 236
#endif

// Decimal 237 (0xED) [Value] - Disk sectror no
#ifndef _DSKSECTORNO
#define _DSKSECTORNO 237
#endif

// Decimal 238 (0xEE) [Value] - Disk buffer pointer
#ifndef _DISKBUFFPTR
#define _DISKBUFFPTR 238
#endif

// Decimal 235 (0xEB) [Value] - Active/last used drive number (1-4)
#ifndef _DOSLASTDRIVE
#define _DOSLASTDRIVE 235
#endif

// Decimal 240 (0xF0) [Value] - Disk error status byte
#ifndef _DOSDISKERROR
#define _DOSDISKERROR 240
#endif

// Decimal 241 (0xF1) [Value] - Current file control block (0..9) $FF=no files open
#ifndef _DOSCURRCTRLBLK
#define _DOSCURRCTRLBLK 241
#endif

// Decimal 242 (0xF2) [Value] - Number of bytes in DTA (also used for tracks in DSKINIT).
#ifndef _DOSBYTESINDTA
#define _DOSBYTESINDTA 242
#endif

// Decimal 243 (0xF3) [Value] - Number of bytes to transfer to/from buffer
#ifndef _DOSNOBYTESMOVE
#define _DOSNOBYTESMOVE 243
#endif

// Decimal 244 (0xF4) [Value] - Record length flag, 00 don'r care $FF=do care
#ifndef _DOSRECLENFLAG
#define _DOSRECLENFLAG 244
#endif

// Decimal 245 (0xF5) [Value] - Dos IRQ timeout flag, 00=check for timeout
#ifndef _DOSIRQTIMEFLAG
#define _DOSIRQTIMEFLAG 245
#endif

// Decimal 246 (0xF6) [Value] - I/O currently in progress flag 0x00 check for time out, Non-0x00 skip timeout check
#ifndef _DOSIOINPROGRESS
#define _DOSIOINPROGRESS 246
#endif

// Decimal 248 (0xF8) [Value] - Sector currently seeking {SuperDos Rom}
#ifndef _DOSSECTORSEEK
#define _DOSSECTORSEEK 248
#endif

// Decimal 1536 (0x600) [Value] - Start of RAM used by DOS
#ifndef _DOSAREASTART
#define _DOSAREASTART 1536
#endif

// Decimal 1539 (0x603) [Value] - Error code from DOS
#ifndef _DOSERRORCODE
#define _DOSERRORCODE 1539
#endif

// Decimal 1541 (0x605) [Value] - Timeout count, timeout occurs when this location is decremented from 0x01 to 0x00
#ifndef _DOSTIMEOUT
#define _DOSTIMEOUT 1541
#endif

// Decimal 1542 (0x606) [Value] - Hardware command byte mask for FF40
#ifndef _DOSHWMASKFF40
#define _DOSHWMASKFF40 1542
#endif

// Decimal 1543 (0x607) [Value] - hardware control mask for $ff48
#ifndef _DOSHWMASKFF48
#define _DOSHWMASKFF48 1543
#endif

// Decimal 1544 (0x608) [Value] - Verify flag, 00=no verify $FF=verify
#ifndef _DOSVERIFYFLAG
#define _DOSVERIFYFLAG 1544
#endif

// Decimal 1545 (0x609) [Value] - Error mask, ANDed with error code from WD
#ifndef _DOSERRORMASK
#define _DOSERRORMASK 1545
#endif

// Decimal 1546 (0x60A) [Value] - Default drive number
#ifndef _DOSDEFDRIVENO
#define _DOSDEFDRIVENO 1546
#endif

// Decimal 1549 (0x60D) [Value] - AUTO current line no
#ifndef _DOSAUTOCURRENT
#define _DOSAUTOCURRENT 1549
#endif

// Decimal 1551 (0x60F) [Value] - AUTO line increment
#ifndef _DOSAUTOINC
#define _DOSAUTOINC 1551
#endif

// Decimal 1553 (0x611) [Value] - Run/load flag $00=LOAD
#ifndef _DOSRUNLOADFLAG
#define _DOSRUNLOADFLAG 1553
#endif

// Decimal 1554 (0x612) [Value] - Fread/FLread flag 00=fread, $FF=FLread
#ifndef _DOSFLFREADFLAG
#define _DOSFLFREADFLAG 1554
#endif

// Decimal 1555 (0x613) [Value] - Auto flag, $FF=auto, $00=no auto
#ifndef _DOSAUTOFLAG
#define _DOSAUTOFLAG 1555
#endif

// Decimal 1556 (0x614) [Value] - ERROR GOTO flag, 0x00 Off Non-0x00 On
#ifndef _DOSERRGOTOFLAG
#define _DOSERRGOTOFLAG 1556
#endif

// Decimal 1557 (0x615) [Value] - Error destination line
#ifndef _DOSERRDESTLINE
#define _DOSERRDESTLINE 1557
#endif

// Decimal 1559 (0x617) [Value] - ERR line no
#ifndef _DOSERRLINENO
#define _DOSERRLINENO 1559
#endif

// Decimal 1561 (0x619) [Value] - Last ERR error
#ifndef _DOSERRLAST
#define _DOSERRLAST 1561
#endif

// Decimal 1564 (0x61C) [Value] - Drive 0 details (6 bytes)
#ifndef _DRV0DETAILS
#define _DRV0DETAILS 1564
#endif

// Decimal 1570 (0x622) [Value] - Drive 1 details (6 bytes)
#ifndef _DRV1DETAILS
#define _DRV1DETAILS 1570
#endif

// Decimal 1576 (0x628) [Value] - Drive 2 details (6 bytes)
#ifndef _DRV2DETAILS
#define _DRV2DETAILS 1576
#endif

// Decimal 1582 (0x62E) [Value] - Drive 3 details (6 bytes)
#ifndef _DRV3DETAILS
#define _DRV3DETAILS 1582
#endif

// Decimal 6 (0x6) [Value] - Entries are 6 bytes long
#ifndef _DRVDEATAILLEN
#define _DRVDEATAILLEN 6
#endif

// Decimal 5 (0x5) [Value] - Usage/open file count ?
#ifndef _DRVDETUSECNT
#define _DRVDETUSECNT 5
#endif

// Decimal 4 (0x4) [Value] - 4 disk buffers
#ifndef _BUFFCOUNT
#define _BUFFCOUNT 4
#endif

// Decimal 7 (0x7) [Value] - Buffer detail entries ar 7 bytes long
#ifndef _BUFFDETAILSIZE
#define _BUFFDETAILSIZE 7
#endif

// Decimal 1588 (0x634) [Value] - Disk buffer 1 details
#ifndef _BUFF1DETAILS
#define _BUFF1DETAILS 1588
#endif

// Decimal 1595 (0x63B) [Value] - Disk buffer 2 details
#ifndef _BUFF2DETAILS
#define _BUFF2DETAILS 1595
#endif

// Decimal 1602 (0x642) [Value] - Disk buffer 3 details
#ifndef _BUFF3DETAILS
#define _BUFF3DETAILS 1602
#endif

// Decimal 1609 (0x649) [Value] - Disk buffer 4 details
#ifndef _BUFF4DETAILS
#define _BUFF4DETAILS 1609
#endif

// Decimal 0 (0x0) [Value] - LSN number
#ifndef _BUFFLSN
#define _BUFFLSN 0
#endif

// Decimal 2 (0x2) [Value] - Flag, tested for $55 and $FF (also set to $01)
#ifndef _BUFFFLAG
#define _BUFFFLAG 2
#endif

// Decimal 3 (0x3) [Value] - Drive no 1..4
#ifndef _BUFFDRIVE
#define _BUFFDRIVE 3
#endif

// Decimal 4 (0x4) [Value] - Age of buffer since last use, 1=oldest..4=youngest
#ifndef _BUFFAGE
#define _BUFFAGE 4
#endif

// Decimal 5 (0x5) [Value] - Buffer address
#ifndef _BUFFADDR
#define _BUFFADDR 5
#endif

// Decimal 0 (0x0) [Value] - Disk buffer is free
#ifndef _BUFFFREE
#define _BUFFFREE 0
#endif

// Decimal 1 (0x1) [Value] - Unknown flag set by SuperDosFindAndRead
#ifndef _BUFFUNKNOWN
#define _BUFFUNKNOWN 1
#endif

// Decimal 85 (0x55) [Value] - Buffer in use
#ifndef _BUFFINUSE
#define _BUFFINUSE 85
#endif

// Decimal 255 (0xFF) [Value] - Buffer has been modified, but not written to disk
#ifndef _BUFFDIRTY
#define _BUFFDIRTY 255
#endif

// Decimal 1616 (0x650) [Value] - Dos current drive info
#ifndef _DOSCURDRIVEINFO
#define _DOSCURDRIVEINFO 1616
#endif

// Decimal 1624 (0x658) [Value] - Current extension, used in validation
#ifndef _DOSCUREXTENSION
#define _DOSCUREXTENSION 1624
#endif

// Decimal 1627 (0x65B) [Value] - Current drive no
#ifndef _DOSCURDRIVENO
#define _DOSCURDRIVENO 1627
#endif

// Decimal 1632 (0x660) [Value] - Current count, used in various places
#ifndef _DOSCURCOUNT
#define _DOSCURCOUNT 1632
#endif

// Decimal 1647 (0x66F) [Value] - Current LSN, of current DIR sector being processed
#ifndef _DOSCURLSN
#define _DOSCURLSN 1647
#endif

// Decimal 1663 (0x67F) [Value] - Pointer to the current Dire sector, Buffer def block
#ifndef _DOSCURDIRBUFF
#define _DOSCURDIRBUFF 1663
#endif

// Decimal 1666 (0x682) [Value] - Current file number on disk, to get dir entry for
#ifndef _DOSCURFILENO
#define _DOSCURFILENO 1666
#endif

// Decimal 1667 (0x683) [Value] - New USR table, relocated from low ram
#ifndef _DOSNEWUSRTABLE
#define _DOSNEWUSRTABLE 1667
#endif

// Decimal 1687 (0x697) [Value] - Drive 0 online flag
#ifndef _DOSD0ONLINE
#define _DOSD0ONLINE 1687
#endif

// Decimal 1688 (0x698) [Value] - Drive 1 online flag
#ifndef _DOSD1ONLINE
#define _DOSD1ONLINE 1688
#endif

// Decimal 1689 (0x699) [Value] - Drive 2 online flag
#ifndef _DOSD2ONLINE
#define _DOSD2ONLINE 1689
#endif

// Decimal 1690 (0x69A) [Value] - Drive 3 online flag
#ifndef _DOSD3ONLINE
#define _DOSD3ONLINE 1690
#endif

// Decimal 1691 (0x69B) [Value] - Drive 0 current track
#ifndef _DOSD0TRACK
#define _DOSD0TRACK 1691
#endif

// Decimal 1692 (0x69C) [Value] - Drive 1 current track
#ifndef _DOSD1TRACK
#define _DOSD1TRACK 1692
#endif

// Decimal 1693 (0x69D) [Value] - Drive 2 current track
#ifndef _DOSD2TRACK
#define _DOSD2TRACK 1693
#endif

// Decimal 1694 (0x69E) [Value] - Drive 3 current track
#ifndef _DOSD3TRACK
#define _DOSD3TRACK 1694
#endif

// Decimal 1695 (0x69F) [Value] - Drive 0 step rate
#ifndef _DOSD0STEPRATE
#define _DOSD0STEPRATE 1695
#endif

// Decimal 1696 (0x6A0) [Value] - Drive 1 step rate
#ifndef _DOSD1STEPRATE
#define _DOSD1STEPRATE 1696
#endif

// Decimal 1697 (0x6A1) [Value] - Drive 2 step rate
#ifndef _DOSD2STEPRATE
#define _DOSD2STEPRATE 1697
#endif

// Decimal 1698 (0x6A2) [Value] - Drive 3 step rate
#ifndef _DOSD3STEPRATE
#define _DOSD3STEPRATE 1698
#endif

// Decimal 1699 (0x6A3) [Value] - Tracks on disk in drive 0
#ifndef _DOSD0TRACKS
#define _DOSD0TRACKS 1699
#endif

// Decimal 1700 (0x6A4) [Value] - Tracks on disk in drive 1
#ifndef _DOSD1TRACKS
#define _DOSD1TRACKS 1700
#endif

// Decimal 1701 (0x6A5) [Value] - Tracks on disk in drive 2
#ifndef _DOSD2TRACKS
#define _DOSD2TRACKS 1701
#endif

// Decimal 1702 (0x6A6) [Value] - Tracks on disk in drive 3
#ifndef _DOSD3TRACKS
#define _DOSD3TRACKS 1702
#endif

// Decimal 1703 (0x6A7) [Value] - Sectors per track drive 0
#ifndef _DOSD0SECTRACK
#define _DOSD0SECTRACK 1703
#endif

// Decimal 1704 (0x6A8) [Value] - Sectors per track drive 1
#ifndef _DOSD1SECTRACK
#define _DOSD1SECTRACK 1704
#endif

// Decimal 1705 (0x6A9) [Value] - Sectors per track drive 2
#ifndef _DOSD2SECTRACK
#define _DOSD2SECTRACK 1705
#endif

// Decimal 1706 (0x6AA) [Value] - Sectors per track drive 3
#ifndef _DOSD3SECTRACK
#define _DOSD3SECTRACK 1706
#endif

// Decimal 1707 (0x6AB) [Value] - Directory sector status $06ab-$06bc
#ifndef _DOSDIRSECSTATUS
#define _DOSDIRSECSTATUS 1707
#endif

// Decimal 1725 (0x6BD) [Value] - File Control Block 0 Address
#ifndef _DOSFCB0ADDR
#define _DOSFCB0ADDR 1725
#endif

// Decimal 1756 (0x6DC) [Value] - File Control Block 1 Address
#ifndef _DOSFCB1ADDR
#define _DOSFCB1ADDR 1756
#endif

// Decimal 1787 (0x6FB) [Value] - File Control Block 2 Address
#ifndef _DOSFCB2ADDR
#define _DOSFCB2ADDR 1787
#endif

// Decimal 1818 (0x71A) [Value] - File Control Block 3 Address
#ifndef _DOSFCB3ADDR
#define _DOSFCB3ADDR 1818
#endif

// Decimal 1849 (0x739) [Value] - File Control Block 4 Address
#ifndef _DOSFCB4ADDR
#define _DOSFCB4ADDR 1849
#endif

// Decimal 1880 (0x758) [Value] - File Control Block 5 Address
#ifndef _DOSFCB5ADDR
#define _DOSFCB5ADDR 1880
#endif

// Decimal 1911 (0x777) [Value] - File Control Block 6 Address
#ifndef _DOSFCB6ADDR
#define _DOSFCB6ADDR 1911
#endif

// Decimal 1942 (0x796) [Value] - File Control Block 7 Address
#ifndef _DOSFCB7ADDR
#define _DOSFCB7ADDR 1942
#endif

// Decimal 1973 (0x7B5) [Value] - File Control Block 8 Address
#ifndef _DOSFCB8ADDR
#define _DOSFCB8ADDR 1973
#endif

// Decimal 2004 (0x7D4) [Value] - File Control Block 9 Address
#ifndef _DOSFCB9ADDR
#define _DOSFCB9ADDR 2004
#endif

// Decimal 2035 (0x7F3) [Value] - First byte beyond last FCB
#ifndef _DOSFCBEND
#define _DOSFCBEND 2035
#endif

// Decimal 2048 (0x800) [Value] - Base of Disk buffers
#ifndef _DOSDISKBUFFBASE
#define _DOSDISKBUFFBASE 2048
#endif

// Decimal 31 (0x1F) [Value] - 31 bytes per FCB
#ifndef _DOSFCBLENGTH
#define _DOSFCBLENGTH 31
#endif

// Decimal 0 (0x0) [Value] - Filename
#ifndef _FCBFILENAME
#define _FCBFILENAME 0
#endif

// Decimal 8 (0x8) [Value] - Extension
#ifndef _FCBEXTENSION
#define _FCBEXTENSION 8
#endif

// Decimal 11 (0xB) [Value] - Drive no
#ifndef _FCBDRIVE
#define _FCBDRIVE 11
#endif

// Decimal 12 (0xC) [Value] - File Pointer
#ifndef _FCBFILEPOINTER
#define _FCBFILEPOINTER 12
#endif

// Decimal 15 (0xF) [Value] - File Length
#ifndef _FCBFILELEN
#define _FCBFILELEN 15
#endif

// Decimal 29 (0x1D) [Value] - File number on disk, (dir entry no).
#ifndef _FCBDISKFILENO
#define _FCBDISKFILENO 29
#endif

// Decimal 0 (0x0) [Value] - Drive number of source
#ifndef _BUPSRCDRIVE
#define _BUPSRCDRIVE 0
#endif

// Decimal 1 (0x1) [Value] - $0001 Source track and sector ?
#ifndef _BUPSRCTRK
#define _BUPSRCTRK 1
#endif

// Decimal 2 (0x2) [Value] - Source sector no
#ifndef _BUPSRCSEC
#define _BUPSRCSEC 2
#endif

// Decimal 5 (0x5) [Value] - Source sector buffer addr ?
#ifndef _BUPSRCBUFF
#define _BUPSRCBUFF 5
#endif

// Decimal 7 (0x7) [Value] - Drive number of dest ?
#ifndef _BUPDESTDRIVE
#define _BUPDESTDRIVE 7
#endif

// Decimal 8 (0x8) [Value] - $0001 Dest track and sector ?
#ifndef _BUPDESTTRK
#define _BUPDESTTRK 8
#endif

// Decimal 9 (0x9) [Value] - Dest sector no
#ifndef _BUPDESTSEC
#define _BUPDESTSEC 9
#endif

// Decimal 12 (0xC) [Value] - Dest sector buffer addr ?
#ifndef _BUPDESTBUFF
#define _BUPDESTBUFF 12
#endif

// Decimal 14 (0xE) [Value] - Sector count per track to copy ?
#ifndef _BUPSECTRK
#define _BUPSECTRK 14
#endif

// Decimal 15 (0xF) [Value] - Pages available to buffer sectors
#ifndef _BUPAVAILPAGES
#define _BUPAVAILPAGES 15
#endif

// Decimal 0 (0x0) [Value] - Drive number
#ifndef _BUPDRIVE
#define _BUPDRIVE 0
#endif

// Decimal 1 (0x1) [Value] - $00 track
#ifndef _BUPTRK
#define _BUPTRK 1
#endif

// Decimal 2 (0x2) [Value] - $01 sector
#ifndef _BUPSEC
#define _BUPSEC 2
#endif

// Decimal 5 (0x5) [Value] - Source sector buffer addr ?
#ifndef _BUPBUFF
#define _BUPBUFF 5
#endif

// Decimal 55296 (0xD800) [Value] - Value for timeout loop
#ifndef _SPINUPDELAY
#define _SPINUPDELAY 55296
#endif

// Decimal 1 (0x1) [Value] - Drive we are syncing
#ifndef _SYNCDRIVE
#define _SYNCDRIVE 1
#endif

// Decimal 3 (0x3) [Value] - Sector we are syncing
#ifndef _SYNCSECNO
#define _SYNCSECNO 3
#endif

// Decimal 0 (0x0) [Value] - Restore to track 0
#ifndef _DOSFNRESTORE
#define _DOSFNRESTORE 0
#endif

// Decimal 1 (0x1) [Value] - Seek to a track
#ifndef _DOSFNSEEK
#define _DOSFNSEEK 1
#endif

// Decimal 2 (0x2) [Value] - Read a sector
#ifndef _DOSFNREADSEC
#define _DOSFNREADSEC 2
#endif

// Decimal 3 (0x3) [Value] - Write a sector
#ifndef _DOSFNWRITESEC
#define _DOSFNWRITESEC 3
#endif

// Decimal 4 (0x4) [Value] - not sure what difference is
#ifndef _DOSFNWRITESEC2
#define _DOSFNWRITESEC2 4
#endif

// Decimal 5 (0x5) [Value] - Write (format) track
#ifndef _DOSFNWRITETRACK
#define _DOSFNWRITETRACK 5
#endif

// Decimal 6 (0x6) [Value] - Read address mark
#ifndef _DOSFNREADADDR
#define _DOSFNREADADDR 6
#endif

// Decimal 7 (0x7) [Value] - Read first two bytes of a sector
#ifndef _DOSFNREADSEC2
#define _DOSFNREADSEC2 7
#endif

// Decimal 0 (0x0) [Value] - Attributes (see above)
#ifndef _DIRENTATTR
#define _DIRENTATTR 0
#endif

// Decimal 1 (0x1) [Value] - Filename, zero padded
#ifndef _DIRENTFILENAME
#define _DIRENTFILENAME 1
#endif

// Decimal 9 (0x9) [Value] - Extension, zero padded
#ifndef _DIRENTEXTENSION
#define _DIRENTEXTENSION 9
#endif

// Decimal 12 (0xC) [Value] - Allocation block #1
#ifndef _DIRENTFNBLOCK1
#define _DIRENTFNBLOCK1 12
#endif

// Decimal 15 (0xF) [Value] - Allocation block #2
#ifndef _DIRENTFNBLOCK2
#define _DIRENTFNBLOCK2 15
#endif

// Decimal 18 (0x12) [Value] - Allocation block #3
#ifndef _DIRENTFNBLOCK3
#define _DIRENTFNBLOCK3 18
#endif

// Decimal 21 (0x15) [Value] - Allocation block #4
#ifndef _DIRENTFNBLOCK4
#define _DIRENTFNBLOCK4 21
#endif

// Decimal 24 (0x18) [Value] - Filename/Continuation flag 0/nonzero
#ifndef _DIRENTFLAG
#define _DIRENTFLAG 24
#endif

// Decimal 1 (0x1) [Value] - Allocation block #1
#ifndef _DIRENTCNTBLOCK1
#define _DIRENTCNTBLOCK1 1
#endif

// Decimal 4 (0x4) [Value] - Allocation block #2
#ifndef _DIRENTCNTBLOCK2
#define _DIRENTCNTBLOCK2 4
#endif

// Decimal 7 (0x7) [Value] - Allocation block #3
#ifndef _DIRENTCNTBLOCK3
#define _DIRENTCNTBLOCK3 7
#endif

// Decimal 10 (0xA) [Value] - Allocation block #4
#ifndef _DIRENTCNTBLOCK4
#define _DIRENTCNTBLOCK4 10
#endif

// Decimal 13 (0xD) [Value] - Allocation block #5
#ifndef _DIRENTCNTBLOCK5
#define _DIRENTCNTBLOCK5 13
#endif

// Decimal 16 (0x10) [Value] - Allocation block #6
#ifndef _DIRENTCNTBLOCK6
#define _DIRENTCNTBLOCK6 16
#endif

// Decimal 19 (0x13) [Value] - Allocation block #7
#ifndef _DIRENTCNTBLOCK7
#define _DIRENTCNTBLOCK7 19
#endif

// Decimal 0 (0x0) [Value] - Logical sector number of start of allocation
#ifndef _ALLOCLSN
#define _ALLOCLSN 0
#endif

// Decimal 2 (0x2) [Value] - Count of number of sectors allocated.
#ifndef _ALLOCCOUNT
#define _ALLOCCOUNT 2
#endif

// Decimal 128 (0x80) [Value] - Deleted, may be reused
#ifndef _ATTRDELETED
#define _ATTRDELETED 128
#endif

// Decimal 32 (0x20) [Value] - Continuation entry, byte at $18 giver next entry no
#ifndef _ATTRCONTINUED
#define _ATTRCONTINUED 32
#endif

// Decimal 8 (0x8) [Value] - End of directory, no more entries need to be scanned
#ifndef _ATTRENDOFDIR
#define _ATTRENDOFDIR 8
#endif

// Decimal 2 (0x2) [Value] - Write protect flag
#ifndef _ATTRWRITEPROT
#define _ATTRWRITEPROT 2
#endif

// Decimal 1 (0x1) [Value] - This is a continuation entry.
#ifndef _ATTRISCONT
#define _ATTRISCONT 1
#endif

// Decimal 10 (0xA) [Value] - Directory entries per sector
#ifndef _DIRENTPERSEC
#define _DIRENTPERSEC 10
#endif

// Decimal 0 (0x0) [Value] - Bitmap uses bytes $00..$FB on first sector
#ifndef _BITMAPPART1
#define _BITMAPPART1 0
#endif

// Decimal 252 (0xFC) [Value] - Tracks on disk
#ifndef _DIRTRACKS
#define _DIRTRACKS 252
#endif

// Decimal 253 (0xFD) [Value] - Sectors/track 18=Single sided, 36=Double sided
#ifndef _DIRSECPERTRK
#define _DIRSECPERTRK 253
#endif

// Decimal 254 (0xFE) [Value] - complement of DirTracks (used to validate)
#ifndef _DIRTRACKS1S
#define _DIRTRACKS1S 254
#endif

// Decimal 255 (0xFF) [Value] - Complement of DirSecPerTrk (used to validate)
#ifndef _DIRSECPERTRK1S
#define _DIRSECPERTRK1S 255
#endif


#endif
