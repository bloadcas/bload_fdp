gcc -c  stdarrayio.c -g -O0 -Wall -o stdarrayio.c.o 
gcc main.c stdarrayio.c.o -o main.exe
pause