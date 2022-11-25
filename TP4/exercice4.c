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

void ajouter_fin(Liste* L1, Liste* l2) {
    if (!est_vide(l2)) {
        Element* e = premier(l2);
        while (e != l2->sentinelle) {
            ajouter_apres(e, dernier(L1), L1);
            e = e->suivant;
        }
    }
}

void ajouter_debut(Liste* L1, Liste* L2) {
    if (!est_vide(L2)) {
        Element* e = dernier(L2);
        while (e != L2->sentinelle) {
            ajouter_en_tete(e, L1);
            e = e->precedent;
        }
    }
}

char est_paire(Element* x) {
    return x->contenu % 2 == 0;
}

void remove_impaire(Liste* L1, Liste* L2) {
    if (!est_vide(L1)) {
        Element* e = premier(L1);
        while (e != L1->sentinelle) {
            if (!est_paire(e)) {
                ajouter_apres(e, dernier(L2), L2);
                supprimer(e);
            }
            e = e->suivant;
        }
    }
}

int main (void) {
    Element* e, *e2, *e3, *e4;
    Liste* l = malloc(sizeof(Liste));
    Liste* l2 = malloc(sizeof(Liste));

    l->sentinelle = malloc(sizeof(Element));
    l->sentinelle->suivant = l->sentinelle;
    l->sentinelle->precedent = l->sentinelle;
    l->num = 0;

    l2->sentinelle = malloc(sizeof(Element));
    l2->sentinelle->suivant = l->sentinelle;
    l2->sentinelle->precedent = l->sentinelle;
    l2->num = 0;

    e = malloc(sizeof(Element));
    e->contenu = 1;
    e->suivant = NULL;
    e->precedent = NULL;
    ajouter_en_tete(e, l);
    e2 = malloc(sizeof(Element));
    e2->contenu = 2;
    e2->suivant = NULL;
    e2->precedent = NULL;
    ajouter_apres(e2, e, l);
    e3 = malloc(sizeof(Element));
    e3->contenu = 3;
    e3->suivant = NULL;
    e3->precedent = NULL;
    ajouter_apres(e3, e2, l);
    e4 = malloc(sizeof(Element));
    e4->contenu = 4;
    e4->suivant = NULL;
    e4->precedent = NULL;

    remove_impaire(l, l2);

    for (e = premier(l); e != l->sentinelle; e = e->suivant) {
        printf("%d", e->contenu);
    }

    return 0;
}