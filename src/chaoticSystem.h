#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>

#include"vector.h"

#ifndef CHAOS_H
#define CHAOS_H

void numericSolve(FILE* input, FILE* output, size_t messageLength, bool isCoupled);

#endif //CHAOS_H