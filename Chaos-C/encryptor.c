#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#include"vector.h"
#include"fileio.h"
#include"chaoticSystem.h"

int main(int argc, char* argv[]) {

    clock_t start, end;
	double cpu_time_used;
	
	start = clock();
	
	FILE* input = openInputFile(argv[0]);
	FILE* output = openOutputFile(argv[1]);
	
    if(input == NULL) {
        printf("input File not found.Exiting.");
        return -1;
    }

    fseek(input, 0, SEEK_END);
    size_t lengthOfFile = ftell(input);
    rewind(input);

    numericSolve(input,output,lengthOfFile, false);

    fclose(input);
	fclose(output);

	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("File encrypted in %.4F seconds.", cpu_time_used);
}