#include<stdio.h>

void vider_buffer(void)
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int main(void) {
    int n, i, j;
    printf("Entrez un nombre entier: ");
    scanf("%d", &n);

    vider_buffer();

    printf("\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; ++j) {
            printf("  ");
        }

        for (j = 1; j <= 2 * i - 1; ++j) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}