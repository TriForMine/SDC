#include<stdio.h>

# define True 1
# define False 0

short estPremier(int n) {
    int i;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return False;
        }
    }
    return True;
}

void afficherPremiers(int n) {
    int i;
    for (i = 2; i < n; i++) {
        if (estPremier(i)) {
            printf("%i ", i);
        }
    }
}

short estNombreParfait(int n) {
    int i;
    int somme;
    somme = 0;

    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            somme += i;
        }
    }
    return somme == n;
}

void exercice1() {
    int n;
    printf("Entrez un nombre: ");
    scanf("%i", &n);
    afficherPremiers(n);

    printf("\n");
}

void exercice2(void) {
    int n, m, i;
    printf("Entrez un nombre minimum: ");
    scanf("%i", &n);
    printf("Entrez un nombre maximum: ");
    scanf("%i", &m);
    for (i = n; i <= m; ++i) {
        if (estNombreParfait(i)) {
            printf("%i ", i);
        }
    }

    printf("\n");
}

/* Le nombre n est un doublon */
short estDoublon(int n) {
    int i, somme, produits;
    somme = 0;
    produits = 1;

    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            somme += i;
            produits *= i;
        }
    }

    if (somme == 0) return False;

    return produits % somme == 0;
}

void exercice3() {
    int n, m, i;
    printf("Entrez un nombre minimum: ");
    scanf("%i", &n);
    printf("Entrez un nombre maximum: ");
    scanf("%i", &m);

    printf("Les nombres doublons sont: \n");

    for (i=n; i <= m; ++i) {
        if (estDoublon(i)) {
            printf("%i ", i);
        }
    }

    printf("\n");
}

int main(void) {
    while (True) {
        int choix;
        printf("Choisissez un exercice (0 pour quitter): ");
        scanf("%i", &choix);

        switch (choix) {
            case 1:
                exercice1();
                break;
            case 2:
                exercice2();
                break;
            case 3:
                exercice3();
                break;
            default:
                return 0;
        }
    }

    return 0;
}