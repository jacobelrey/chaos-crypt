#include<stdint.h>

#include "vector.h"

vector cprod(vector lvec, vector rvec) {
	return (vector) {
		lvec.y*rvec.z- rvec.y * lvec.z,
		lvec.z* rvec.x - rvec.z * lvec.x,
		lvec.x* rvec.y - rvec.x * lvec.y
	};
}

int64_t dprod(vector lvec, vector rvec) {
	return lvec.x * lvec.x + lvec.y * lvec.y + lvec.z * lvec.z;
}

vector vsum(vector lvec, vector rvec) {
	return (vector) {
		lvec.x + rvec.x,
		lvec.y + rvec.y,
		lvec.z + rvec.z
	};
}

vector sprod(float scalar, vector vec) {
	return (vector) {
		vec.x * scalar,
		vec.y * scalar,
		vec.z * scalar,
	};
}

vector mprod(matrix mat, vector vec) {
	vector vx = sprod(vec.x, mat.v0);
	vector vy = sprod(vec.y, mat.v1);
	vector vz = sprod(vec.z, mat.v2);
	return vsum(vsum(vx, vy), vz);
}