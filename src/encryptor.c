#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include"vector.h"
#include"fileio.h"
#include"chaoticSystem.h"

int main(int argc, char* argv[]) {

    clock_t start, end;
	double cpu_time_used;
	
	start = clock();

    float* params = calloc(sizeof(float), 9);

	printf("input: %s\n", argv[1]);
    printf("output: %s\n", argv[2]);
    printf("Enter Encryption parameters (x0, y0, z0, w0, σ ρ β γ ε)");
    scanf("%f %f %f %f %f %f %f %f %f", params, params+1, params+2, params+3, params+4, params+5, params+6, params+7, params+8);

	FILE* input = openInputFile(argv[1]);
	FILE* output = openOutputFile(argv[2]);

    if(input == NULL) {
        printf("input File not found.Exiting.\n");
        return -1;
    }

    fseek(input, 0, SEEK_END);
    size_t fileLength = ftell(input);
    rewind(input);

    numericSolve(input,output,fileLength, params);

    fclose(input);
	fclose(output);

	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%ld clock cycles were used, making bitrate %.4f cycles/byte\n", (end-start), ((float)(end-start)/fileLength));
	printf("File encrypted in %.4f seconds.\n", cpu_time_used);
    free(params);
}