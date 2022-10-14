#include "parser.h"

void initialize_polygon(polygon_t* polygon);

void initialize(index *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = NULL;
    structure->vertexes = 0;
    // structure->polygon->numbers_of_vertexes_in_facets = 0;
    // structure->polygon->vertexes = NULL;
}


void main_parser(const char* filename, index* src) {
    initialize(src);
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        // src->polygon->vertexes = (int*)calloc(1, sizeof(int));
        src->array = (float*)calloc(1, sizeof(float));
        char buffer = '0';
        char c = '\0';
        int count_fields = 0;
        while((c = fgetc(file)) != EOF) {
            if (c == 'f' && buffer == '0') {
                src->polygon = (polygon_t *) realloc(src->polygon, count_fields);
                parser_f(file, src->polygon);
                count_fields++;
                // for (int j = 0; j < src->polygon->numbers_of_vertexes_in_facets; j++)
                //     printf("!count_verticies = %d: number_verticies = %d\n", j, src->polygon->vertexes[j]);
            }
            if (c == 'v' && buffer == '0')
                parser_v(file, src);
        }
        src->indexF = count_fields;
        fclose(file);
    }
}


void parser_v(FILE *file, index* src){
    if(src->array != NULL) {
        src->array = (float*)realloc(src->array, (src->indexV + 3) * sizeof(float));
        for (size_t i = 0; i < 0; i++) {
            src->array[src->indexV + i];
        }
        fscanf(file, "%f %f %f", &src->array[src->indexV], &src->array[src->indexV + 1], &src->array[src->indexV + 2]);
    src->indexV += 3;
    } else {
        printf("Memory error");
    }
}

int count_verticies_fun(FILE *file) {
    int count = 0;
    char cc[256] = "";
    while((fgets(cc, 256, file)) != NULL) {
        int i = 0;
        while(cc[i] != '\0') {
            if (cc[i] == ' ')
                count++;
            i++;
        }
    }
    return count;
}

void parser_f(FILE *file, polygon_t* polygon) {
    char c = '\0';
    int count_verticies = 0;
    if (polygon->vertexes != NULL)
    polygon->vertexes = (int*) malloc(sizeof(int) * 3);
    while((c = fgetc(file)) != '\n') {
        if (c != ' ') {
            int number_verticies = 0, i = 0;
            char str[50] = "";
            while(c != ' ' && c != '\n' && c != EOF) {
                str[i++] = c;
                c = fgetc(file);
            }
            while(i-- > 0)
                number_verticies += (str[i] - '0') * pow(10, i);
            
            if (count_verticies > 2) polygon->vertexes = (int *) realloc(polygon->vertexes, count_verticies+1);
            polygon->vertexes[count_verticies] = number_verticies;
            count_verticies++;
            if (c == '\n' || c == EOF) break;
        }
    }
    polygon->numbers_of_vertexes_in_facets = count_verticies;
}


int main() {
    const char filename[50] = "test.obj";
    index src;
    initialize(&src);
    main_parser(filename, &src);
    for (int i = 0; i < src.indexV; i++) {
        for (int j = 0; j < 3; j++)
            printf("!count_array = %d: number_verticies = %d\n", i, src.vertexes[j]);
        // src.polygon++;
    }
    for (int i = 0; i < src.indexF; i++) {
        for (int j = 0; j < src.polygon->numbers_of_vertexes_in_facets; j++)
            printf("!count_verticies = %d: number_verticies = %d\n", i, src.polygon->vertexes[j]);
        src.polygon++;
    }
    return 0;
}