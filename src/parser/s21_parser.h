//
// Created by Warbird Ozell on 10/11/22.
//

#ifndef INC_3DVIEWER_V1_0_PARSER_H
#define INC_3DVIEWER_V1_0_PARSER_H
#include <bootstrap.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// bool notEOF = true;

typedef struct facets {
    unsigned *vertexes;
    unsigned numbers_of_vertexes_in_facets;
    unsigned *texture_coordinates;
    unsigned is_texture;
    unsigned is_normal;
    unsigned *normal;
} polygon_t;

typedef struct Indexes {
    unsigned int indexV;
    unsigned int maxV;
    unsigned long indexF;
    unsigned int maxF;
    float *array;
    unsigned int *vertexes;
    polygon_t *polygon;
} indexes;

void initialize(indexes *structure);
void main_parser(const char *filename, indexes *src);

void rotate_x(float *array, int indexV, double x);
void rotate_y(float *array, int indexV, double x);
void rotate_z(float *array, int indexV, double x);
// static void parser_v(FILE *file, index* src);
// static polygon_t parser_f(FILE *file, index* src);

#endif  // SRC/PARSER/INC_3DVIEWER_V1_0_PARSER_H
