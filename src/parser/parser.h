//
// Created by Warbird Ozell on 10/11/22.
//

#ifndef INC_3DVIEWER_V1_0_PARSER_H
#define INC_3DVIEWER_V1_0_PARSER_H
#include <stdio.h>

bool notEOF = true;

typedef struct Indexes {
    unsigned int indexV;
    unsigned int indexF;
    float* array;
    unsigned int* vertexes;
} index;

void initialize(index *structure);
void parser_v(FILE *file, index* src);
void parser_f(FILE *file, index* src);

#endif //SRC/PARSER/INC_3DVIEWER_V1_0_PARSER_H
