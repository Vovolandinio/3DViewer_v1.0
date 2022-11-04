#ifndef INC_3DVIEWER_V1_0_PARSER_H
#define INC_3DVIEWER_V1_0_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bootstrap.h>
#include <string.h>


typedef struct Indexes {
    //! Number of vertices.
    unsigned int indexV;
    unsigned int maxV;
    //! Number of polygons.
    int indexF;
    //! Pointer on vertices.
    float* array;
    //! Pointer on polygons.
    unsigned int* indexess;
} indexes;


int isnum(char *c);

/**
* @brief Struct initialization.
* @param structure indexes.
 */
void initialize(indexes *structure);

/**
* @brief Accepts a file and redirects to other functions depending on the flag.
* @param filename file .obj.
* @param src structure.
 */
void main_parser(const char* filename, indexes* src);

/**
* @brief This function is used to free memory.
* @param src structure
*/
void remove_array_of_polygons(indexes* src);

int count_fields_in_file(const char *filename, indexes* src);

/**
 * @brief Memory allocation for a polygons.
 * @param src structure.
 * @param filename .obj file
 * @return code error.
 */
int create_array_of_polygons(indexes* src, const char* filename);

/**
* @brief This function is used to fill the array of polygons.
* @param src structure.
 */
void from_struct_to_array(indexes* src);

/**
 *
 * @param file
 * @param c
 * @return count of vertices.
 */
int get_number(FILE *file, char *c);

/**
* @brief This function is used to fill the array of polygons.
* @param polyarray
* @param file
* @param c
* @param count_verticies
*/
void full_array_in_polygon(unsigned *polyarray, FILE *file, char *c, int count_verticies);

/**
* @brief Affine transformation for the x-axis.
* @param array is Vertices.
* @param indexV count of Vertices.
* @param x coordinate.
*/
void rotate_x(float* array, int indexV, double x);

/**
* @brief Affine transformation for the y-axis.
* @param array is Vertices.
* @param indexV count of Vertices.
* @param y coordinate.
*/
void rotate_y(float* array, int indexV, double y);

/**
* @brief Affine transformation for the z-axis.
* @param array is Vertices.
* @param indexV count of Vertices.
* @param z coordinate.
*/
void rotate_z(float* array, int indexV, double z);

#endif //SRC/PARSER/INC_3DVIEWER_V1_0_PARSER_H