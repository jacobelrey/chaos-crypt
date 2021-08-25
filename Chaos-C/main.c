#include<stdint.h>
#include<stdio.h>

#include"vector.h"

void heunsPlusOne(matrix* params, vector* current, float stepSize) {
	vector xvec = { current->x,0.0,0.0 };
	vector uxv = cprod(xvec, *current);
	vector Ax = mprod(*params, *current);

	*current = vsum(*current, sprod(stepSize / 2, vsum(*current, sprod(stepSize + 1, vsum(Ax, uxv)))));
	
}

matrix initParams(float sigma, float rho, float beta) {
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
		beta
	};
	return (matrix) { v0, v1, v2 };
}


int main(void) {
	matrix params = initParams(10.0, 28.0, 8/3);
	vector vec = { 1.0,1.0,1.0 };
	for (int i = 0; i < 20000; i++) {
		heunsPlusOne(&params, &vec, 0.0001);
		printf("(%d) x:%.4F, y:%.4F, z:%.4F\n", i, vec.x, vec.y, vec.z);
	}
}