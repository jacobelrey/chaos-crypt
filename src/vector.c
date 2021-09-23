#include<stdint.h>

#include "vector.h"

int64_t dprod(vector lvec, vector rvec) {
	return lvec.x * rvec.x + lvec.y * rvec.y + lvec.z * rvec.z + lvec.w * rvec.w;
}

vector vsum(vector lvec, vector rvec) {
	return (vector) {
		lvec.x + rvec.x,
		lvec.y + rvec.y,
		lvec.z + rvec.z,
		lvec.w + rvec.w,
	};
}

vector sprod(float scalar, vector vec) {
	return (vector) {
		vec.x * scalar,
		vec.y * scalar,
		vec.z * scalar,
		vec.w * scalar,
	};
}

vector mprod(matrix mat, vector vec) {
	vector vx = sprod(vec.x, mat.v0);
	vector vy = sprod(vec.y, mat.v1);
	vector vz = sprod(vec.z, mat.v2);
	vector vw = sprod(vec.w, mat.v3);
	return vsum(vsum(vsum(vx, vy), vz), vw);
}