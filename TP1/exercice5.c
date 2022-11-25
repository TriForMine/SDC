#include<stdio.h>

void vider_buffer() {
    int c;
    while((c=getchar()) != '\n' && c != EOF);
}

void question2() {
    int entier;

    printf("Choisissez un entier entre 1 et 100: ");

    while (scanf("%d", &entier) && (entier < 1 || entier > 100)) {
        printf("Entier invalide. Choisissez un entier entre 1 et 100: ");
    }

    vider_buffer();

    printf("Vous avez choisi %d\n", entier);
}

void question3() {
    int entier, num, total;
    num = 0;
    total = 0;

    printf("Choisissez un entier entre 1 et 20: ");

    while (scanf("%d", &entier) && entier != 99) {
        printf("Entrez un autre entier (99 pour terminer): ");
        total += entier;
        ++num;
    }

    vider_buffer();

    printf("La moyenne est %f\n", (float)total / num);
}

int main(void) {
    question2();
    question3();

    return 0;
}