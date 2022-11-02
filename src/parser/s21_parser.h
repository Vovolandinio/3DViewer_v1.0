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


///
/// @brief Struct initialization.
/// @param structure indexes.
///
void initialize(indexes *structure);

///
/// @brief Accepts a file and redirects to other functions depending on the flag.
/// @param filename file .obj.
/// @param src structure.
///
void main_parser(const char* filename, indexes* src);

///
/// @brief This function is used to free memory.
/// @param src structure
///
void remove_array_of_polygons(indexes* src);

int count_fields_in_file(const char *filename);

int create_array_of_polygons(indexes* src, const char* filename);

void from_struct_to_array(indexes* src);

int get_number(FILE *file, char *c);

void full_array_in_polygon(unsigned *polyarray, FILE *file, char *c, int count_verticies);


///
/// @brief Affine transformation for the x-axis.
/// @param array is Vertices.
/// @param indexV count of Vertices.
/// @param x coordinate.
///

void rotate_x(float* array, int indexV, double x);
///
/// @brief Affine transformation for the y-axis.
/// @param array is Vertices.
/// @param indexV count of Vertices.
/// @param y coordinate.
///

void rotate_y(float* array, int indexV, double y);

///
///@brief Affine transformation for the z-axis.
///@param array is Vertices.
///@param indexV count of Vertices.
///@param z coordinate.
///
void rotate_z(float* array, int indexV, double z);

#endif //SRC/PARSER/INC_3DVIEWER_V1_0_PARSER_H