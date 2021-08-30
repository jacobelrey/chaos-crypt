#include<stdint.h>
#include<stdio.h>

#include"vector.h"
#include"fileio.h"

void heunsPlusOne(matrix* params, vector* current, float stepSize) {
	vector xvec = { current->x,0.0,0.0 };
	vector uxv = cprod(xvec, *current);
	vector Ax = mprod(*params, *current);

	*current = vsum(*current, sprod(stepSize / 2, vsum(*current, sprod(stepSize + 1, vsum(Ax, uxv)))));
	
}

matrix initParams(float rho, float sigma, float beta) {
	vector v0 = {
		-1*sigma,
		rho,
		0.0
	};
	vector v1 = {
		sigma,
		-1,
		0
	};

	vector v2 = {
		0,
		0,
		-1*beta
	};
	return (matrix) { v0, v1, v2 };
}


int main(void) {
	matrix params = initParams(28.0, 10.0, 8/3);
	vector vec = { 1.0,1.0,1.0 };
	
	char inputName[81];
	char outputName[81];
	FILE* input = NULL;
	FILE* output = NULL;
	
	readString(inputName, 80);
	readString(outputName, 80);

	input = openInputFile(inputName);

	if (input == NULL) {
	    
	} else {
	    output = openOutputFile(outputName);
        if(output == NULL) {
        } else {
			for (int i = 0; i < 380000; i++) {
				heunsPlusOne(&params, &vec, 0.001);
				fprintf(output, "%.4F,%.4F,%.4F\n", vec.x, vec.y, vec.z);
			}
		}
	}
	fclose(input);
	fclose(output);
}
