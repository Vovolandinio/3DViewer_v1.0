#include "s21_parser.h"

void rotate_x(indexes *src, double x) {
    for(size_t i = 0;i < src->indexV; i = i + 3) {
        double array = src->array[i];
        src->array[i] *= cos(x);
        src->array[i] += src->array[i + 1] * sin(x);
        src->array[i + 1] *= cos(x);
        src->array[i + 1] -= array * sin(x);
    }
}

void rotate_y(indexes *src, double x) {
    for(size_t i = 0;i < src->indexV; i = i + 3) {
        double array = src->array[i];
        src->array[i] *= cos(x);
        src->array[i] -= src->array[i + 2] * sin(x);
        src->array[i + 2] *= cos(x);
        src->array[i + 2] += array * sin(x);
    }
}

void rotate_z(indexes *src, double x) {
    for(size_t i = 0;i < src->indexV; i = i + 3) {
        double array = src->array[i];
        src->array[i] *= cos(x);
        src->array[i] += src->array[i + 1] * sin(x);
        src->array[i + 1] *= cos(x);
        src->array[i + 1] -= array * sin(x);
    }
}


