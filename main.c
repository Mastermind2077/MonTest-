#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Etudiant {
    int matricule;
    char nom[50];
    char prenom[50];
    char sexe;
    int age;
    float note1;
    float note2;
    float note3;
    struct Etudiant *suivant;
} Etudiant;

Etudiant *tete = NULL;

void ajouterEtudiant() {
    Etudiant *nouveau = (Etudiant *)malloc(sizeof(Etudiant));
    printf("Entrez le matricule: ");
    scanf("%d", &nouveau->matricule);
    printf("Entrez le nom: ");
    scanf("%s", nouveau->nom);
    printf("Entrez le prenom: ");
    scanf("%s", nouveau->prenom);
    printf("Entrez le sexe (M/F): ");
    scanf(" %c", &nouveau->sexe);
    printf("Entrez l'age: ");
    scanf("%d", &nouveau->age);
    printf("Entrez la note 1: ");
    scanf("%f", &nouveau->note1);
    printf("Entrez la note 2: ");
    scanf("%f", &nouveau->note2);
    printf("Entrez la note 3: ");
    scanf("%f", &nouveau->note3);
    nouveau->suivant = tete;
    tete = nouveau;
    printf("Etudiant ajoute avec succes!\n");
}

void mettreAJourEtudiant() {
    int matricule;
    printf("Entrez le matricule de l'etudiant a mettre a jour: ");
    scanf("%d", &matricule);
    Etudiant *courant = tete;
    while (courant != NULL) {
        if (courant->matricule == matricule) {
            printf("Entrez le nouveau nom: ");
            scanf("%s", courant->nom);
            printf("Entrez le nouveau prenom: ");
            scanf("%s", courant->prenom);
            printf("Entrez le nouveau sexe (M/F): ");
            scanf(" %c", &courant->sexe);
            printf("Entrez le nouvel age: ");
            scanf("%d", &courant->age);
            printf("Entrez la nouvelle note 1: ");
            scanf("%f", &courant->note1);
            printf("Entrez la nouvelle note 2: ");
            scanf("%f", &courant->note2);
            printf("Entrez la nouvelle note 3: ");
            scanf("%f", &courant->note3);
            printf("Etudiant mis a jour avec succes!\n");
            return;
        }
        courant = courant->suivant;
    }
    printf("Etudiant non trouve.\n");
}

void supprimerEtudiant() {
    int matricule;
    printf("Entrez le matricule de l'etudiant a supprimer: ");
    scanf("%d", &matricule);
    Etudiant *courant = tete;
    Etudiant *precedent = NULL;
    while (courant != NULL) {
        if (courant->matricule == matricule) {
            if (precedent == NULL) {
                tete = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            free(courant);
            printf("Etudiant supprime avec succes!\n");
            return;
        }
        precedent = courant;
        courant = courant->suivant;
    }
    printf("Etudiant non trouve.\n");
}

int main() {
    int choix;
    while (1) {
        printf("\nMenu:\n");
        printf("1 - Ajouter un etudiant\n");
        printf("2 - Mettre a jour un etudiant\n");
        printf("3 - Supprimer un etudiant\n");
        printf("4 - Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouterEtudiant();
                break;
            case 2:
                mettreAJourEtudiant();
                break;
            case 3:
                supprimerEtudiant();
                break;
            case 4:
                printf("Au revoir!\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    }
}
