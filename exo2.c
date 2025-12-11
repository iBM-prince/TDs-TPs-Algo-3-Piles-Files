#include<stdio.h>
#include<stdlib.h>


typedef struct Element {
    int valeur;
    struct Element *suivant;
} Element;

typedef struct Pile {
    Element *sommet;
} Pile;


Pile *initialisation() {
    Pile *p = malloc(sizeof(Pile));
    p->sommet = NULL;
    return p;
}

void empiler(Pile *p, int x) {
    Element *nouveau = malloc(sizeof(Element));
    nouveau->valeur = x;
    nouveau->suivant = p->sommet;
    p->sommet = nouveau;
}

int depiler(Pile *p) {
    int val = -1;
    if (p->sommet == NULL)
        return -1;

    Element *todelete = p->sommet;
    val = todelete->valeur;

    p->sommet = p->sommet->suivant;
    free(todelete);

    return val;
}

//EXERCICE 1 : INVERSER UNE PILE
int inverserPile(Pile *p){
    Pile *temp = initialisation();

    while(p->sommet != NULL){
        empiler(temp, depiler(p));
    }
    p->sommet = temp->sommet;
    return 0;

}

//EXERCICE 4 : ENTIER  BINAIRE AVEC UNE PILE
void enBinaire(int n) {
    Pile *p = initialisation();

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        empiler(p, n % 2);
        n /= 2;
    }

    while (p->sommet != NULL)
        printf("%d", depiler(p));

}

// EXERCICE 5 : INVERSER UNE CHAÎNE AVEC UNE PILE

void inverserChaine(char *texte) {
    Pile *p = initialisation();
    int i = 0;

    while (texte[i] != '\0') {
        empiler(p, texte[i]);
        i++;
    }

    i = 0;
    while (p->sommet != NULL) {
        texte[i] = depiler(p);
        i++;
    }
    texte[i] = '\0';
}

//EXERCICE 6 : HTML SIMPLE BIEN OUVERT/FERMÉ

int htmlok(char *html) {
    Pile *p = initialisation();

    for (int i = 0; html[i] != '\0'; i++) {

        if (html[i] == '<') {
            i++;

            int fermeture = 0;

            if (html[i] == '/') {
                fermeture = 1;
                i++;
            }

            char nom = html[i]; 

            while (html[i] != '>') i++;

            if (fermeture == 0)
                empiler(p, nom);
            else {
                if (p->sommet == NULL) return 0;
                if (depiler(p) != nom) return 0;
            }
        }
    }

    return p->sommet == NULL;
}


int main(){
    Pile *p = initialisation();
    empiler(p, 10);
    empiler(p, 20);
    empiler(p, 30);
    inverserPile(p);

    printf("Pile inversée:\n");
    while(p->sommet != NULL){
        printf("%d\n", depiler(p));

    }
   
    
   
    printf("Nombre 13 en binaire : ");
    enBinaire(13);
    printf("\n");
    char texte[] = "Bonjour le monde!";
    inverserChaine(texte);
    printf("Texte inversé : %s\n", texte);
    char html1[] = "<html><body><h1>Titre</h1></body></html>";
    char html2[] = "<html><body><h1>Titre</body></html>";
    printf("HTML1 est %s\n", htmlok(html1) ? "valide" : "invalide");
    printf("HTML2 est %s\n", htmlok(html2) ? "valide" : "invalide");
    return 0;   
   
}