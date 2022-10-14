#include "parser.h"

void initialize_polygon(polygon_t* polygon);

void initialize(index *structure) {
    structure->indexV = 0;
    structure->indexF = 0;
    structure->array = NULL;
    structure->vertexes = 0;
    initialize_polygon(structure->polygon);
}

void initialize_polygon(polygon_t* polygon) {
    polygon->numbers_of_vertexes_in_facets = 0;
    polygon->vertexes = NULL;
}

void main_parser(const char* filename, index* src) {
    initialize(src);
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL){
        printf("Cannot open file");
    } else {
        char buffer = '0';
        char c = '\0';
        while((c = fgetc(file)) != EOF) {
            if (c == 'f' && buffer == '0')
                parser_f(file, src);
            if (c == 'v' && buffer == '0')
                parser_v(file, src);
        }
        fclose(file);
    }
}


void parser_v(FILE *file, index* src){

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

void parser_f(FILE *file, index* src){
    char c = '\0';
    int count_verticies = 0; // count_verticies_fun(file);
    src->polygon->vertexes = (int *) calloc(6, sizeof(int));
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
            
            src->polygon->vertexes[count_verticies] = number_verticies;
            count_verticies++;
            if (c == '\n' || c == EOF) break;
        }
    }
    src->polygon->numbers_of_vertexes_in_facets = count_verticies;
    for(int i = 0; i < count_verticies; i++)
        printf("count_verticies = %d: number_verticies = %d\n", i, src->polygon->vertexes[i]);
}


int main() {
    const char filename[50] = "test.obj";
    index src;
    initialize(&src);
    main_parser(filename, &src);
    return 0;
}