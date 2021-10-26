#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>

#include"vector.h"

#ifndef CHAOS_H
#define CHAOS_H

void numericSolve(FILE* input, FILE* output, size_t messageLength, float init[], uint32_t windUp);

void GenNumeric(FILE* input, FILE* output, size_t messageLength, float init[], uint32_t windUp);

#endif //CHAOS_H
