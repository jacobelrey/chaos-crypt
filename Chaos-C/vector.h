#ifndef VECTOR_H

#include<stdint.h>
#define VECTOR_H

typedef struct vector {
	int64_t x;
	int64_t y;
	int64_t z;
} vector;

vector cprod(vector lvec, vector rvec);

int64_t dprod(vector lvec, vector rvec);

vector mprod(vector matrix[3], vector vec);

vector sprod(int64_t scalar, vector vec);

vector vsum(vector lvec, vector rvec);

#endif // !VECTOR_H
