#include "parser.h"

void initialize(index *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = 0;
    structure->vertexes = 0;
}

void main_parser(const char* filename, index* src) {
    initialize(src);
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        src->polygon->vertexes = (int*)calloc(1, sizeof(int));
        src->array = (float *)calloc(1, sizeof(float));
        char buffer = '0';
        while(notEOF) {
            char c = fgetc(file);
            if (buffer == 'f' && c == ' ')
                parser_f(file, src);
            if (buffer == 'v' && c == ' ')
                parser_v(file, src);
        }
        if (!src->indexF) free(src->polygon->vertexes);
        if (!src->indexV) free(src->array);
        fclose(file);
    }
}


void parser_v(FILE *file, index* src){
    if(src->array != NULL) {
        src->array = (float*)realloc(src->array, (src->indexV + 3) * sizeof(float));
        for (size_t i = 0; i < 0; i++) {
            src->array[src->indexV + i];
        }
        fscanf(file, "%f %f %f", &src->array[src->indexV], &src->array[src->indexV + 1], &src->array[src->indexV + 2]);
    src->indexV += 3;
    } else {
        printf("Memory error");
    }
}

void parser_f(FILE *file, index* src){

}

int main() {
    const char filename[50] = "test.obj";
    index src;
//    initialize(&src);
    main_parser(filename, &src);
    for (int i = 0; i < src.indexV; i++) {
        for (int j = 0; j < 3; j++)
            printf("!count_array = %d: number_verticies = %d\n", i, src.array[j]);
        // src.polygon++;
    }
    return 0;
}