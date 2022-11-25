#include <stdio.h>

#define True 1
#define False 0

char chercher_caractere (char *c, char s)
{
    int i = 0;
    while (c[i] != '\0')
    {
        if (c[i] == s)
            return True;
        i++;
    }
    return False;
}

char multiple_de_3 (char *c)
{
    int i, somme;
    i = 0;
    somme = 0;
    while (c[i] != '\0')
    {
        somme += c[i] - '0';
        i++;
    }
    if (somme % 3 == 0)
        return True;
    return False;
}

int main(void) {
    printf("bonjour contient 'o' = %d", chercher_caractere("bonjour", 'o'));
    printf("\n");
    printf("bonjour contient 't' = %d", chercher_caractere("bonjour", 't'));
    printf("\n");
    printf("12345678 est multiple de 3 = %d", multiple_de_3("12345678"));
    printf("\n");
    printf("4 est multiple de 3 = %d", multiple_de_3("4"));

    return 0;
}