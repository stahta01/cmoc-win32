..\bin\pic2raw -pal=1 -w 256 -h 192 -o image.raw images\1.png
..\bin\bin2c -v image1 -o 1.c image.raw

..\bin\pic2raw -pal=2 -w 128 -h 192 -o image.raw images\2.png
..\bin\bin2c -v image2 -o 2.c image.raw

..\bin\pic2raw -pal=3 -w 128 -h 192 -o image.raw images\3.png
..\bin\bin2c -v image3 -o 3.c image.raw

..\bin\pic2raw -pal=0 -w 256 -h 192 -o image.raw images\4.png
..\bin\bin2c -v image4 -o 4.c image.raw

..\bin\pic2raw -pal=3 -w 128 -h 192 -o image.raw images\5.png
..\bin\bin2c -v image5 -o 5.c image.raw

..\bin\pic2raw -pal=0 -w 256 -h 192 -o image.raw images\6.png
..\bin\bin2c -v image6 -o 6.c image.raw

..\bin\pic2raw -pal=3 -w 128 -h 192 -o image.raw images\7.png
..\bin\bin2c -v image7 -o 7.c image.raw

..\bin\pic2raw -pal=1 -w 256 -h 192 -o image.raw images\8.png
..\bin\bin2c -v image8 -o 8.c image.raw


del *.raw *.c.i *.asm *.asm.i *.o

pause
