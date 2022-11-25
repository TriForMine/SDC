#include<stdio.h>

double exercice1(double celsius) {
    return celsius * 9 / 5 + 32;
}

double exercice2(double fahrenheit) {
    return 5 * (fahrenheit - 32) / 9;
}

double exercice3(double distance, double temps) {
    return (distance / 1000) / (temps / 60);
}

int main(void) {
    printf("Exercice 1: %lf\n", exercice1(32));
    printf("Exercice 2: %lf\n", exercice2(89.6));
    printf("Exercice 3: %lf\n", exercice3(100,1));

    return 0;
}