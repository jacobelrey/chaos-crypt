#include<stdint.h>
#include<float.h>
#include<math.h>
#include<stdio.h>
#include "vector.h"

int64_t dprod(vector lvec, vector rvec) {
	return lvec.x * rvec.x + lvec.y * rvec.y + lvec.z * rvec.z + lvec.w * rvec.w;
}

vector vsum(vector lvec, vector rvec) {
	return (vector) {
		!isfinite(lvec.x + rvec.x) ? (DBL_MAX-lvec.x) : lvec.x + rvec.x,
		!isfinite(lvec.y + rvec.y) ? (DBL_MAX-lvec.y) : lvec.y + rvec.y,
		!isfinite(lvec.z + rvec.z) ? (DBL_MAX-lvec.y): lvec.z + rvec.z,
		!isfinite(lvec.w + rvec.w) ? (DBL_MAX-lvec.w) : lvec.w + rvec.w,
	};
}

vector sprod(float scalar, vector vec) {
	return (vector) {
		!isfinite(vec.x * scalar) ? (DBL_MAX-vec.x) : vec.x * scalar,
		!isfinite(vec.y * scalar) ? (DBL_MAX-vec.y) : vec.y * scalar,
		!isfinite(vec.z * scalar) ? (DBL_MAX-vec.y) : vec.z * scalar,
		!isfinite(vec.w * scalar) ? (DBL_MAX-vec.w) : vec.w * scalar,
	};
}

vector mprod(matrix mat, vector vec) {
	vector vx = sprod(vec.x, mat.v0);
	vector vy = sprod(vec.y, mat.v1);
	vector vz = sprod(vec.z, mat.v2);
	vector vw = sprod(vec.w, mat.v3);
	return vsum(vsum(vsum(vx, vy), vz), vw);
}

void vector_print(vector* vec) {
	printf("(%Lf, %Lf, %Lf)\n", vec->x, vec->y, vec->z);
}