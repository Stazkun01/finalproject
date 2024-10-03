#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct reservationdate {
    int jour;
    int mois;
    int anne;
};

struct reservation {
    int ref;
    char nom[20];
    char prenom[20];
    char number[20];
    int age;
    char statut[20];
    struct reservationdate date;
};

struct reservation reservations[100];
int count = 10;

void ajout() {
    if (count >= 100) {
        printf("Limite de reservations atteinte!\n");
        return;
    }
    printf("Veuillez entrer le nom du patient : \n");
    scanf("%s", reservations[count].nom);
    printf("Veuillez entrer le prenom du patient : \n");
    scanf("%s", reservations[count].prenom);
    printf("Veuillez entrer le numero de telephone du patient : \n");
    scanf("%s", reservations[count].number);
    printf("Veuillez entrer l'age du patient : \n");
    scanf("%d", &reservations[count].age);
    printf("Veuillez entrer le statut de reservation du patient (valide, reporte, annule, traite): \n");
    scanf("%s", reservations[count].statut);
    
    reservations[count].ref = count + 1;
    printf("Veuillez entrer le jour de reservation du patient : \n");
    scanf("%d", &reservations[count].date.jour);
    printf("Veuillez entrer le mois de reservation du patient : \n");
    scanf("%d", &reservations[count].date.mois);
    printf("Veuillez entrer l'annee de reservation du patient : \n");
    scanf("%d", &reservations[count].date.anne);
    
    count++;
    printf("reservation ajoutee avec succee\n");
    Sleep(3000);
    system("cls");
}
void affichtous() {
    if (count == 0) {
        printf("Aucune reservation disponible.\n");
        Sleep(3000);
        system("cls");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf(" Nom de l'etudiant: %s\n", reservations[i].nom);
        printf(" Prenom de l'etudiant: %s\n", reservations[i].prenom);
        printf(" Telephone de la reservation: %s\n", reservations[i].number);
        printf(" Age : %d\n", reservations[i].age);
        printf(" Statut de la reservation: %s\n", reservations[i].statut);
        printf(" Reference unique: %d\n", reservations[i].ref);
        printf(" Date de reservation: %02d/%02d/%d\n",
               reservations[i].date.jour,
               reservations[i].date.mois,
               reservations[i].date.anne);
               
     }
}
void affich() {
    int option;
    printf("Entrer le reference du patient que vous voulez afficher : \n");
    scanf("%d", &option);
    for (int i = 0; i < count; i++) {
        if (option == reservations[i].ref) {
            printf(" Nom de l'etudiant: %s\n", reservations[i].nom);
            printf(" Prenom de l'etudiant: %s\n", reservations[i].prenom);
            printf(" Telephone de la reservation: %s\n", reservations[i].number);
            printf(" Age : %d\n", reservations[i].age);
            printf(" Statut de la reservation: %s\n", reservations[i].statut);
            printf(" Reference unique: %d\n", reservations[i].ref);
            printf(" Date de reservation: %02d/%02d/%d\n",
                   reservations[i].date.jour,
                   reservations[i].date.mois,
                   reservations[i].date.anne);
            return;
        }
    }
    printf("Aucune reservation trouvee!\n");
    Sleep(3000);
    system("cls");
}

void modiff() {
    int option;
    printf("Veuillez entrer la Reference unique: ");
    scanf("%d", &option);
    
    for (int i = 0; i < count; i++) {
        if (reservations[i].ref == option) {
            printf("Veuillez entrer le nom du patient : \n");
            scanf("%s", reservations[i].nom);
            printf("Veuillez entrer le prenom du patient : \n");
            scanf("%s", reservations[i].prenom);
            printf("Veuillez entrer le numero de telephone du patient : \n");
            scanf("%s", reservations[i].number);
            printf("Veuillez entrer l'age du patient : \n");
            scanf("%d", &reservations[i].age);
            printf("Veuillez entrer le statut de reservation du patient : \n");
            scanf("%s", reservations[i].statut);
            printf("Veuillez entrer le jour de reservation : \n");
            scanf("%d", &reservations[i].date.jour);
            printf("Veuillez entrer le mois de reservation : \n");
            scanf("%d", &reservations[i].date.mois);
            printf("Veuillez entrer l'annee de reservation : \n");
            scanf("%d", &reservations[i].date.anne);
            system("cls");
            return;
        }
    }
    printf("Le reference unique que vous avez entre n'existe pas.\n");
    Sleep(3000);
    system("cls");
}

void suprr() {
    int option;
    printf("Veuillez entrer la Reference unique: ");
    scanf("%d", &option);
    
    for (int i = 0; i < count; i++) {
        if (reservations[i].ref == option) {
            for (int j = i; j < count - 1; j++) {
                reservations[j] = reservations[j + 1];
            }
            count--;
            printf("Reservation supprimee avec succes.\n");
            Sleep(3000);
            system("cls");
            return;
        }
    }
    printf("Le reference unique que vous avez entre n'existe pas.\n");
    Sleep(3000);
    system("cls");
}

void rech() {
    int option;
    printf("Entrer le type de recherche : (par reference : 1 , par nom : 2)");
    scanf("%d", &option);
    if (option == 1) {
        affich();
    } else if (option == 2) {
        char nom[20];
        printf("Veuillez entrer le nom du patient : ");
        scanf("%s", nom);
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(reservations[i].nom, nom) == 0) {
                printf(" Nom de l'etudiant: %s\n", reservations[i].nom);
                printf(" Prenom de l'etudiant: %s\n", reservations[i].prenom);
                printf(" Telephone de la reservation: %s\n", reservations[i].number);
                printf(" Age : %d\n", reservations[i].age);
                printf(" Statut de la reservation: %s\n", reservations[i].statut);
                printf(" Reference unique: %d\n", reservations[i].ref);
                printf(" Date de reservation: %02d/%02d/%d\n",
                       reservations[i].date.jour,
                       reservations[i].date.mois,
                       reservations[i].date.anne);
                found = 1;
            }
        }
        if (!found) {
            printf("Aucune reservation trouvee pour le nom %s!\n", nom);
        }
    } else {
        printf("input invalide");
    }
    return;
}

void trierparstatut() {
    struct reservation temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(reservations[i].statut, reservations[j].statut) > 0) {
                temp = reservations[j];
                reservations[j] = reservations[i];
                reservations[i] = temp;
            }
        }
    }
    printf("Reservations triees par statut avec succes.\n");
    Sleep(3000);
    system("cls");
}

int main() {
    int choice;
    strcpy(reservations[count].nom, "dahmad");
    strcpy(reservations[count].prenom, "beneisa");
    strcpy(reservations[count].number, "0123456789");
    reservations[count].age = 30;
    strcpy(reservations[count].statut, "valide");
    reservations[count].date.jour = 10;
    reservations[count].date.mois = 1;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    do {
        printf("1. Ajouter une reservation\n");
        printf("2. Afficher tous les reservation\n");
        printf("3. Modifier une reservation\n");
        printf("4. Supprimer une reservation\n");
        printf("5. rechercher une reservation\n");
        printf("6. Trier par statut\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ajout();
            case 2:
                affichtous();
                break;
            case 3:
                affich();
                break;
            case 4:
                modiff();
                break;
            case 5:
                suprr();
                break;
            case 6:
                rech();
                break;
            case 7:
                trierparstatut();
                break;
            case 8:
                printf("Merci et au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                system("cls");
        }
    } while (choice != 7);

    return 0;
}
