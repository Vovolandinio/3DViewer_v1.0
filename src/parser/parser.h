//
// Created by Warbird Ozell on 10/11/22.
//

#ifndef INC_3DVIEWER_V1_0_PARSER_H
#define INC_3DVIEWER_V1_0_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bootstrap.h>


bool notEOF = true;

typedef struct facets {
    int *vertexes;
    int numbers_of_vertexes_in_facets;
} polygon_t;

typedef struct Indexes {
    unsigned int indexV;
    unsigned int indexF;
    float* array;
    unsigned int* vertexes;
    polygon_t *polygon;
} index;

void initialize(index *structure);
void parser_v(FILE *file, index* src);
void parser_f(FILE *file, index* src);

#endif //SRC/PARSER/INC_3DVIEWER_V1_0_PARSER_H
