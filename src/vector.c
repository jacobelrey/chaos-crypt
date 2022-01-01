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
		fmod(lvec.x, FLT_MAX) + fmod(rvec.x, FLT_MAX),
		fmod(lvec.y, FLT_MAX) + fmod(rvec.y, FLT_MAX),
		fmod(lvec.z, FLT_MAX) + fmod(rvec.z, FLT_MAX),
		fmod(lvec.w, FLT_MAX) + fmod(rvec.w, FLT_MAX),
	};
}

vector sprod(float scalar, vector vec) {
	return (vector) {
		!isfinite(vec.x * scalar) ? fmod(vec.x, FLT_MAX) * scalar : vec.x * scalar,
		!isfinite(vec.y * scalar) ? fmod(vec.y, FLT_MAX) * scalar : vec.y * scalar,
		!isfinite(vec.z * scalar) ? fmod(vec.y, FLT_MAX) * scalar : vec.z * scalar,
		!isfinite(vec.w * scalar) ? fmod(vec.w, FLT_MAX) * scalar : vec.w * scalar,
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
	printf("(%F, %F, %F)\n", vec->x, vec->y, vec->z);
}