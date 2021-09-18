#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
#include"vector.h"

void heunsPlusOne(matrix* params, vector* current, float stepSize) {
	vector xvec = { current->x,0.0,0.0 };
	vector uxv = cprod(xvec, *current);
	vector Ax = mprod(*params, *current);

	*current = vsum(*current, sprod(stepSize / 2, vsum(*current, sprod(stepSize + 1, vsum(Ax, uxv)))));
	
}

static void initParams(matrix* params, float rho, float sigma, float beta) {
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
	params->v0=v0;
	params->v1=v1;
	params->v2=v2;
}

void numericSolve(FILE* input, FILE* output, size_t messageLength) {

	vector vec = { 1.0,1.0,1.0 };
	
	matrix paramsVal={vec,vec,vec};
	matrix* params = &paramsVal;
	
	initParams(params,28,10,8/3);

	uint8_t bytestream[3];

	for(int i=0; i<messageLength/3-1; i++) {
		
		heunsPlusOne(params, &vec, 0.01);

		bytestream[0] = fgetc(input);
		bytestream[1] = fgetc(input);
		bytestream[2] = fgetc(input);

		bytestream[0] ^=  (int8_t) (vec.x * 10000) % UINT8_MAX;
		bytestream[1] ^=  (int8_t) (vec.y * 10000) % UINT8_MAX;
		bytestream[2] ^=  (int8_t) (vec.z * 10000) % UINT8_MAX;


		printf("after mask%d\n", bytestream[0]);
		fwrite(bytestream, 3, sizeof(int8_t), output);
	}
	
	bytestream[0] = fgetc(input);
	bytestream[1] = fgetc(input);
	bytestream[2] = fgetc(input);
	printf("Message Length %ld", messageLength);

	if (bytestream[0] == EOF) {
		return;
	} else {
		heunsPlusOne(params, &vec, 0.01);
		bytestream[0] ^=  (int8_t) (vec.x * 10000) % UINT8_MAX;
		fwrite(&bytestream[0], 1, sizeof(uint8_t), output);
		if(bytestream[1] == EOF) {
			return;
		} else {
			heunsPlusOne(params, &vec, 0.01);
			bytestream[1] ^=  (int8_t) (vec.y * 10000) % UINT8_MAX;
			fwrite(&bytestream[1], 1, sizeof(uint8_t), output);
			if(bytestream[2] == EOF) {
				return;
			} else {
				heunsPlusOne(params, &vec, 0.01);
				bytestream[2] ^=  (uint8_t) (vec.z * 10000) % UINT8_MAX;
				fwrite(&bytestream[2], 1, sizeof(uint8_t), output);
			}
		}
	}
	printf("Message Length %ld", messageLength);
}