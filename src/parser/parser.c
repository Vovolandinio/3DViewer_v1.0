#include "parser.h"


static void parser_v(FILE *file, index* src);

void initialize(index *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = NULL;
    structure->vertexes = 0;
    structure->polygon = NULL;
    structure->maxV = 0;
}


void main_parser(const char* filename, index* src) {
    initialize(src);
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        char buffer = '0';
        char c = '0';
        int count_fields = 0;
        src->polygon = (polygon_t *)calloc(1, sizeof(polygon_t));
        src->array = (float *)calloc(1, sizeof(float));
        while((c = fgetc(file)) != EOF) {
            if (c == 'f' && buffer == '0') {
                *(src->polygon + count_fields) = parser_f(file, src);
                count_fields++;
            }
//             if (c == 'v' && buffer == '0')
//             parser_v(file, src);
        }
        src->indexF = count_fields;
        if(!src->indexV) free(src->array);
        if(!src->indexF) free(src->polygon);
        fclose(file);
    }
}


//static void parser_v(FILE *file, index* src) {
//     if(src->array != NULL) {
//         src->array = (float*)realloc(src->array, (src->indexV + 3) * sizeof(float));
//         for (size_t i = 0; i < 0; i++) {
//             src->array[src->indexV + i];
//         }
//         fscanf(file, "%f %f %f", &src->array[src->indexV], &src->array[src->indexV + 1], &src->array[src->indexV + 2]);
//     src->indexV += 3;
//     } else {
//         printf("Memory error");
//     }
// }


static polygon_t parser_f(FILE *file, index* src) {
    char c = '\0';
    int count_verticies = 1;
    polygon_t polygoncopy;
    polygoncopy.numbers_of_vertexes_in_facets = 0;
    polygoncopy.vertexes = NULL;
    while((c = fgetc(file)) != EOF) {
        if (c != ' ' && c != 'f' && c != '\n') {
            int number_verticies = 0, i = 0, k = 0;
            char str[50] = "";
            while(c != ' ' && c != '\n' && c != EOF) {
                str[i] = c;
                c = fgetc(file);
                i++;
            }
            while(k < i) {
                number_verticies += (str[k] - '0') * pow(10, i - k - 1);
                k++;
            }
            polygoncopy.vertexes = (unsigned *) realloc(polygoncopy.vertexes, (count_verticies * sizeof (unsigned )));
            polygoncopy.vertexes[count_verticies - 1] = number_verticies;
            count_verticies++;
            if (c == '\n' || c == EOF) break;
        }
    }
    polygoncopy.numbers_of_vertexes_in_facets = count_verticies;
    return polygoncopy;
}


int main() {
    const char filename[50] = "test.obj";
    index src;
    main_parser(filename, &src);
//     for (int i = 0; i < src.indexV; i++)
//         for (int j = 0; j < 3; j++)
//             printf("!count_array = %d: number_verticies = %d\n", j, src.vertexes[j]);

    for (int i = 0; i < src.indexF; i++)
        for (int j = 0; j < (src.polygon + i)->numbers_of_vertexes_in_facets; j++)
            printf("!count_verticies = %u: number_verticies = %u\n", i, (src.polygon + i)->vertexes[j]);
    return 0;
}