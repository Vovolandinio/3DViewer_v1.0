#include "parser.h"

void normalize(index* stract){
    src->V = 0;
    src->F = 0;
}

void main_parser(char* filename, index* src) {
    normalize(src);
    FILE file = fopen(filename, "r");

    fclose(file);
}