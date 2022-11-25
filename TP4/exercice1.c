#include <stdio.h>
#include <stdlib.h>

struct tableau {
    int *tab;
    int taille;
};

typedef struct tableau Tableau;

int* doubler_tableau(int *t, int n) {
    int i;
    int *t2 = malloc(2*n*sizeof(int));
    for (i = 0; i < n; i++) {
        t2[i] = t[i];
    }
    free(t);
    return t2;
}

Tableau rallouer(Tableau t) {
    int i;
    int *t2 = malloc(2*t.taille*sizeof(int));
    for (i = 0; i < t.taille; i++) {
        t2[i] = t.tab[i];
    }
    free(t.tab);
    t.tab = t2;
    t.taille *= 2;
    return t;
}

int main(void) {
    int i;
    int *t = malloc(10*sizeof(int));
    for (i = 0; i < 10; i++) {
        t[i] = i;
    }
    t = doubler_tableau(t, 10);
    for (i = 0; i < 20; i++) {
        printf("%d ", t[i]);
    }

    printf("\n");

    Tableau t2;
    t2.tab = malloc(10*sizeof(int));
    t2.taille = 10;

    for (i = 0; i < 10; i++) {
        t2.tab[i] = i;
    }
    t2 = rallouer(t2);
    for (i = 0; i < 20; i++) {
        printf("%d ", t2.tab[i]);
    }

    return 0;
}