#include<stdlib.h>


#ifndef FILEIO_H
#define FILEIO_H

FILE* openInputFile(char* filename);

FILE* openOutputFile(char* filename);

size_t readString(char* string, size_t max_string_length);

#endif //FILEIO_H


