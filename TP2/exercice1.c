#include <stdio.h>

void saisie_tab (int tab[], int n) {
    int i;
    for (i=0; i<n; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
}

void affiche_tab (int tab[], int n) {
    int i;
    printf("tab = [");
    for (i = 0; i < n; i++) {
        printf("%d; ", tab[i]);
    }
    printf("]");
}

int main(void) {
    int tab[10];
    saisie_tab(tab, 10);
    affiche_tab(tab, 10);

    return 0;
}