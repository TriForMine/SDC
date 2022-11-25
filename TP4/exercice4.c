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

int main(void) {
    return 0;
}