#include <stdio.h>

int main (int argc, char *argv[]) {
	int j = 2;
	int i = 100;
	int *pi = &i;

	printf("i = %d, j = %d, *pi = %d\n", i, j, *pi);
	*pi = 1000;
	printf("i = %d, j = %d, *pi = %d\n", i, j, *pi);
	pi[1] = -4; /* mais où va-t-on? */
	printf("i = %d, j = %d, *pi = %d\n", i, j, *pi);
	pi++; /* et là? */
	*pi = -100;
	printf("i = %d, j = %d, *pi = %d\n", i, j, *pi);
	return 0;
}
