#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#include"vector.h"
#include"fileio.h"
#include"chaoticSystem.h"

int main(void) {

    clock_t start, end;
	double cpu_time_used;
	
	start = clock();
	    
	char inputName[81];
	char outputName[81];
	FILE* input = NULL;
	FILE* output = NULL;
	
	printf("Enter Input Destination:");
	readString(inputName, 80);
	printf("Enter Output Destination:");
	readString(outputName, 80);

	input = openInputFile(inputName);
	output = openOutputFile(outputName);
	
    if(output != NULL) {
		numericSolve(input,output,1000000);
	}
	//fclose(input);
	fclose(output);
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Program completed in %.4F seconds.", cpu_time_used);
}
