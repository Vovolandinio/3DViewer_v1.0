#include "parser.h"

void initialize(index *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = 0.0;
    structure->vertexes = 0;
}

void main_parser(const char* filename, index* src) {
    initialize(src);
    FILE file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        src->polygon->vertexes = (int*)calloc(1, sizeof(int));
        src->vertexes = (unsigned*)calloc(1, sizeof(unsigned));
        char buffer = '0';
        while(notEOF) {
            char c = fgetc(file);
            if (buffer == 'f' && c = ' ')
                parser_f(file, src);
            if (buffer == 'v' && c = ' ')
                parser_v(file, src);
        }
        fclose(file);
    }
}


void parser_v(FILE *file, index* src){
    if(src->vertexes != NULL) {
        src->vertexes = (float*)realloc(src->array, (src->indexV + 3) * sizeof(float));
        for (size_t i = 0; i < 0; i++) {
            src->vertexes[src->indexV + i];
        }
        fscanf(file, "%f %f %f", &src->vertexes[src->indexV], &src->vertexes[src->indexV + 1], &src->vertexes[src->indexV + 2]);
    src->indexV += 3;
    } else {
        printf("Memory error");
    }
}

void parser_f(FILE *file, index* src){

}