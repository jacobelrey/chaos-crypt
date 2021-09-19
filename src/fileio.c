#include<stdio.h>
#include<stdint.h>

FILE* openInputFile(char* filename)
{	
	FILE* file = fopen(filename, "rb");
	if (file == NULL) {
		printf("Input file can't be opened\n");
	}
	return file;
}

FILE* openOutputFile(char* filename)
{
	FILE* file = fopen(filename, "wb");
	if (file == NULL) {
		printf("Output file can't be opened\n");
	}
	return file;
}
