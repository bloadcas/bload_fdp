#include <stdio.h>
#include <mem.h>
#include "stdarrayio.h"

int main(int argc, char **argv) {

    tStdArrayIO tsaio;
    
    stdarrayio_init(&tsaio);
    printf("inited\n");
    stdarrayio_open(&tsaio, "file.txt");
    printf("opened\n");
    
    tStdArrayIODouble doubles = stdarrayio_readDouble1D(&tsaio);
    printf("%lf %lf %lf\n", doubles.elems[0],  doubles.elems[1],  doubles.elems[2]);
    
    stdarrayio_print1DLF(doubles);
    // stdarrayio_print(&tsaio);
    // printf("printed\n");
    
    stdarrayio_close(&tsaio);
    printf("closed\n");
    
    return 0;
}