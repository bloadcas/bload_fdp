#include "stdarrayio.h"

void stdarrayio_init(tStdArrayIO* input){

    assert(input != NULL);
    
    input->pfilename = NULL;
    input->ptr = NULL;
    
}

void stdarrayio_free(tStdArrayIO* input){

    assert(input != NULL);
    
    if(input->pfilename != NULL)
        free(input->pfilename);
    
    stdarrayio_init(input);
    
}

tStdArrayIOError stdarrayio_open(tStdArrayIO* input, char* filename){
    tStdArrayIOError  result;

    assert(input != NULL);
    assert(filename != NULL);

    input->pfilename = (char*)malloc(sizeof(char)*strlen(filename));
    strcpy(input->pfilename, filename);
    input->ptr = fopen(filename, "r");
    if (NULL == input->ptr) {
        result = E_CANNOT_OPEN;
        input->pfilename = NULL;
    } else {
        result = E_OK;
    }
    return result;
}
tStdArrayIOError stdarrayio_close(tStdArrayIO* input){
    tStdArrayIOError  result;

    assert(input != NULL);

    if( input->ptr != NULL ){
        // Closing the file
        fclose(input->ptr);
        result = E_OK;
    } else {
        result = E_CANNOT_CLOSE;
    }

    return result;
}

void stdarrayio_print(tStdArrayIO* input) {
    
    printf("The content of %s \n", input->pfilename);
    // Printing what is written in file
    // character by character using loop.
    char ch;
    do {
        ch = fgetc(input->ptr);
        printf("%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (ch != EOF);
}

  
  
// ------------------------------------------------------------
  
tStdArrayIODouble stdarrayio_readDouble1D(tStdArrayIO* input) {
    int i;
    double real;
    tStdArrayIODouble result;
    
    assert(input != NULL);
    
    result.count = 0;
    result.elems = NULL;
    
    fscanf(input->ptr, "%d", &i);
    if( i > 0 ) {
        result.elems = (double*)malloc(i*sizeof(double));
        result.count = 0;
        while (!feof (input->ptr)) 
        {
            fscanf (input->ptr, "%lf", &real);      
            if( result.count <= i-1 )
            {
                result.elems[result.count] = real;
                result.count++;
            }
        }
    }
    return result;
}


void stdarrayio_print1DLF(tStdArrayIODouble a) {
    int n = a.count;
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%9.5f ", a.elems[i]);
    }
    printf("\n");
}