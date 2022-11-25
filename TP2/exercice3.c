#include <stdio.h>

int get_bit(unsigned int x, int pos) {
    return (x >> pos) & 1;
}

unsigned int set_bit(unsigned int x, int pos) {
    return x | (1 << pos);
}

unsigned int clear_bit(unsigned int x, int pos) {
    return x & ~(1 << pos);
}

unsigned int toggle_bit(unsigned int x, int pos) {
    return x ^ (1 << pos);
}

unsigned int define_bit(unsigned int x, int pos, int val) {
    if (1 == val)
        return set_bit(x, pos);
    return clear_bit(x, pos);
}

void afficher_bits(unsigned int x) {
    int i;
    printf("%d = ", x);
    for (i = 31; i >= 0; --i) {
        printf("%d", get_bit(x, i));
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

int multiplication_binaire(unsigned int x, unsigned int y) {
    int i;
    unsigned int res = 0;
    for (i = 0; i < 32; ++i) {
        if (get_bit(y, i) == 1)
            res += x << i;
    }
    afficher_bits(res);
    return res;
}

int division_binaire(unsigned int x, unsigned int y) {
    int i;
    unsigned int res = 0;
    for (i = 31; i >= 0; --i) {
        if (x >= (y << i)) {
            x -= y << i;
            res = set_bit(res, i);
        }
    }
    afficher_bits(res);
    return res;
}

unsigned int miroir(unsigned int x, int n) {
    int i;
    unsigned int res = 0;
    for (i = 0; i < n; ++i) {
        if (get_bit(x, i) == 1)
            res = set_bit(res, n - i - 1);
    }
    printf("Miroir %d bits de %d = %d\n", n, x, res);
    afficher_bits(x);
    afficher_bits(res);
    return res;
}

void extraire(unsigned int x) {
    int i;
    printf("\n10 bits les plus à gauche: ");

    for (i = 0; i < 10; ++i) {
        printf("%d", get_bit(x, 31 - i));
        if (i % 4 == 3)
            printf(" ");
    }

    printf("\n10 bits les plus à droite: ");
    for (i = 9; i >= 0; --i) {
        printf("%d", get_bit(x, i));
        if (i % 4 == 0)
            printf(" ");
    }

    printf("\n12 bits du milieu: ");

    for (i = 21; i >= 10; --i) {
        printf("%d", get_bit(x, i));
        if (i % 4 == 2)
            printf(" ");
    }
}

int main(void) {
    int a, b;

    printf("get_bit(1, 0) = %d\n", get_bit(1, 0));
    printf("get_bit(2, 0) = %d\n", get_bit(2, 0));
    printf("get_bit(2, 1) = %d\n", get_bit(2, 1));

    printf("set_bit(0, 0) = %d\n", set_bit(0, 0));
    printf("set_bit(2, 0) = %d\n", set_bit(2, 0));

    printf("clear_bit(2, 0) = %d\n", clear_bit(2, 0));
    printf("clear_bit(2, 1) = %d\n", clear_bit(2, 1));

    printf("toggle_bit(2, 0) = %d\n", toggle_bit(2, 0));
    printf("toggle_bit(2, 1) = %d\n", toggle_bit(2, 1));

    printf("define_bit(2, 0, 1) = %d\n", define_bit(2, 0, 1));
    printf("define_bit(1, 0, 0) = %d\n", define_bit(1, 0, 0));

    afficher_bits(8);
    afficher_bits(13);

    printf("\nTest des fonctions multiplication/divsions binaire\n\n");

    a = 9;
    b = multiplication_binaire(a, a);
    division_binaire(b, 9);

    printf("\nTest de la fonction miroir\n\n");

    miroir(8, 4);
    miroir(8, 32);

    printf("\nTest de la fonction extraire\n\n");
    afficher_bits(123456789);
    extraire(123456789);

    return 0;
}