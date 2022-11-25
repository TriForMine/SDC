#include <stdlib.h>
#include <stdio.h>

struct element {
    int contenu;
    struct element* suivant;
    struct element* precedent;
};

typedef struct element Element;

struct liste {
    Element* premier;
    int num;
};

typedef struct liste Liste;

int donnee(Element* e) {
    return e->contenu;
}

Element* suivant(Element* e) {
    return e->suivant;
}

Element* precedent(Element* e) {
    return e->precedent;
}

Element* premier(Liste* l) {
    return l->premier;
}

int est_vide(Liste* l) {
    return l->premier == NULL;
}

void supprimer_premier(Liste* l) {
    if (!est_vide(l)) {
        Element* a_supprimer = l->premier;
        l->premier = l->premier->suivant;
        --l->num;
        free(a_supprimer);
    }
}

void vider(Liste* l) {
    while (!est_vide(l)) {
        supprimer_premier(l);
    }
}

void ajouter_en_tete(Element* x, Liste* l) {
    x->suivant = l->premier;
    x->precedent = NULL;
    if (l->premier != NULL) {
        l->premier->precedent = x;
    }
    l->premier = x;
    ++l->num;
}

void ajouter_apres(Element* x, Element* y, Liste* l) {
    x->suivant = y->suivant;
    x->precedent = y;
    if (y->suivant != NULL) {
        y->suivant->precedent = x;
    }
    y->suivant = x;
    ++l->num;
}

void supprimer(Element* x) {
    if (x->precedent != NULL) {
        x->precedent->suivant = x->suivant;
    }
    if (x->suivant != NULL) {
        x->suivant->precedent = x->precedent;
    }
    free(x);
}

int longueur(Liste* l) {
    return l->num;
}

int main (void) {
    Liste l;
    Element e1;

    l.premier = NULL;
    printf("Est vide: %d\n", est_vide(&l));

    e1.contenu = 1;
    e1.suivant = NULL;
    ajouter_en_tete(&e1, &l);
    printf("Liste de longueur %d\n", longueur(&l));
    printf("Est vide: %d\n", est_vide(&l));

    return 0;
}