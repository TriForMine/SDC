#include <stdlib.h>
#include <stdio.h>

struct element {
    int contenu;
    struct element* suivant;
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
    l->premier = x;
    ++l->num;
}

void ajouter_apres(Element* x, Element* y, Liste* l) {
    x->suivant = y->suivant;
    y->suivant = x;
    ++l->num;
}

void supprimer_suivant(Element* x, Liste* l) {
    if (x->suivant != NULL) {
        Element* a_supprimer = x->suivant;
        x->suivant = x->suivant->suivant;
        --l->num;
        free(a_supprimer);
    }
}

int longueur(Liste* l) {
    return l->num;
}

Liste* fusion_destructrice(Liste* l1, Liste* l2) {
    Element* e1;
    Element* e2;
    e1 = premier(l1);
    e2 = premier(l2);
    while (e2 != NULL) {
        if (e1 == NULL || donnee(e2) < donnee(e1)) {
            Element* tmp = suivant(e2);
            supprimer_suivant(e2, l2);
            ajouter_apres(e2, e1, l1);
            e2 = tmp;
        } else {
            e1 = suivant(e1);
        }
    }
    return l1;
}

Liste fusion(Liste* l1, Liste* l2) {
    Element* e1;
    Element* e2;
    Liste l3;
    l3.premier = NULL;
    l3.num = 0;

    e1 = premier(l1);
    e2 = premier(l2);

    while (e1 != NULL && e2 != NULL) {
        if (donnee(e1) < donnee(e2)) {
            ajouter_en_tete(e1, &l3);
            e1 = suivant(e1);
        } else {
            ajouter_en_tete(e2, &l3);
            e2 = suivant(e2);
        }
    }

    while (e1 != NULL) {
        ajouter_en_tete(e1, &l3);
        e1 = suivant(e1);
    }

    while (e2 != NULL) {
        ajouter_en_tete(e2, &l3);
        e2 = suivant(e2);
    }

    return l3;
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