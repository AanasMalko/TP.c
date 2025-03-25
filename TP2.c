#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Date {
    char jour [3];
    char mois [3];
    char annee [5];
} Date;
typedef struct Produit {
    char Nom_produit [50];
    char Reference[100];
    float Montant;
    Date Date_achat;
} Produit;
typedef struct Liste {
    Produit cellule;
    struct Liste *suivant;
} Liste;
Liste *creer_liste (){
return NULL;
}
int est_vide (Liste *liste){
return liste==NULL;
}
Produit creer_produit (char *nom,char* ref,float montant,char *jour,char *mois,char *annee){
    Produit p;
    strcpy(p.Nom_produit,nom);
    strcpy(p.Reference,ref);
    p.Montant=montant;
    strcpy(p.Date_achat.jour,jour);
    strcpy(p.Date_achat.mois,mois);
    strcpy(p.Date_achat.annee,annee);
    return p;
}
void afficher_produit (Produit p){
    printf("nom du produit : %s\n",p.Nom_produit);
    printf("reference du produit : %s\n",p.Reference);
    printf("montant du produit : %f\n",p.Montant);
    printf("date d'achat du produit : %s/%s/%s\n",p.Date_achat.jour,p.Date_achat.mois,p.Date_achat.annee); 
}
Liste *ajouter_debut (Liste *tete,Produit p){
    Liste *nouveau=(Liste*)malloc(sizeof(Liste));
    nouveau->cellule=p;
    nouveau->suivant=tete;
    return nouveau;
}
Liste *ajouter_fin (Liste *tete,Produit p){
    Liste *nouveau=(Liste*)malloc(sizeof(Liste));
    Liste *courant=tete;
    nouveau->cellule=p;
    nouveau->suivant=NULL;
    if (est_vide(tete)){
        return nouveau;
    }
    while (courant->suivant!=NULL){
        courant=courant->suivant;
    }
    courant->suivant=nouveau;
    return tete;
}
