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

    fclose(input);
	fclose(output);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Program completed in %.4F seconds.", cpu_time_used);
}