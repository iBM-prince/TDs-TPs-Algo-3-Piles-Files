#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct Client {
    int numcompte;
    char nom[50];
    char prenom[50];
    float solde;
    struct Client *suivant;
} Client;

typedef struct File {
    Client *sommet;  
    Client *queue;   
} File;

File *initialisation(){
    File *f = malloc(sizeof(File));

    if(f == NULL){
        exit(EXIT_FAILURE);
    }
    f->sommet = NULL;
    f->queue = NULL;
    return f;
}

void enfiler(File *f, int numcompte, char nom[], char prenom[], float solde){
    Client *nouveau = (Client*)malloc(sizeof(Client));
    if(nouveau == NULL){
        exit(EXIT_FAILURE);
    }
    nouveau->numcompte = numcompte;
    strcpy(nouveau->nom, nom);
    strcpy(nouveau->prenom, prenom);
    nouveau->solde = solde;
    nouveau->suivant = NULL;

    if(f->queue == NULL){
        f->sommet = f->queue = nouveau;
    
    }else{
        f->queue ->suivant = nouveau;
        f->queue = nouveau;

    }


}

int defiler(File *f){
    int val = -1;
    if(f->sommet == NULL){
        printf("La file est vide\n");
        return -1;
    }
    Client *todelete = f->sommet;
    val = todelete->numcompte;
    f->sommet = f->sommet->suivant;
    if(f->sommet == NULL){
        f->queue = NULL;
    }
    free(todelete);
    return val;


}

void afficher(File *f){
    Client *temp = f->sommet;

    printf("File: ");

    while(temp != NULL){
        printf("Compte: %d, Nom: %s, Prénom: %s, Solde: %.2f -> ", temp->numcompte, temp->nom, temp->prenom, temp->solde);
        temp = temp->suivant;

    }
    printf("NULL\n");

}
int main(){
    File *f = initialisation();

    enfiler(f, 101, "Ibrahima", "Diallo", 25000.50);
    enfiler(f, 102, "Awa", "Sow", 15000.75);
    enfiler(f, 103, "Mamadou", "Ba", 30000.00); 
    afficher(f);

    printf("Servir le client avec le compte numéro: %d\n", defiler(f));
    afficher(f);

    
    printf("Clients en attente:\n");
    afficher(f);
 


    return 0;


}