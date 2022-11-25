#include <stdio.h>
#include "heures.h"

Heure heureLocale (void) {
    Heure h;
    h.h = 0;
    h.m = 0;
    h.s = 0;
    return h;
}

Heure saisirHeure (void) {
    Heure h;
    printf("Entrez l'heure (hh:mm:ss) : ");
    scanf("%hd:%hd:%hd", &h.h, &h.m, &h.s);
    return h;
}

Heure mettreHeure (short h, short m, short s) {
    Heure heure;
    heure.h = h;
    heure.m = m;
    heure.s = s;
    return heure;
}

void afficherHeure (Heure h, Systeme s) {
    if (s == syst24) {
        printf("%02hd:%02hd:%02hd ", h.h, h.m, h.s);
    } else {
        if (h.h < 12) {
            printf("%02hd:%02hd:%02hd PM ", h.h, h.m, h.s);
        } else {
            printf("%02hd:%02hd:%02hd AM ", h.h - 12, h.m, h.s);
        }
    }
}

long int heure2sec (Heure h) {
    return h.h * 3600 + h.m * 60 + h.s;
}

Heure sec2heure (long int s) {
    Heure h;
    h.h = s / 3600;
    h.m = (s % 3600) / 60;
    h.s = s % 60;
    return h;
}

Heure ajouterHeure (Heure h1, Heure h2) {
    return sec2heure(heure2sec(h1) + heure2sec(h2));
}

Heure soustraireHeure (Heure h1, Heure h2) {
    return sec2heure(heure2sec(h1) - heure2sec(h2));
}

int main(void) {
    Heure h1 = heureLocale();
    Heure h2 = saisirHeure();
    Heure h3 = mettreHeure(12, 30, 00);
    afficherHeure(h1, 24);
    afficherHeure(h2, 24);
    afficherHeure(h3, 12);
    printf("%ld\n", heure2sec(h1));
    Heure h4 = sec2heure(heure2sec(h1));
    afficherHeure(h4, 24);
    Heure h5 = ajouterHeure(h1, h2);
    afficherHeure(h5, 24);
    Heure h6 = soustraireHeure(h1, h2);
    afficherHeure(h6, 24);

    return 0;
}