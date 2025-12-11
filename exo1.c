#include <stdio.h>
#include <stdlib.h>

typededef struct Elements Elements;

typedef struct Elements {
    int valeur;
    struct Elements *suivant;
} Elements;

typedef struct Pile Pile;
typedef struct Pile {
    Elements *sommet;
} Pile;



Pile *initialisation()
{
    Pile *p = malloc(sizeof(Pile));

    if (p == NULL)
    {
        printf("Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }

    p->sommet = NULL;
    return p;
}




void empiler(Pile *pile, int nombre)
{
    Elements *nouveau = malloc(sizeof(Elements));

    if (nouveau == NULL)
    {
        printf("Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }

    nouveau->valeur = nombre;
    nouveau->suivant = pile->sommet;
    pile->sommet = nouveau;
}




int depiler(Pile *pile)
{
    int val = -1;
    if (pile == NULL || pile->sommet == NULL)
    {
        printf("La pile est vide\n");
        return -1;
    }

    Elements *toDelete = pile->sommet;
    val = toDelete->valeur;

    pile->sommet = toDelete->suivant;
    free(toDelete);

    return val;
}




void affichage(Pile *pile)
{
    Elements *temp = pile->sommet;

    printf("Sommet -> ");

    while (temp != NULL)
    {
        printf("[%d] -> ", temp->valeur);
        temp = temp->suivant;
    }

    printf("NULL\n");
}




int Nb_Element(Pile *pile)
{
    int compt = 0;
    Elements *temp = pile->sommet;

    while (temp != NULL)
    {
        compt++;
        temp = temp->suivant;
    }

    return compt;
}




int Identique(Pile *p1, Pile *p2)
{
    Elements *v1 = p1->sommet;
    Elements *v2 = p2->sommet;

    while (v1 != NULL && v2 != NULL)
    {
        if (v1->valeur != v2->valeur)
            return 0;  

        v1 = v1->suivant;
        v2 = v2->suivant;
    }

   
    if (v1 == NULL && v2 == NULL)
        return 1;

    return 0;
}




int main()
{
    Pile *pile1 = initialisation();
    Pile *pile2 = initialisation();
    Pile *pile3 = initialisation();

    empiler(pile1, 1);
    empiler(pile1, 2);
    empiler(pile1, 3);
    empiler(pile1, 4);
    empiler(pile1, 5);

    affichage(pile1);



    empiler(pile2, 6);
    empiler(pile2, 7);
    empiler(pile2, 4);
    empiler(pile2, 8);
    empiler(pile2, 9);

    empiler(pile3, 6);
    empiler(pile3, 7);
    empiler(pile3, 4);
    empiler(pile3, 8);
    empiler(pile3, 9);

    affichage(pile2);
    if (Identique(pile2, pile3))
        printf("Les piles sont identiques\n");
    else
        printf("Les piles sont differentes\n");

    printf("Nombre d'elements : %d\n", Nb_Element(pile1));
    

    printf("Depiler : %d\n", depiler(pile1));

    affichage(pile1);

    return 0;
}