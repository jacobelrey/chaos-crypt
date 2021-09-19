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

	printf("input: %s\n", argv[1]);
    printf("output: %s\n", argv[2]);


	FILE* input = openInputFile(argv[1]);
	FILE* output = openOutputFile(argv[2]);
	
    if(input == NULL) {
        printf("input File not found.Exiting.\n");
        return -1;
    }

    fseek(input, 0, SEEK_END);
    size_t fileLength = ftell(input);
    rewind(input);

    numericSolve(input,output,fileLength, false);

    fclose(input);
	fclose(output);

	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%ld clock cycles were used, making bitrate %ld bytes/clock", (end-start), (end-start)/fileLength);
	printf("File encrypted in %.4F seconds.\n", cpu_time_used);
}