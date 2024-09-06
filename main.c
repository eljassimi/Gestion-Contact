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
int r=-1;


int rechercheContact(char name[]){
        for(int i=0;i<c;i++){
        r = strcmp(name,Contact[i].Nom);
        if(r==0){
            return r;
        }
}
return r;

}
int rechercheIndiceContact(char name[]){
    int i=-1;
        for(i=0;i<c;i++){
        if(strcmp(name,Contact[i].Nom)==0){
            return i;
        }

}
return i;

}
void Afficher_un_Contact(char nom[]){
    int indice=rechercheIndiceContact(nom);
   if(indice != -1){
       printf("Les informations du contact %d : \n", indice + 1);
       printf("Nom : %s \n", Contact[indice].Nom);
       printf("Telephone : %s \n", Contact[indice].tele);
       printf("Email : %s \n", Contact[indice].email);
   }
   else{
     printf("Contact introuvable\n");
   }
}
void ajouter_contact(char name[]) {
    int l;
     while(rechercheContact(name)==0){
        printf("ce nom existe dans memoire.\n ajouter un diffirent nom :\n");
        scanf("%s",name);
        }
        strcpy(Contact[c].Nom,name);
        printf("Entrer le numero de tele\n");
        scanf("%s", Contact[c].tele);
        printf("Entrer l email : \n");
        scanf("%s", Contact[c].email);
        c++;
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
    if(rechercheContact(nom)==0){
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
}
void afficher_tous_contact() {
    if (c == 0) {
        printf("Aucun contact dans la mémoire :\n");
    }

    else {
         printf("Les informations du contacts %d : \n");
        for (int i = 0; i < c; i++) {
                char nom[20];
                strcpy(nom, Contact[i].Nom);
             Afficher_un_Contact(nom);
             printf("\n=========================\n");
        }
    }
}

void recherche_contact(char nom[]) {
    if(rechercheContact(nom)==0){
    for (int i = 0; i < c; i++) {
            printf("contact trouve \n");
            printf("Les informations du contact : \n");
            printf("Nom : %s \n", Contact[i].Nom);
            printf("Telephone : %s \n", Contact[i].tele);
            printf("Email : %s \n", Contact[i].email);
            return;

          }


    }
    printf("Le nom que vous avez saisi n'est pas disponible dans la memoire.\n");
}

void supprimer_contact(char nom[]) {
    if(rechercheIndiceContact(nom)==-1){
        printf("Le contact n'existe pas.\n");
    }
    else{
            int index = rechercheIndiceContact(nom);
        for (int i = index; i < c - 1; i++) {
            Contact[i] = Contact[i + 1];
    }
    c--;
}
}
/*void supprimer_contact(char nom[]) {
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
}*/

int main() {
    int choix;
    char nom[20];
    char name[20];
    do {
        printf("\n===================================\n");
        printf("1- Ajouter un Contact \n");
        printf("2- Modifier un Contact\n");
        printf("3- Rechercher un Contact\n");
        printf("4- Afficher les Contacts\n");
        printf("5- Afficher un seul Contact\n");
        printf("6- Supprimer un Contact\n");
        printf("0- Quitter\n");
        printf("===================================\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Entrer le nom du contact\n");
                scanf("%s",name);
                ajouter_contact(name);
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
                Afficher_un_Contact(nom);
                break;
            case 6 :
                printf("Entrer le nom du contact\n");
                scanf("%s", nom);
                supprimer_contact(nom);

        }
    } while (choix != 0);
    return 0;
}
