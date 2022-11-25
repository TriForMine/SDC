#include "chaines.h"
#include <stdio.h>
#include <stdlib.h>

int longueur (const char s[]) {
    int i = 0;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}

char *copieChaine (const char s[]) {
    int i = 0;
    char *copie = malloc(longueur(s) * sizeof(char));
    for (i = 0; s[i] != '\0'; i++) {
        copie[i] = s[i];
    }
    copie[i] = '\0';
    return copie;
}

char *concateneChaines (const char s1[], const char s2[]) {
    int i = 0;
    int j = 0;
    char *concat = malloc((longueur(s1) + longueur(s2) + 1) * sizeof(char));
    for (i = 0; s1[i] != '\0'; i++) {
        concat[i] = s1[i];
    }
    for (j = 0; s2[j] != '\0'; j++) {
        concat[i + j] = s2[j];
    }
    concat[i + j] = '\0';
    return concat;
}

char *miseEnMajuscules (const char s[]) {
    int i = 0;
    char *maj = malloc(longueur(s) * sizeof(char));
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            maj[i] = s[i] - 32;
        } else {
            maj[i] = s[i];
        }
    }
    maj[i] = '\0';
    return maj;
}

int compareChaines (const char s1[], const char s2[]) {
    int i = 0;
    int j = 0;
    for (i = 0; s1[i] != '\0' && s2[j] != '\0'; i++, j++) {
        if (s1[i] > s2[j]) {
            return 1;
        } else if (s1[i] < s2[j]) {
            return -1;
        }
    }
    if (s1[i] == '\0' && s2[j] == '\0') {
        return 0;
    } else if (s1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

char *strcat(char *dst, const char *src) {
    int i = 0;
    int j = 0;
    for (i = 0; dst[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++) {
        dst[i + j] = src[j];
    }
    dst[i + j] = '\0';
    return dst;
}

char *strcpy(char *dst, const char *src) {
    int i = 0;
    for (i = 0; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}

int main(void) {
    char *s1 = "Bonjour";

    printf("Longueur de %s : %d\n", s1, longueur(s1));

    char *s2 = copieChaine(s1);
    printf("Copie de %s : %s\n", s1, s2);
    char *s3 = concateneChaines(s1, s2);
    printf("Concaténation de %s et %s : %s\n", s1, s2, s3);
    char *s4 = miseEnMajuscules(s1);
    printf("Mise en majuscules de %s : %s\n", s1, s4);
    int cmp = compareChaines(s1, s2);
    printf("Comparaison de %s et %s : %d", s1, s2, cmp);

    /* Test de strcat */
    char *s5 = "Bonjour";
    char *s6 = " tout le monde";
    char *s7 = strcat(s5, s6);
    printf("Concaténation de %s et %s : %s\n", s5, s6, s7);

    /* Test de strcpy */
    char *s8 = "Bonjour";
    char *s9 = " tout le monde";
    char *s10 = strcpy(s8, s9);
    printf("Copie de %s dans %s : %s\n", s9, s8, s10);

    return 0;
}
