#ifndef VECTOR_H

#include<stdint.h>
#define VECTOR_H

typedef struct vector {
	float x;
	float y;
	float z;
} vector;

typedef struct matrix {
	vector v0;
	vector v1;
	vector v2;
} matrix;

vector cprod(vector lvec, vector rvec);

int64_t dprod(vector lvec, vector rvec);

vector mprod(matrix mat, vector vec);

vector sprod(float scalar, vector vec);

vector vsum(vector lvec, vector rvec);

#endif // !VECTOR_H
