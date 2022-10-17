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
    structure->maxF = 0;
}

void count_numbers_in_file(indexes* src, int count_fields) {
    src->maxF += (src->polygon + count_fields)->numbers_of_vertexes_in_facets +
        (src->polygon + count_fields)->numbers_of_vertexes_in_facets * src->polygon->is_normal +
        (src->polygon + count_fields)->numbers_of_vertexes_in_facets * src->polygon->is_texture;
}

int count_fields_in_file(const char *filename) {
    int count = 0, count_numbers = 0;
    char c = '\0';
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        while((c = fgetc(file)) != EOF)
            if (c == 'f')
                count++;
        fclose(file);
    }
    return count;
}

void main_parser(const char* filename, indexes* src) {
    initialize(src);
    FILE *file;
    int count_fields_file = count_fields_in_file(filename);
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        char buffer = '0';
        char c = '0';
        int count_fields = 0;
        src->polygon = (polygon_t *)malloc(count_fields_file * sizeof(polygon_t));
        for (int i = 0; i < 100; i ++) {
            (src->polygon + i)->vertexes = (unsigned *)malloc(1000 * sizeof(unsigned));
            (src->polygon + i)->texture_coordinates = (unsigned *)malloc(1000 * sizeof(unsigned));
            (src->polygon + i)->normal = (unsigned *)malloc(1000 * sizeof(unsigned));
        } 
        src->array = (float *)calloc(1, sizeof(float));
        while((c = fgetc(file)) != EOF) {
            if (c == 'f' && buffer == '0') {
                *(src->polygon + count_fields) = parser_f(file, src);
                count_numbers_in_file(src, count_fields);
                count_fields++;
            }
            if (c == 'v' && buffer == '0')
                parser_v(file, src);
            
        }
        if(!src->indexV) free(src->array);
        if(!src->indexF) free(src->polygon);
        fclose(file);
        src->indexF = count_fields;
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
    polygoncopy.is_normal = 0; // no normal


    polygoncopy.vertexes = (unsigned *) malloc(3 * sizeof(unsigned));
    polygoncopy.normal = (unsigned *) malloc(3 * sizeof(unsigned));
    polygoncopy.texture_coordinates = (unsigned *) malloc(3 * sizeof(unsigned));

    while((c = fgetc(file)) != EOF) {
        if (c != ' ' && c != 'f' && c != '\n') {
            unsigned number_verticies = get_number(file, &c);
            polygoncopy.vertexes = (unsigned *) realloc(polygoncopy.vertexes, (count_verticies * sizeof (unsigned )));
            polygoncopy.vertexes[count_verticies - 1] = number_verticies;
            if (c == '/') {
                c = fgetc(file);
                if (c == '/') {
                    polygoncopy.is_normal = 1;
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
            count_verticies++;
            if (c == '\n' || c == EOF)
                break;
        }
    }
    polygoncopy.numbers_of_vertexes_in_facets = count_verticies - 1;
    return polygoncopy;
}


int main() {
    const char filename[50] = "minicooper.obj";
    indexes src;
    main_parser(filename, &src);

    for (int i = 0; i < src.indexV; i++)
       printf("!count_array = %d: number_verticies = %f\n", i, (src.array)[i]);

    for (int i = 0; i < src.indexF - 1; i++) {
        for (int j = 0; j < (src.polygon + i)->numbers_of_vertexes_in_facets; j++) {
            printf("!count_verticies = %d: number_verticies = %u\n", i, (src.polygon + i)->vertexes[j]);
            printf("!count_verticies = %d: normal = %d\n", i, (src.polygon + i)->normal[j]);
            if ((src.polygon + i)->is_texture)
                printf("!count_verticies = %d: texture_coordinates = %d\n", i, (src.polygon + i)->texture_coordinates[j]);
        }
    }

    return 0;
}