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

void numericSolve(FILE* input, FILE* output, size_t messageLength, float init[], uint32_t windUp) {

	vector vec = { init[0],init[1],init[2], init[3] };

	float rho = init[4];
	float sigma = init[5];
	float beta = init[6];
	float gamma = init[7];

	uint8_t bytestream[4];

	
	matrix paramsVal={vec,vec,vec,vec};
	matrix* params = &paramsVal;

	FILE* chaos = fopen("./chaos.csv", "w");

	initParams(params,rho,sigma,beta,gamma);
	for(int i = 0; i<windUp + 1024; i++){
		heunsPlusOne(params, &vec, 0.0000000001);
	}
	for(int i=0; i<messageLength/16; i++) {
		
		heunsPlusOne(params, &vec, 0.0000000001);
		fprintf(chaos, "%Lf,", vec.x);
		fprintf(chaos, "%Lf,", vec.y);
		fprintf(chaos, "%Lf\n", vec.z);
		//printf("(%Lf, %Lf, %Lf)\n", vec.x, vec.y, vec.z);
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