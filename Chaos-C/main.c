#include<stdint.h>
#include<stdio.h>

#include"vector.h"

void heunsPlusOne(vector* params[3], vector* current, int64_t stepSize) {
	vector xvec = { current->x,0,0 };
	*current = vsum(*current, vsum(*current, sprod(stepSize/2, vsum(*current, sprod(stepSize+1, vsum(mprod(params, *current), cprod(xvec, *current)))))));
}

void initParams(vector* params[3], int64_t sigma, int64_t rho, int64_t beta) {
	vector v0 = {
		-1*sigma,
		rho,
		(int64_t) 0
	};
	vector v1 = {
		sigma,
		(int64_t) -1,
		(int64_t) 0
	};

	vector v2 = {
		(int64_t) 0,
		(int64_t) 0,
		beta
	};
	*params[0] = v0;
	*params[0] = v1;
	*params[0] = v2;
}


int main(void) {
	vector v = { 0,0,0 };
	vector params[3] = {v,v,v};
	initParams(&params, 10, 28, 3);
	vector vec = { 1,1,1 };
	for (int i = 0; i < 1000; i++) {
		heunsPlusOne(&params, &vec, 1);
		printf("x:%ld, y:%ld, z:%ld\n", (long)vec.x, (long)vec.y, (long)vec.z);
	}
}