#include "s21_parser.h"

void move_x(indexes* src, int shift){
    for (size_t i = 0; i < src->indexV; i = i + 3) {
        src->array[i] += shift;
    }
}
void move_y(indexes* src, int shift){
    for (size_t i = 1; i < src->indexV; i = i + 3) {
        src->array[i] += shift;
    }
}
void move_z(indexes* src, int shift){
    for (size_t i = 2; i < src->indexV; i = i + 3) {
        src->array[i] += shift;
    }
}