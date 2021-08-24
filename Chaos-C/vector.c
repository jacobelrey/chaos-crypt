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

vector sprod(int64_t scalar, vector vec) {
	return (vector) {
		scalar* vec.x,
		scalar* vec.y,
		scalar* vec.z,
	};
}

vector mprod(vector matrix[3], vector vec) {
	vector vx = sprod(vec.x, matrix[0]);
	vector vy = sprod(vec.y, matrix[1]);
	vector vz = sprod(vec.z, matrix[2]);
	return vsum(vsum(vx, vy), vz);
}