#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <ctype.h>
#include <stdbool.h>

size_t readString(char* string, size_t max_string_length)
{
	size_t len = 0;
	char candidate = getchar();
	while (len < max_string_length && (candidate != '\n' && candidate != EOF)) {
		string[len] = candidate;
		candidate = getchar();
		len++;
	}
	string[len] = '\0';
	return len;
}

FILE* openInputFile(char* filename)
{	
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Input file can't be opened");
	}
	return file;
}

FILE* openOutputFile(char* filename)
{
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("Output file can't be opened");
	}
	return file;
}
