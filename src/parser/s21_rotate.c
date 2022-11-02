#include "s21_parser.h"

void rotate_x(float* array, int indexV, double x) {
    double angle = x * (M_PI / 180);
    for (int i = 0; i < indexV; i = i + 3) {
        double buff_array_y = array[i + 1];
        double buff_array_z = array[i + 2];
        array[i + 1] = cos(angle) * buff_array_y - sin(angle) * buff_array_z;
        array[i + 2] = sin(angle) * buff_array_y + cos(angle) * buff_array_z;
    }
}

void rotate_y(float* array, int indexV, double y) {
    double angle = y * (M_PI / 180);
    for (int i = 0; i < indexV; i = i + 3) {
        double buff_array_x = array[i];
        double buff_array_z = array[i + 2];
        array[i] = cos(angle) * buff_array_x - sin(angle) * buff_array_z;
        array[i + 2] = sin(angle) * buff_array_x + cos(angle) * buff_array_z;
    }
}

void rotate_z(float* array, int indexV, double z) {
    double angle = z * (M_PI / 180);
    for (int i = 0; i < indexV; i = i + 3) {
        double buff_array_x = array[i];
        double buff_array_y = array[i + 1];
        array[i] = cos(angle) * buff_array_x - sin(angle) * buff_array_y;
        array[i + 1] = sin(angle) * buff_array_x + cos(angle) * buff_array_y;
    }
}
