This beta version of VCC adds support for the "Becker" interface, which can be used
to communicate between the emulated CoCo and the outside world via a TCP socket.  A
common application for this interface is connecting with a DriveWire 4 server.

You will find configuration options for this interface on the BitBanger tab of the
config dialog.  

If you are running DriveWire on the same computer that you run Vcc, enter 127.0.0.1 
as the server IP address and 65504 as the TCP port.  This will match the settings 
used by the simple configuration wizard in DW4 if you choose "emulator" as your
platform and leave the other settings at their defaults.  You can also connect to a
server on another computer or even at another location by specifiying it's IP address
and port.

HDBDOS for DW ROMs are included in this installation and can be found in the same 
directory you installed Vcc to.  These can be used in VCC by selecting FD-502 config
from the Cartridge menu, and then choosing "External ROM Image" in the top lefthand
Dos Image selection, and then use the Browse button in the lower right to choose the
HDBDOS ROM image.  A hard reset is required when changing these options.

To use the Becker interface with NitrOS9, download any of the disks with names ending
in "becker" from http://www.nitros9.org/latest/

For technical details of the Becker interface, please see:
http://sourceforge.net/apps/mediawiki/drivewireserver/index.php?title=Becker_port_specification

Enjoy.
