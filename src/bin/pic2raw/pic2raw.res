        ��  ��                  N      �� ��               <?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
 <assemblyIdentity version="1.0.0.0" processorArchitecture="*" name="CompanyName.ProductName.YourApp" type="win32"/>
 <description>Your application description here.</description>
 <dependency>
  <dependentAssembly>
   <assemblyIdentity type="win32" name="Microsoft.Windows.Common-Controls" version="6.0.0.0" processorArchitecture="*" publicKeyToken="6595b64144ccf1df" language="*"/>
  </dependentAssembly>
 </dependency>
 <trustInfo xmlns="urn:schemas-microsoft-com:asm.v3">
  <security>
   <requestedPrivileges>
    <requestedExecutionLevel level="asInvoker" uiAccess="false"/>
   </requestedPrivileges>
  </security>
 </trustInfo>
 <compatibility xmlns="urn:schemas-microsoft-com:compatibility.v1">
  <application>
   <!-- Windows Vista -->
   <supportedOS Id="{e2011457-1546-43c5-a5fe-008deee3d3f0}" />
   <!-- Windows 7 -->
   <supportedOS Id="{35138b9a-5d96-4fbd-8e2d-a2440225f93a}" />
   <!-- Windows 8 -->
   <supportedOS Id="{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}" />
   <!-- Windows 8.1 -->
   <supportedOS Id="{1f676c76-80e1-4239-95bb-83d0f6d0da78}" />
   <!-- Windows 10 -->
   <supportedOS Id="{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}" />
   </application>
  </compatibility>
</assembly>  C  (   ��
 U S A G E                 Usage: pic2raw -pal=PALCODE [-w=WIDTH] [-h=HEIGHT] -o=OUTPUT INPUTFILE
pic2raw converts an image to a CoCo raw image file.

INPUTFILE : Supports bmp, png & jpeg images.
OUTPUT    : Output name of compressed CoCo picture.

PALCODE   : Selects palette used for color mapping.
            0 = Black/Green
            1 = Black/Buff
            2 = Green/Yellow/Blue/Red
            3 = Buff/Cyan/Magenta/Orange
            4 = Black/Red/Blue/Buff (Artificial)
            5 = Black/Blue/Red/Buff (Artificial)

WIDTH     : Width in pixels. If only a width is provided, the height will be
            adjusted to maintain aspect ratio of the input size. (Optional)

HEIGHT    : Height in pixels. If only a height is provided, the width will be
            adjusted to maintain aspect ration of the input size. (Optional)
