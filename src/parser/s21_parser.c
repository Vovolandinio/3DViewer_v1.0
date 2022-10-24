#include "s21_parser.h"
#include <string.h>
static void parser_v(FILE *file, indexes* src);
static void parser_f(FILE *file, indexes* src, int count_fields);

void initialize(indexes *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = NULL;
    structure->vertexes = NULL;
    structure->polygon = NULL;
    structure->maxV = 0;
    structure->maxF = 0;
}

void count_numbers_in_file(indexes* src, int count_fields) {
    src->maxF += (src->polygon + count_fields)->numbers_of_vertexes_in_facets +
        (src->polygon + count_fields)->numbers_of_vertexes_in_facets * src->polygon->is_normal +
        (src->polygon + count_fields)->numbers_of_vertexes_in_facets * src->polygon->is_texture;
}

int count_fields_in_file(const char *filename, int *count_numbers) {
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
    int code = 0;
    int count_numbers = 0, count_fields_file = count_fields_in_file(filename, &count_numbers);
    src->polygon = (polygon_t *)malloc((count_fields_file) * sizeof(polygon_t));
    if (src->polygon)
        for (int i = 0; i < count_fields_file; i ++) {
            (src->polygon + i)->vertexes = (unsigned *)malloc(1 * sizeof(unsigned));
            (src->polygon + i)->texture_coordinates = (unsigned *)malloc(1 * sizeof(unsigned));
            (src->polygon + i)->normal = (unsigned *)malloc(1 * sizeof(unsigned));
        }
    else
        code = 1;
    src->indexF = count_fields_file;
    return code;
}

void remove_array_of_polygons(indexes* src) {
    for (int i = src->indexF; i >= 0; i--) {
        for (int j = (src->polygon + i)->numbers_of_vertexes_in_facets; j >= 0; j--) {
                free((src->polygon + i)->vertexes + j);
            if ((src->polygon + i)->is_texture)
                free((src->polygon + i)->texture_coordinates + j);
            if ((src->polygon + i)->is_normal)
                free((src->polygon + i)->normal + j);
        }
    }
    free(src->polygon);
    free(src->array);
    free(src->vertexes);
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
                count_fields++;
            }
            if (c == 'v')
                parser_v(file, src);
            
        }
        if(!src->indexV) free(src->array);
        if(!src->indexF) remove_array_of_polygons(src);
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
    // if (count_verticies > 0)
    polyarray[count_verticies] = get_number(file, c);
    polyarray = (unsigned *) realloc(polyarray, ((count_verticies) * sizeof (unsigned )));

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
                    (src->polygon + count_fields)->is_normal = 1;
                    c = fgetc(file);
                    full_array_in_polygon((src->polygon + count_fields)->normal, file, &c, count_verticies);
                } else {
                    (src->polygon + count_fields)->is_texture = 1;
                    full_array_in_polygon((src->polygon + count_fields)->texture_coordinates, file, &c, count_verticies);
                    if (c == '/') {
                        (src->polygon + count_fields)->is_normal = 1;
                        c = fgetc(file);
                        full_array_in_polygon((src->polygon + count_fields)->normal, file, &c, count_verticies);
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

int main() {
    const char filename[50] = "../objectfiles/minicooper.obj";
    indexes src;
    main_parser(filename, &src);

    // for (int i = 0; i < src.indexV; i++)
    //    printf("!count_array = %d: number_verticies = %f\n", i, (src.array)[i]);

    // for (int i = 0; i < src.indexF; i++)
    //     for (int j = 0; j < (src.polygon + i)->numbers_of_vertexes_in_facets; j++) {
    //         printf("!count_verticies = %d: number_verticies = %u\n", i, (src.polygon + i)->vertexes[j]);
    //         if ((src.polygon + i)->is_normal)
    //             printf("!count_verticies = %d: normal = %d\n", i, (src.polygon + i)->normal[j]);
    //         if ((src.polygon + i)->is_texture)
    //             printf("!count_verticies = %d: texture_coordinates = %d\n", i, (src.polygon + i)->texture_coordinates[j]);
    //     }

    remove_array_of_polygons(&src);

    return 0;
}