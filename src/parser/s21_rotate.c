#include "s21_parser.h"

void rotate_x(float* array, int indexV, double x) {
    x = x * M_PI / 180;
    for (size_t i = 1; i < indexV; i = i + 3) {
        double buff_array = array[i];
        array[i] *= cos(x);
        array[i] += array[i + 1] * sin(x);
        array[i + 1] *= cos(x);
        array[i + 1] -= buff_array * sin(x);
    }
}

void rotate_y(float* array, int indexV, double x) {
    x = x * M_PI / 180;
    for (size_t i = 0; i < indexV; i = i + 3) {
        double buff_array = array[i];
        array[i] *= cos(x);
        array[i] -= array[i + 2] * sin(x);
        array[i + 2] *= cos(x);
        array[i + 2] += buff_array * sin(x);
    }
}

void rotate_z(float* array, int indexV, double x) {
    x = x * M_PI / 180;
    for (size_t i = 0; i < indexV; i = i + 3) {
        double buff_array = array[i];
        array[i] *= cos(x);
        array[i] += array[i + 1] * sin(x);
        array[i + 1] *= cos(x);
        array[i + 1] -= buff_array * sin(x);
    }
}
