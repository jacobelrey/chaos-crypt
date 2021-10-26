#ifndef VECTOR_H

#include<stdint.h>
#define VECTOR_H

typedef struct vector {
	double x;
	double y;
	double z;
	double w;
} vector;

typedef struct matrix {
	vector v0;
	vector v1;
	vector v2;
	vector v3;
} matrix;

vector cprod(vector lvec, vector rvec);

int64_t dprod(vector lvec, vector rvec);

vector mprod(matrix mat, vector vec);

vector sprod(float scalar, vector vec);

vector vsum(vector lvec, vector rvec);

void vector_print(vector* vec);

#endif // !VECTOR_H
