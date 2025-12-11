#include<stdio.h>
#include<stdlib.h>



typedef struct Element {
    int valeur;
    struct Element *suivant;
} Element;

typedef struct File {
    Element *sommet; 
    Element *queue;   
} File;




File *initialisation() {
    File *f = malloc(sizeof(File));
    if (f == NULL) exit(EXIT_FAILURE);

    f->sommet = NULL;
    f->queue = NULL;
    return f;
}




void enfiler(File *f, int nombre) {
    Element *nouveau = malloc(sizeof(Element));
    if (nouveau == NULL) exit(EXIT_FAILURE);

    nouveau->valeur = nombre;
    nouveau->suivant = NULL;

    if (f->queue == NULL) {
        f->sommet = f->queue = nouveau;
    } else {
        f->queue->suivant = nouveau;
        f->queue = nouveau;
    }
}




int defiler(File *f) {
    int val = -1;

    if (f->sommet == NULL) {
        printf("La file est vide\n");
        return -1;
    }

    Element *todelete = f->sommet;
    val = todelete->valeur;

    f->sommet = f->sommet->suivant;
    if (f->sommet == NULL)
        f->queue = NULL;

    free(todelete);
    return val;
}




void afficher(File *f) {
    Element *temp = f->sommet;
    printf("File: ");

    while (temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }

    printf("NULL\n");
}


/*---------------- NOMBRE D'ELEMENTS ----------------*/

int Nb_Element(File *f) {
    int compt = 0;
    Element *temp = f->sommet;

    while (temp != NULL) {
        compt++;
        temp = temp->suivant;
    }

    return compt;
}


/*---------------- COMPARER DEUX FILES ----------------*/

int Identique(File *f1, File *f2) {
    Element *v1 = f1->sommet;
    Element *v2 = f2->sommet;

    while (v1 != NULL && v2 != NULL) {
        if (v1->valeur != v2->valeur)
            return 0;

        v1 = v1->suivant;
        v2 = v2->suivant;
    }

    return (v1 == NULL && v2 == NULL);
}


/*---------------- MAIN ----------------*/

int main() {
    File *f1 = initialisation();
    File *f2 = initialisation();

    enfiler(f1, 1);
    enfiler(f1, 2);
    enfiler(f1, 3);
    enfiler(f1, 4);
    enfiler(f1, 5);

    afficher(f1);

    enfiler(f2, 1);
    enfiler(f2, 2);
    enfiler(f2, 3);
    enfiler(f2, 4);
    enfiler(f2, 5);

    afficher(f2);

    if (Identique(f1, f2))
        printf("Les files sont identiques\n");
    else
        printf("Les files sont différentes\n");

    printf("Nombre d'elements : %d\n", Nb_Element(f1));

    printf("Defiler : %d\n", defiler(f1));

    afficher(f1);

    return 0;
}
