#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nom[20];
    char tele[20];
    char email[30];
} contact;

contact Contact[1000];
int c = 0;
void ajouter_contact() {
    int l;
    do {

        printf("Entrer le nom du contact\n");
        scanf("%s", Contact[c].Nom);
    for(int i=0;i<c;i++){
        while(strcmp(Contact[c].Nom,Contact[i].Nom)==0){
            printf("ce nom existe dans memoire. ajouter un diffirent nom :\n");
            scanf("%s", Contact[c].Nom);
        }

    }
        printf("Entrer le numero de tele\n");
        scanf("%s", Contact[c].tele);
        printf("Entrer l email : \n");
        scanf("%s", Contact[c].email);
        c++;

        printf("Voulez-vous ajouter un autre contact? Appuyez sur 1 pour oui et 2 pour non\n");
        do {
            scanf("%d", &l);
            if (l != 1 && l != 2) {
                printf("Entrée invalide. Appuyez sur 1 pour oui et 2 pour non\n");
            }
        } while (l != 1 && l != 2);

    } while (l == 1);


}



void modifier_contact(char nom[]) {
    char nom_modifier[20];
    char tele_modifier[20];
    char email_modifier[20];
    printf("Entrer le nouveau nom : \n");
    scanf("%s", nom_modifier);
    printf("Entrer le nouveau numéro de telephone : \n");
    scanf("%s", tele_modifier);
    printf("Entrer le nouvel email : \n");
    scanf("%s", email_modifier);
    for (int i = 0; i < c; i++) {
        if (strcmp(Contact[i].Nom, nom) == 0) {
            strcpy(Contact[i].Nom, nom_modifier);
            strcpy(Contact[i].tele, tele_modifier);
            strcpy(Contact[i].email, email_modifier);
            return;
        }
    }
    printf("Le nom que vous avez saisi n'est pas disponible.\n");
}

void afficher_tous_contact() {
    if (c == 0) {
        printf("Aucun contact dans la mémoire :\n");
    } else {
        for (int i = 0; i < c; i++) {
            printf("Les informations du contact %d : \n", i + 1);
            printf("Nom : %s \n", Contact[i].Nom);
            printf("Telephone : %s \n", Contact[i].tele);
            printf("Email : %s \n", Contact[i].email);
        }
    }
}

void recherche_contact(char nom[]) {
    for (int i = 0; i < c; i++) {
        if (strcmp(Contact[i].Nom, nom) == 0) {
            printf("Les informations du contact : \n");
            printf("Nom : %s \n", Contact[i].Nom);
            printf("Telephone : %s \n", Contact[i].tele);
            printf("Email : %s \n", Contact[i].email);

            return;
        }
    }
    printf("Le nom que vous avez saisi n'est pas disponible dans la mémoire.\n");
}

void supprimer_contact(char nom[]) {
    int index = -1;
    for (int i = 0; i < c; i++) {
        if (strcmp(Contact[i].Nom, nom) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < c - 1; i++) {
            Contact[i] = Contact[i + 1];
        }
        c--;
    } else {
        printf("Le contact n'existe pas.\n");
    }
}

int main() {
    int choix;
    char nom[20];
    do {
        printf("\n===================================\n");
        printf("1- Ajouter un Contact \n");
        printf("2- Modifier un Contact\n");
        printf("3- Rechercher un Contact\n");
        printf("4- Afficher les Contacts\n");
        printf("5- Supprimer un Contact\n");
        printf("0- Quitter\n");
        printf("===================================\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouter_contact();
                break;
            case 2:
                printf("Entrer le nom du contact\n");
                scanf("%s", nom);
                modifier_contact(nom);
                break;
            case 3:
                printf("Entrer le nom du contact\n");
                scanf("%s", nom);
                recherche_contact(nom);
                break;
            case 4:
                afficher_tous_contact();
                break;
            case 5:
                printf("Entrer le nom du contact\n");
                scanf("%s", nom);
                supprimer_contact(nom);
                break;
        }
    } while (choix != 0);
    return 0;
}
