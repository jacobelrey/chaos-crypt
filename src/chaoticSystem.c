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

void numericSolve(FILE* input, FILE* output, size_t messageLength) {

	vector vec = { 1.0,1.0,1.0, 1.0};
	
	matrix paramsVal={vec,vec,vec,vec};
	matrix* params = &paramsVal;

	float rho, sigma, beta, gamma;

	printf("Enter Lorenz Parameters: (rho sigma beta gamma)");
    scanf("%f %f %f %f\n", &rho, &sigma, &beta, &gamma);

	initParams(params, rho,sigma,beta, gamma);

	uint8_t bytestream[4];

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


	/*

	bytestream[0] = fgetc(input);
	bytestream[1] = fgetc(input);
	bytestream[2] = fgetc(input);
	bytestream[3] = fgetc(input);


	
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
	*/
}