#include "s21_parser.h"


static void parser_v(FILE *file, indexes* src);
static polygon_t parser_f(FILE *file, indexes* src);

void initialize(indexes *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = NULL;
    structure->vertexes = 0;
    structure->polygon = NULL;
    structure->maxV = 0;
}


void main_parser(const char* filename, indexes* src) {
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
                src->polygon->vertexes = (unsigned *) realloc(src->polygon->vertexes, 1000);
                src->polygon->texture_coordinates = (unsigned *) realloc(src->polygon->texture_coordinates, 1000);
                src->polygon->normal = (unsigned *) realloc(src->polygon->normal, 1000);
                *(src->polygon + count_fields) = parser_f(file, src);
                count_fields++;
            }
            if (c == 'v' && buffer == '0')
            parser_v(file, src);
        }
        src->indexF = count_fields;
        if(!src->indexV) free(src->array);
        if(!src->indexF) free(src->polygon);
        fclose(file);
    }
}


static void parser_v(FILE *file, indexes* src) {
    if(src->array != NULL) {
        char c = '\0';
        if ((c = fgetc(file)) == 'n') c = fgetc(file);
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


unsigned get_number(FILE *file, char *c) {
    int number_verticies = 0, i = 0, k = 0;
    char str[50] = "";
    while(*c != ' ' && *c != '/' && *c != '\n' && *c != EOF && *c != '\0') {
        str[i] = *c;
        *c = fgetc(file);
        i++;
    }
    while(k < i) {
        number_verticies += (str[k] - '0') * pow(10, i - k - 1);
        k++;
    }
    return number_verticies;
}

static polygon_t parser_f(FILE *file, indexes* src) {
    char c = '\0';
    int count_verticies = 1;
    polygon_t polygoncopy;
    polygoncopy.numbers_of_vertexes_in_facets = 0;
    polygoncopy.vertexes = NULL;
    polygoncopy.texture_coordinates = NULL;
    polygoncopy.normal = NULL;
    polygoncopy.is_texture = 0; // no texture
    while((c = fgetc(file)) != EOF) {
        if (c != ' ' && c != 'f' && c != '\n') {
            unsigned number_verticies = get_number(file, &c);
            polygoncopy.vertexes = (unsigned *) realloc(polygoncopy.vertexes, (count_verticies * sizeof (unsigned )));
            polygoncopy.vertexes[count_verticies - 1] = number_verticies;
            if (c == '/') {
                c = fgetc(file);
                if (c == '/') {
                    c = fgetc(file);
                    unsigned normal = get_number(file, &c);
                    polygoncopy.normal = (unsigned *) realloc(polygoncopy.normal, (count_verticies * sizeof (unsigned )));
                    polygoncopy.normal[count_verticies - 1] = normal;
                } else {
                    polygoncopy.is_texture = 1;
                    unsigned texture_coordinates = get_number(file, &c);
                    polygoncopy.texture_coordinates = (unsigned *) realloc(polygoncopy.texture_coordinates, (count_verticies * sizeof (unsigned )));
                    polygoncopy.texture_coordinates[count_verticies - 1] = texture_coordinates;

                    c = fgetc(file);
                    unsigned normal = get_number(file, &c);
                    polygoncopy.normal = (unsigned *) realloc(polygoncopy.normal, (count_verticies * sizeof (unsigned )));
                    polygoncopy.normal[count_verticies - 1] = normal;
                }
            }
            // printf("%d\n", polygoncopy.is_texture);
            count_verticies++;
            if (c == '\n' || c == EOF)
                break;
        }
    }
    polygoncopy.numbers_of_vertexes_in_facets = count_verticies - 1;
    return polygoncopy;
}


int main() {
    const char filename[50] = "test.obj";
    indexes src;
    main_parser(filename, &src);
    for (int i = 0; i < src.indexV; i++)
       printf("!count_array = %d: number_verticies = %f\n", i, (src.array)[i]);

    for (int i = 0; i < src.indexF; i++) {
        for (int j = 0; j < (src.polygon + i)->numbers_of_vertexes_in_facets; j++) {
            printf("!count_verticies = %d: number_verticies = %u\n", i, (src.polygon + i)->vertexes[j]);
            printf("!count_verticies = %d: normal = %d\n", i, (src.polygon + i)->normal[j]);
            if ((src.polygon + i)->is_texture)
                printf("!count_verticies = %d: texture_coordinates = %d\n", i, (src.polygon + i)->texture_coordinates[j]);
        }
    }

    return 0;
}