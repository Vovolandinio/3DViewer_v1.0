#include "s21_parser.h"
static void parser_v(FILE *file, indexes* src);
static void parser_f(FILE *file, indexes* src);

void initialize(indexes *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = NULL;
    structure->indexess = NULL;
    structure->maxV = 0;
    structure->maxF = 0;
    structure->lines_count = 0;
}


void main_parser(const char* filename, indexes* src) {
    initialize(src);
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        char c = '0';
        src->array = (float *)calloc(1, sizeof(float));
        src->indexess = (unsigned *)calloc(1, sizeof(unsigned));
        while((c = fgetc(file)) != EOF) {
            if (c == 'f') {
                if ((c = fgetc(file)) == ' ') {
                    parser_f(file, src);
                }
            }
            if (c == 'v')
                if ((c = fgetc(file)) == ' ') {
                    parser_v(file, src);
                }
        }
        fclose(file);
        // if(!src->indexV || !src->indexF) remove_arrays(src);
    }
}

static void parser_v(FILE *file, indexes* src) {
    if(src->array != NULL) {
        char c = '\0';
        src->array = (float*)realloc(src->array, (src->indexV + 3) * sizeof(float));
        for (size_t i = 0; i < 3; i++) {
            src->array[src->indexV + i] = 0;
        }
        fscanf(file, "%f %f %f", &src->array[src->indexV], &src->array[src->indexV + 1], &src->array[src->indexV + 2]);
        for (size_t i = 0; i < 3; i++)
            if (fabs(src->array[src->indexV + i]) > src->maxV) src->maxV = fabs(src->array[src->indexV + i]);
        src->indexV += 3;
    } else {
        printf("Memory error");
    }
}


static void parser_f(FILE *file, indexes* src) {

}

int isnum(char *c) {
    return (c > 47 && c < 58);
}

// int main() {
//    const char filename[50] = "test.obj";
//    indexes src;
//    main_parser(filename, &src);
//    printf("!!!!!!!!!!!!!!!!!%d\n", src.maxF);
//    for (int i = 0; i < src.indexV; i++)
//            printf("%f\n", src.array[i]);
//    for (int i = 0; i < src.maxF; i++)
//            printf("%u\n", src.indexess[i]);

// //    remove_arrays(&src);

//    return 0;
// }
