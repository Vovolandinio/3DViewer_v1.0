#include "s21_parser.h"

void rotate_x(float* array, int indexV, double x) {
    double agle = x * (M_PI / 180);
    for (unsigned int i = 0; i < indexV; i = i + 3) {
        double buff_array_y = array[i + 1];
        double buff_array_z = array[i + 2];
        array[i + 1] = cos(agle) * buff_array_y - sin(agle) * buff_array_z;
        array[i + 2] = sin(agle) * buff_array_y + cos(agle) * buff_array_z;
    }
}

void rotate_y(float* array, int indexV, double y) {
    double agle = y * (M_PI / 180);
    for (unsigned int i = 0; i < indexV; i = i + 3) {
        double buff_array_x = array[i];
        double buff_array_z = array[i + 2];
        array[i] = cos(agle) * buff_array_x - sin(agle) * buff_array_z;
        array[i + 2] = sin(agle) * buff_array_x + cos(agle) * buff_array_z;
    }
}

void rotate_z(float* array, int indexV, double z) {
    double agle = z * (M_PI / 180);
    for (unsigned int i = 0; i < indexV; i = i + 3) {
        double buff_array_x = array[i];
        double buff_array_y = array[i + 1];
        array[i] = cos(agle) * buff_array_x - sin(agle) * buff_array_y;
        array[i + 1] = sin(agle) * buff_array_x + cos(agle) * buff_array_y;
    }
}
