#include "s21_parser.h"
static void parser_v(FILE *file, indexes* src);
static void parser_f(FILE *file, indexes* src, int count_fields, int *k );

void initialize(indexes *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = NULL;
    structure->indexess = NULL;
    structure->maxV = 0;
    structure->maxF = 0;
    structure->lines_count = 0;
}

unsigned count_fields_in_file(const char *filename, indexes *src) {
    unsigned count = 0, count_numbers = 0, count_slash = 0;
    char c = '\0';
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        while((c = fgetc(file)) != EOF) {
            if (c == 'f') {
                count++;
                while((c = fgetc(file)) != '\n' && c  != EOF) {
                    if (c == '/') count_slash++;
                    if (c == ' ') {
                        count_numbers++;
                    }
                }
            }
        }
        fclose(file);
    }
    src->maxF = count_numbers;
    if (count_slash == 0)
        src->maxF *= 2;

    return count;
}


void main_parser(const char* filename, indexes* src) {
    initialize(src);
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        char c = '0';
        unsigned count_fields = count_fields_in_file(filename, src), k = 0;
        src->array = (float *)calloc(1, sizeof(float));
        src->indexess = (unsigned*)calloc (src->maxF * 100000, sizeof(unsigned));
        while((c = fgetc(file)) != EOF) {
            if (c == 'f') {
                if ((c = fgetc(file)) == ' ') {
                    parser_f(file, src, count_fields, &k);
                    count_fields++;
                } 
            if (c == 'v')
                if ((c = fgetc(file)) == ' ') {
                    parser_v(file, src);
                }
        }

        fclose(file);
        if (src->lines_count != 0)
            src->lines_count--;
        // if(!src->indexV || !src->indexF) remove_arrays(src);
    }
}

static void parser_v(FILE *file, indexes* src) {
    if(src->array != NULL) {
        char c = '\0';
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
    unsigned number_verticies = 0, i = 0, k = 0;
    char str[50] = "";
    while(*c != ' ' && *c != '/' && *c != '\n' && *c != EOF) {
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

static void parser_f(FILE *file, indexes* src, int count_fields, int *k ) {
    char c = '\0';
    unsigned count_verticies = 0;
    unsigned remember_k = *k;
    while((c = fgetc(file)) != EOF) {
        if (c != ' ' && c != 'f' && c != '\n') {
            if (*k == remember_k) {
                src->indexess[*k] = get_number(file, &c) - 1;
                *k += 1;
            }
            else if (*k != remember_k) {
                src->indexess[*k] = get_number(file, &c) - 1;
                *k += 1;
                src->indexess[*k] = src->indexess[*k - 1];
                *k += 1;


            }
        }

            if (c == '/') {   /* этот кусок я позже уберу но пока он ОЧЕНЬ НУЖЕН */
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
            if (c == '\n' || c == EOF)
                break;
        }
    src->indexess[*k] = src->indexess[remember_k];
    src->lines_count += (*k - remember_k + 1) / 2;
    *k += 1;
}


// int main() {
//    const char filename[200] = "/Users/gloriagi/Desktop/3DViewer_v1.0/src/objectfiles/_cube 2.obj";
//    indexes src;
//    main_parser(filename, &src);
//    printf("!!!!!!!!!!!!!!!!!%d\n", src.maxF);
// //    for (int i = 0; i < src.indexV; i++)
// //            printf("%f\n", src.array[i]);
//    for (unsigned i = 0; i < src.maxF; i++)
//            printf("i: %u %u\n", i, src.indexess[i]);

// //    remove_arrays(&src);

//    return 0;
// }

void remove_arrays(indexes* src) {
    free(src->array);
    free(src->indexess);
}
