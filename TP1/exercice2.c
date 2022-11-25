#include<stdio.h>

void question2(void) {
    int i;

    for (i = 65; i < 91; i++) {
        printf("%i ", i);
    }

    printf("\n");
}

void question3(void) {
    int i;

    for (i = 65; i < 91; i++) {
        printf("%c ", i);
    }

    printf("\n");
}

void question4(void) {
    char* s = "Pi vaut";
    float x = 3.1415926;

    printf("%s %f", s, x);

    printf("\n");
}

void question5(void) {
    char c = 'a';
    int i = 65;
    printf("valeur de c en caractère est %c, et son équivalent décimal est %d\n", c, c);
    printf("valeur de i en décimal est %d, et son équivalent caractère est %c\n", i, i);
}

void question6() {
    char s = 'a';

    while (s - 1 != 'z') {
        printf("%c ", s);
        ++s;
    }
}

int main(void) {
    question2();
    question3();
    question4();
    question5();
    question6();

    return 0;
}