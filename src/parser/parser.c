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
        while(notEOF) {
            char buffer = '0';
            char c = fgetc(file);
            if (buffer == 'f' && c = ' ')
                parser_f(file, src);
            if (buffer == 'v' && c = ' ')
                parser_v(file, src);
        }

    }
    }


    fclose(file);
}

void parser_v(FILE *file, index* src){

}

void parser_f(FILE *file, index* src){

}