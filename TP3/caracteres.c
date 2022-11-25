#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void affCar (char c) {
	printf("%c\n", c);
}

void majCar (char c) {
	c = toupper(c);
}

int majCarF (char c) {
	return toupper(c);
}

void majCarP (char *c) {
	printf("1 dans majCarP, c = %p, *c = %c\n", c, *c);
	*c = toupper(*c);
	printf("2 dans majCarP, c = %p, *c = %c\n", c, *c);
}

void majCarPbis (char *c) {
	printf("1 dans majCarPbis, c = %p, *c = %c\n", c, *c);
	c = malloc(sizeof(char));
	*c = 'a';
	printf("2 dans majCarPbis, c = %p, *c = %c\n", c, *c);
}

void ecrire_chaine(char *chaine) {
    while(*chaine != '\0') {
        printf("%c", *chaine);
        ++chaine;
    }
}

void maj_chaine(char *chaine) {
    while(*chaine != '\0') {
        *chaine = toupper(*chaine);
        ++chaine;
    }
}

void strcopy(char *dest, char *src) {
    while(*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';
}

void maj_chaine_f(char *chaine) {
    char *buffer = malloc(sizeof(chaine) +1);
    strcopy(buffer, chaine);
    maj_chaine(buffer);

    printf("%s", buffer);

    free(buffer);
}

int main (int argc, char *argv[]) {
	char car = 'b';

	affCar(car);
	majCar(car); affCar(car);
	affCar(majCarF(car)); affCar(car);
	majCarP(&car); affCar(car);
	majCarPbis(&car); affCar(car);

    char chaine[] = "Bonjour tout le monde!";
    maj_chaine(chaine);
    ecrire_chaine( chaine);
    printf("\n");
    maj_chaine_f("Bonjour tout le monde!");

	return 0;
}
