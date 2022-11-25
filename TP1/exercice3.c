#include<stdio.h>

int main(void) {
    float fi = 10.1f;
    float fj = 10.2f;
    printf("%.16f %.16f %.16f %d %d\n", fi, fj, fi + fj, (int)fi, fi);
    printf("%.32f %.32f %.32f %d %d\n", fi, fj, fi + fj, (int)fi, fi);
    printf("%.8f %.8f %.8f %d %d\n", fi, fj, fi + fj, (int)fi, fi);
    printf("%.2f %.2f %.2f %.2f\n", 5/2, 5.0/2, 5/2.0, 5.0/2.0);

    return 0;
}