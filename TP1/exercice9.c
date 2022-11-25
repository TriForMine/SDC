#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[], char **envp) {
    FILE *f;
    char    *text;
    long    numbytes;

    f = fopen(argv[1], "r");

    fseek(f, 0L, SEEK_END);
    numbytes = ftell(f);
    fseek(f, 0L, SEEK_SET);

    text = (char*)calloc(numbytes, sizeof(char));
    if(text == NULL)
        return 1;

    fread(text, sizeof(char), numbytes, f);
    fclose(f);

    int lignes, mots, caracteres, i;
    char l;
    l = ' ';
    caracteres = strlen(text);
    mots = 0;
    lignes = 0;

    for (i = 0; i < strlen(text); i++) {
        if ((l == ' ' || l == '\n') && (text[i] != ' ' && text[i] != '\n')) {
            mots++;
        }
        if (text[i] == '\n') {
            lignes++;
        }
        l = text[i];
    }

    printf("Nombre de lignes: %d, Nombre de mots: %d, Nombre de caractères: %d", lignes, mots, caracteres);

    return 0;
}