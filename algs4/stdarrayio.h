#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef struct _StdArrayIO {
    
    FILE* ptr;
    char* pfilename;
    
} tStdArrayIO;


enum _tStdArrayIOError {
    E_OK,
    E_CANNOT_OPEN,
    E_CANNOT_CLOSE,
};
// Define an error type
typedef enum _tStdArrayIOError tStdArrayIOError;


void stdarrayio_init(tStdArrayIO* input);

void stdarrayio_free(tStdArrayIO* input);

tStdArrayIOError stdarrayio_open(tStdArrayIO* input, char* filename);

tStdArrayIOError stdarrayio_close(tStdArrayIO* input);

void stdarrayio_print(tStdArrayIO* input);



typedef struct _tStdArrayIODouble {
    double* elems;
    int count;
} tStdArrayIODouble;

tStdArrayIODouble stdarrayio_readDouble1D(tStdArrayIO* input);
void stdarrayio_print1DLF(tStdArrayIODouble a);
