//
// Created by Warbird Ozell on 10/11/22.
//

#ifndef INC_3DVIEWER_V1_0_PARSER_H
#define INC_3DVIEWER_V1_0_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bootstrap.h>


// bool notEOF = true;

typedef struct facets {
    unsigned *vertexes;
    int numbers_of_vertexes_in_facets;
    unsigned *texture_coordinates;
    unsigned is_texture;
    unsigned is_normal;
    unsigned *normal;
} polygon_t;

typedef struct Indexes {
    unsigned int indexV;
    unsigned int maxV;
    int indexF;
    int maxF;
    float* array; // координаты
    unsigned int* indexess; // индексы вершин
    unsigned int* vertexes;
    polygon_t *polygon;
} indexes;



void initialize(indexes *structure);
void main_parser(const char* filename, indexes* src);
// static void parser_v(FILE *file, index* src);
// static polygon_t parser_f(FILE *file, index* src);

#endif //SRC/PARSER/INC_3DVIEWER_V1_0_PARSER_H
