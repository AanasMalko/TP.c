#include <stdio.h>
#include <stdlib.h>

typedef struct noeud {
    int valeur;
    struct noeud *suivant;
} noeud;

noeud *cree(int _valeur) {
    noeud *nouveau = (noeud*)malloc(sizeof(noeud));
    nouveau->valeur = _valeur;
    nouveau->suivant = NULL;
    return nouveau;
}

void afficher(noeud *debut) {
    noeud *ptr = debut;
    if (debut == NULL) {
        printf("La liste est vide\n");
    } else {
        while (ptr != NULL) {
            printf("Valeur : %d\n", ptr->valeur);
            ptr = ptr->suivant;
        }
    }
}

noeud *ajouterD(noeud *debut, int _valeur) {
    noeud *nouveau = cree(_valeur);
    nouveau->suivant = debut;
    return nouveau;
}

noeud *ajouterF(noeud *debut, int _valeur) {
    noeud *nouveau = cree(_valeur);
    if (debut == NULL) {
        return nouveau;
    }
    noeud *ptr = debut;
    while (ptr->suivant != NULL) {
        ptr = ptr->suivant;
    }
    ptr->suivant = nouveau;
    return debut;
}

int taille(noeud *debut) {
    int cmp = 0;
    noeud *ptr = debut;
    while (ptr != NULL) {
        cmp++;
        ptr = ptr->suivant;
    }
    return cmp;
}

noeud *insertion(noeud *debut, int pos, int _valeur) {
    if (pos < 1 || pos > taille(debut) + 1) {
        printf("Position invalide\n");
        return debut;
    }
    if (pos == 1) {
        return ajouterD(debut, _valeur);
    }
    noeud *nouveau = cree(_valeur);
    noeud *ptr = debut;
    for (int i = 1; i < pos - 1; i++) {
        ptr = ptr->suivant;
    }
    nouveau->suivant = ptr->suivant;
    ptr->suivant = nouveau;
    return debut;
}

void rechercher(noeud *debut, int _valeur) {
    noeud *ptr = debut;
    int position = 1;
    while (ptr != NULL) {
        if (ptr->valeur == _valeur) {
            printf("Valeur trouvee à la position %d.\n", position);
            return;
        }
        ptr = ptr->suivant;
        position++;
    }
    printf("Valeur non trouvee dans la liste.\n");
}

noeud *supprimerDEBUT(noeud *debut) {
    if (debut == NULL) {
        printf("La liste est vide.\n");
        return NULL;
    }
    noeud *ptr = debut;
    debut = debut->suivant;
    free(ptr);
    return debut;
}

noeud *supprimerFIN(noeud *debut) {
    if (debut == NULL) {
        printf("La liste est vide.\n");
        return NULL;
    }
    if (debut->suivant == NULL) {
        free(debut);
        return NULL;
    }
    noeud *ptr = debut;
    while (ptr->suivant->suivant != NULL) {
        ptr = ptr->suivant;
    }
    free(ptr->suivant);
    ptr->suivant = NULL;
    return debut;
}

noeud *supprimerPOS(noeud *debut, int pos) {
    if (debut == NULL) {
        printf("La liste est vide\n");
        return NULL;
    }
    int size = taille(debut);
    if (pos < 1 || pos > size) {
        printf("Position invalide.\n");
        return debut;
    }
    if (pos == 1) {
        return supprimerDEBUT(debut);
    }
    noeud *courant = debut;
    noeud *precedent = NULL;
    for (int i = 1; i < pos; i++) {
        precedent = courant;
        courant = courant->suivant;
    }
    precedent->suivant = courant->suivant;
    free(courant);
    return debut;
}

noeud *modifierD(noeud *debut, int _valeur) {
    if (debut == NULL) {
        printf("La liste est vide.\n");
        return NULL;
    }
    debut->valeur = _valeur;
    return debut;
}

noeud *modifierF(noeud *debut, int _valeur) {
    if (debut == NULL) {
        printf("La liste est vide.\n");
        return NULL;
    }
    noeud *ptr = debut;
    while (ptr->suivant != NULL) {
        ptr = ptr->suivant;
    }
    ptr->valeur = _valeur;
    return debut;
}

noeud *modifierP(noeud *debut, int pos, int _valeur) {
    if (pos < 1 || pos > taille(debut)) {
        printf("Position invalide.\n");
        return debut;
    }
    noeud *ptr = debut;
    for (int i = 1; i < pos; i++) {
        ptr = ptr->suivant;
    }
    ptr->valeur = _valeur;
    return debut;
}

int main() {
    noeud *liste = NULL;

    liste = ajouterD(liste, 10);
    liste = ajouterD(liste, 20);
    liste = ajouterF(liste, 30);
    return 0;
}
