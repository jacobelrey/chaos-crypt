#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
#include"vector.h"

void heunsPlusOne(matrix* params, vector* current, float stepSize) {

	vector uxv = { 0, -1 * current->x * current->z, current->x * current->y, 0 };
	vector Ax = mprod(*params, *current);

	*current = vsum(*current, sprod(stepSize / 2, vsum(*current, sprod(stepSize + 1, vsum(Ax, uxv)))));
	
}

static void initParams(matrix* params, float rho, float sigma, float beta, float gamma) {
	vector v0 = {
		-1*sigma,
		rho,
		0.0,
		-1
	};
	vector v1 = {
		sigma,
		-1,
		0,
		0
	};

	vector v2 = {
		0,
		0,
		-1*beta,
		0
	};
	vector v3 = {
		gamma,
		0,
		0,
		sigma
	};

	params->v0=v0;
	params->v1=v1;
	params->v2=v2;
	params->v3=v3;
}

void numericSolve(FILE* input, FILE* output, size_t messageLength, uint32_t params[]) {

	vector vec = { params[0],params[1],params[2], params[3]};

	float rho = params[4];
	float sigma = params[5];
	float beta = params[6];
	float sigma = params[7];

	uint8_t bytestream[4];

	
	matrix paramsVal={vec,vec,vec,vec};
	matrix* params = &paramsVal;

	initParams(params,rho,sigma,beta,gamma);


	for(int i=0; i<messageLength/16; i++) {
		
		heunsPlusOne(params, &vec, 0.001);

		bytestream[0] = fgetc(input);
		bytestream[1] = fgetc(input);
		bytestream[2] = fgetc(input);
		bytestream[3] = fgetc(input);

		*(int32_t*) bytestream ^= *(int32_t*) &vec.x;
		fwrite(bytestream, 1, sizeof(int32_t), output);

		bytestream[0] = fgetc(input);
		bytestream[1] = fgetc(input);
		bytestream[2] = fgetc(input);
		bytestream[3] = fgetc(input);

		*(int32_t*) bytestream ^= *(int32_t*) &vec.y;
		fwrite(bytestream, 1, sizeof(int32_t), output);

		bytestream[0] = fgetc(input);
		bytestream[1] = fgetc(input);
		bytestream[2] = fgetc(input);
		bytestream[3] = fgetc(input);

		*(int32_t*) bytestream ^= *(int32_t*) &vec.z;
		fwrite(bytestream, 1, sizeof(int32_t), output);

		bytestream[0] = fgetc(input);
		bytestream[1] = fgetc(input);
		bytestream[2] = fgetc(input);
		bytestream[3] = fgetc(input);

		*(int32_t*) bytestream ^= *(int32_t*) &vec.w;
		fwrite(bytestream, 1, sizeof(int32_t), output);
	}

}