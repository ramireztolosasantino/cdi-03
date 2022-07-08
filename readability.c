#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    // TODO
    int i = 0;
    int oraciones = 0, palabras = 0, letras = 0;
    float index;
    float S;
    float L;
    while (text[i]) {

        if(isalpha(text[i])) {
            letras++;
        }    

        if(isspace(text[i])) {
            palabras++;
        }

        if(text[i]=='.'){
        oraciones++;
        }

        if(text[i]=='?'){
        oraciones++;
        }

        if(text[i]=='!'){
        oraciones++;
        }
        i++;
    }
    
    S = 100 * oraciones / palabras;
    L = 100 * letras / palabras;
    
    index = 0.0588 * L - 0.296 * S - 15.8;

    index=round(index);
    printf("%d",index);
    return 0;
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    while ((c = getc(fp)) != EOF) {
        *text = c;
        text++;
    }
    return 0;
}
