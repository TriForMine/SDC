/* ATTENTION: programme faux!!! */
#include <stdio.h>

double f (void) {
    double i;
    printf("un nombre décimal? ");
    scanf("%lf", &i);
    return i;
}

int main(void) {
    double nb = f();
    printf("Valeur du nombre lu = %lf\n", nb);
    return 0;
}