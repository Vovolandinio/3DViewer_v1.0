#include "s21_parser.h"
#include <string.h>
static void parser_v(FILE *file, indexes* src);
static void parser_f(FILE *file, indexes* src, int count_fields);

void initialize(indexes *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = NULL;
    structure->indexess = NULL;
    structure->polygon = NULL;
    structure->maxV = 0;
    structure->maxF = 0;
}

int count_fields_in_file(const char *filename) {
    int count = 0;
    char c = '\0';
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        while((c = fgetc(file)) != EOF) {
            if (c == 'f')
                count++;
        }
        fclose(file);
    }
    return count;
}

int create_array_of_polygons(indexes* src, const char* filename) {
    int code = 0, count_fields_file = count_fields_in_file(filename);
    src->polygon = (polygon_t *)malloc((count_fields_file) * sizeof(polygon_t));
    if (src->polygon)
        for (int i = 0; i < count_fields_file; i ++)
            (src->polygon + i)->vertexes = (unsigned *)malloc(1 * sizeof(unsigned));
    else
        code = 1;
    src->indexF = count_fields_file;
    return code;
}

void from_struct_to_array(indexes* src) {
    src->indexess = malloc (src->maxF * sizeof(unsigned));
    int k = 0;
    for (int i = 0; i < src->indexF; i++) {
        int remember_k = k;
        for (int j = 0; j < (src->polygon + i)->numbers_of_vertexes_in_facets + 1; j++) {

            src->indexess[k] = (src->polygon + i)->vertexes[j];
            if (j != 0) {
                k++;
                src->indexess[k] = (src->polygon + i)->vertexes[j];
            }
            k++;
        }
        src->indexess[k] =  src->indexess[remember_k];
        k++;
    }
    src->maxF = k;
}

void main_parser(const char* filename, indexes* src) {
    initialize(src);
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        char c = '0';
        int count_fields = 0;
        int code = create_array_of_polygons(src, filename);
        src->array = (float *)calloc(1, sizeof(float));
        while((c = fgetc(file)) != EOF) {
            if (c == 'f') {
                parser_f(file, src, count_fields);
                src->maxF += (src->polygon + count_fields)->numbers_of_vertexes_in_facets;
                count_fields++;
            }
            if (c == 'v')
                parser_v(file, src);

        }
        fclose(file);
        from_struct_to_array(src);
        if(!src->indexV || !src->indexF) remove_array_of_polygons(src);
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

int get_number(FILE *file, char *c) {
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
    memset(str, '\0', 50);
    return number_verticies;
}

void full_array_in_polygon(unsigned *polyarray, FILE *file, char *c, int count_verticies) {
    if (count_verticies > 0)
        polyarray = (unsigned *) realloc(polyarray, ((count_verticies) * sizeof (unsigned )));
    polyarray[count_verticies] = get_number(file, c);
}

static void parser_f(FILE *file, indexes* src, int count_fields) {
    char c = '\0';
    int count_verticies = 0;

    while((c = fgetc(file)) != EOF) {
        if (c != ' ' && c != 'f' && c != '\n') {
            full_array_in_polygon((src->polygon + count_fields)->vertexes, file, &c, count_verticies);
            if (c == '/') {
                c = fgetc(file);
                if (c == '/') {
                    c = fgetc(file);
                    get_number(file, &c);
                } else {
                    c = fgetc(file);
                    get_number(file, &c);
                    if (c == '/') {
                        c = fgetc(file);
                        get_number(file, &c);
                    }
                }
            }
            count_verticies++;
            if (c == '\n' || c == EOF)
                break;
        }
    }
    (src->polygon + count_fields)->numbers_of_vertexes_in_facets = count_verticies - 1;
}


//int main() {
//    const char filename[50] = "tests/cub.obj";
//    indexes src;
//    main_parser(filename, &src);
//
//    // int k = 0;
//    // for (int i = 0; i < src.maxF - 1; i++)
//    //         printf("%u\n", src.indexess[i]);
//
//
//    remove_array_of_polygons(&src);
//
//    return 0;
//}

void remove_array_of_polygons(indexes* src) {
    for (int i = src->indexF - 1; i >= 0; i--) {
        free((src->polygon + i)->vertexes);
    }

    free(src->array);
    free(src->indexess);
    free(src->polygon);
}