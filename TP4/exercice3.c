#include <stdlib.h>
#include <stdio.h>

struct element {
    int contenu;
    struct element* suivant;
    struct element* precedent;
};

typedef struct element Element;

struct liste {
    Element* sentinelle;
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
    return l->sentinelle->suivant;
}

Element* dernier(Liste* l) {
    return l->sentinelle->precedent;
}

int est_vide(Liste* l) {
    return l->sentinelle->suivant == l->sentinelle;
}

void supprimer_premier(Liste* l) {
    if (!est_vide(l)) {
        Element* e = premier(l);
        l->sentinelle->suivant = e->suivant;
        e->suivant->precedent = l->sentinelle;
        free(e);
    }
}

void vider(Liste* l) {
    while (!est_vide(l)) {
        supprimer_premier(l);
    }
}

void ajouter_en_tete(Element* x, Liste* l) {
    x->suivant = l->sentinelle->suivant;
    x->precedent = l->sentinelle;
    l->sentinelle->suivant = x;
    x->suivant->precedent = x;
    ++l->num;
}

void ajouter_apres(Element* x, Element* y, Liste* l) {
    x->suivant = y->suivant;
    x->precedent = y;
    y->suivant = x;
    x->suivant->precedent = x;
    ++l->num;
}

void supprimer(Element* x) {
    x->precedent->suivant = x->suivant;
    x->suivant->precedent = x->precedent;
    free(x);
}

int longueur(Liste* l) {
    return l->num;
}

int main (void) {
    Liste l;
    Element e1;

    l.sentinelle = &e1;
    l.num = 0;

    printf("Est vide: %d\n", est_vide(&l));

    e1.contenu = 1;
    e1.suivant = NULL;
    ajouter_en_tete(&e1, &l);
    printf("Liste de longueur %d\n", longueur(&l));
    printf("Est vide: %d\n", est_vide(&l));

    return 0;
}