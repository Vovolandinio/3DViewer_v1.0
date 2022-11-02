#ifndef INC_3DVIEWER_V1_0_PARSER_H
#define INC_3DVIEWER_V1_0_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bootstrap.h>
#include <string.h>

// bool notEOF = true;

typedef struct facets {
    unsigned *vertexes;
    int numbers_of_vertexes_in_facets;
    unsigned *texture_coordinates;
    unsigned is_texture;
    unsigned is_normal;
    unsigned *normal;
} polygon_t;

typedef struct Indexes {
    unsigned int indexV;
    unsigned int maxV;
    int indexF;
    int maxF;
    float* array;
    unsigned int* indexess;
    polygon_t *polygon;
} indexes;


/**
 * .
 * @param structure
 * Pupi
 */
void initialize(indexes *structure);
/**
 *
 * @param filename
 * @param src
 */
void main_parser(const char* filename, indexes* src);
void remove_array_of_polygons(indexes* src);
int count_fields_in_file(const char *filename);
int create_array_of_polygons(indexes* src, const char* filename);
void from_struct_to_array(indexes* src);
void main_parser(const char* filename, indexes* src);
int get_number(FILE *file, char *c);
void full_array_in_polygon(unsigned *polyarray, FILE *file, char *c, int count_verticies);


#endif //SRC/PARSER/INC_3DVIEWER_V1_0_PARSER_H