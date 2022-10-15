#include "parser.h"

void initialize_polygon(polygon_t* polygon);

void initialize(index *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = NULL;
    structure->vertexes = 0;
    structure->polygon = NULL;

}


void main_parser(const char* filename, index* src) {
    initialize(src);
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {

        char buffer = '0';
        char c = '\0';
        int count_fields = 0;
        while((c = fgetc(file)) != EOF) {
            if (c == 'f' && buffer == '0') {
                src->polygon = (polygon_t *) realloc(src->polygon, (count_fields + 1) * sizeof(polygon_t));
                *(src->polygon + count_fields) = parser_f(file, src);
                for (int j = 0; j < (src->polygon + count_fields)->numbers_of_vertexes_in_facets; j++)
                    printf("!count_verticies = %d: number_verticies = %d\n", count_fields, (src->polygon + count_fields)->vertexes[j]);
                count_fields++;
            }
            // if (c == 'v' && buffer == '0')
                // parser_v(file, src);
        }
        src->indexF = count_fields;
        fclose(file);
    }
}


// void parser_v(FILE *file, index* src){
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

int count_verticies_fun(FILE *file) {
    int count = 0;
    char cc[256] = "";
    while((fgets(cc, 256, file)) != NULL) {
        int i = 0;
        while(cc[i] != '\0') {
            if (cc[i] == ' ')
                count++;
            i++;
        }
    }
    return count;
}

polygon_t parser_f(FILE *file, index* src) {
    char c = '\0';
    int count_verticies = 1;
    polygon_t polygoncopy;
    polygoncopy.numbers_of_vertexes_in_facets = 0;
    polygoncopy.vertexes = NULL;
    polygoncopy.vertexes = (int *) realloc(polygoncopy.vertexes, 1);
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

            polygoncopy.vertexes = (int *) realloc(polygoncopy.vertexes, (count_verticies + 1));
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
    // for (int i = 0; i < src.indexV; i++) {

    //     for (int j = 0; j < 3; j++)
    //         printf("!count_array = %d: number_verticies = %d\n", i, src.vertexes[j]);
    //     // src.polygon++;
    // }
    for (int i = 1; i < src.indexF; i++)
    for (int j = 1; j < (src.polygon + i)->numbers_of_vertexes_in_facets; j++)
        printf("!count_verticies = %d: number_verticies = %d\n", i, (src.polygon + i)->vertexes[j]);
    return 0;
}