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
int count = 0;

void ajouter() {
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
    
    reservations[count].ref = count;
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
void affichertous() {
    if (count == 0) {
        printf("Aucune reservation disponible.\n");
        Sleep(3000);
        system("cls");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n***************************\n");
        printf(" \nNom du patient :          %s\n", reservations[i].nom);
        printf(" \nPrenom du patient :       %s\n", reservations[i].prenom);
        printf(" \nTelephone du patient :    %s\n", reservations[i].number);
        printf(" \nAge du patient :          %d\n", reservations[i].age);
        printf(" \nStatut de la reservation :%s\n", reservations[i].statut);
        printf(" \nReference unique :        %d\n", reservations[i].ref);
        printf(" \nDate de reservation :     %02d/%02d/%d\n",
               reservations[i].date.jour,
               reservations[i].date.mois,
               reservations[i].date.anne);
               
     }
}
void afficher() {
    int option;
    printf("Entrer le reference du patient que vous voulez afficher : \n");
    scanf("%d", &option);
    for (int i = 0; i < count; i++) {
        if (option == reservations[i].ref) {
            printf("\n******************\n");
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

void modiffier() {
    int option;
    printf("Veuillez entrer la Reference unique: ");
    scanf("%d", &option);
    
    for (int i = 0; i < count; i++) {
        if (reservations[i].ref == option) {
            printf("Veuillez entrer le nouveau nom du patient : \n");
            scanf("%s", reservations[i].nom);
            printf("Veuillez entrer le nouveau prenom du patient : \n");
            scanf("%s", reservations[i].prenom);
            printf("Veuillez entrer le nouveau numero de telephone du patient : \n");
            scanf("%s", reservations[i].number);
            printf("Veuillez entrer le nouveau age du patient : \n");
            scanf("%d", &reservations[i].age);
            printf("Veuillez entrer le nouveau statut de reservation du patient : \n");
            scanf("%s", reservations[i].statut);
            printf("Veuillez entrer le nouveau jour de reservation : \n");
            scanf("%d", &reservations[i].date.jour);
            printf("Veuillez entrer le nouveau mois de reservation : \n");
            scanf("%d", &reservations[i].date.mois);
            printf("Veuillez entrer la nouvelle annee de reservation : \n");
            scanf("%d", &reservations[i].date.anne);
            system("cls");
            return;
        }
    }
    printf("Le reference unique que vous avez entre n'existe pas.\n");
    Sleep(3000);
    system("cls");
}

void suprrimer() {
    int option;
    printf("Veuillez entrer la Reference unique: \n");
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

void recherche() {
    int option;
    printf("Entrer le type de recherche : (par reference : 1 , par nom : 2)\n");
    scanf("%d", &option);
    if (option == 1) {
        afficher();
    } else if (option == 2) {
        char nom[20];
        printf("Veuillez entrer le nom du patient : \n ");
        scanf("%s", nom);
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(reservations[i].nom, nom) == 0) {
                printf(" Nom du patient: %s\n", reservations[i].nom);
                printf(" Prenom du patient: %s\n", reservations[i].prenom);
                printf(" Telephone du patient: %s\n", reservations[i].number);
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
        printf("input invalide\n");
    }
    return;
}
void trier() {
    struct reservation temp;
    int option;
    printf("\nEnter le type du triage : (1- par statut . 2- par nom .\n");
    scanf("%d", &option);
if (option == 1) {
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
    }
    else if (option == 2) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (strcmp(reservations[i].nom, reservations[j].nom) > 0) {
                    temp = reservations[j];
                    reservations[j] = reservations[i];
                    reservations[i] = temp;
                }
            }
        }
        printf("Reservations triees par nom avec succes.\n");
    } 
        else {
        printf("Input invalide\n");
    }
}
void cma() {
    if (count == 0) {
        printf("Aucune reservation disponible pour calculer la moyenne d'age.\n");
        return;
    }

    int somme = 0;
    for (int i = 0; i < count; i++) {
        somme += reservations[i].age;
    }
    float moyenne = (float)somme / count;
    printf("La moyenne d'age des patients ayant reserve est : %.2f ans\n", moyenne);
    Sleep(5000);
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

    strcpy(reservations[count].nom, "fatima");
    strcpy(reservations[count].prenom, "zahra");
    strcpy(reservations[count].number, "0123456780");
    reservations[count].age = 28;
    strcpy(reservations[count].statut, "traite");
    reservations[count].date.jour = 5;
    reservations[count].date.mois = 4;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    strcpy(reservations[count].nom, "ali");
    strcpy(reservations[count].prenom, "bensalem");
    strcpy(reservations[count].number, "0234567891");
    reservations[count].age = 35;
    strcpy(reservations[count].statut, "valide");
    reservations[count].date.jour = 10;
    reservations[count].date.mois = 5;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    strcpy(reservations[count].nom, "noura");
    strcpy(reservations[count].prenom, "elmahfoud");
    strcpy(reservations[count].number, "0345678902");
    reservations[count].age = 22;
    strcpy(reservations[count].statut, "reporte");
    reservations[count].date.jour = 15;
    reservations[count].date.mois = 6;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    strcpy(reservations[count].nom, "hamid");
    strcpy(reservations[count].prenom, "benmohamed");
    strcpy(reservations[count].number, "0456789013");
    reservations[count].age = 50;
    strcpy(reservations[count].statut, "annule");
    reservations[count].date.jour = 20;
    reservations[count].date.mois = 7;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    strcpy(reservations[count].nom, "sarah");
    strcpy(reservations[count].prenom, "benali");
    strcpy(reservations[count].number, "0567890124");
    reservations[count].age = 30;
    strcpy(reservations[count].statut, "valide");
    reservations[count].date.jour = 25;
    reservations[count].date.mois = 8;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    strcpy(reservations[count].nom, "youssef");
    strcpy(reservations[count].prenom, "benhamid");
    strcpy(reservations[count].number, "0678901235");
    reservations[count].age = 45;
    strcpy(reservations[count].statut, "traite");
    reservations[count].date.jour = 30;
    reservations[count].date.mois = 9;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    strcpy(reservations[count].nom, "laila");
    strcpy(reservations[count].prenom, "benhassan");
    strcpy(reservations[count].number, "0789012346");
    reservations[count].age = 29;
    strcpy(reservations[count].statut, "reporte");
    reservations[count].date.jour = 2;
    reservations[count].date.mois = 10;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    strcpy(reservations[count].nom, "karim");
    strcpy(reservations[count].prenom, "benali");
    strcpy(reservations[count].number, "0890123457");
    reservations[count].age = 38;
    strcpy(reservations[count].statut, "valide");
    reservations[count].date.jour = 12;
    reservations[count].date.mois = 11;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    strcpy(reservations[count].nom, "najwa");
    strcpy(reservations[count].prenom, "elhaddad");
    strcpy(reservations[count].number, "0901234568");
    reservations[count].age = 32;
    strcpy(reservations[count].statut, "annule");
    reservations[count].date.jour = 18;
    reservations[count].date.mois = 12;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    strcpy(reservations[count].nom, "dibt");
    strcpy(reservations[count].prenom, "chakib");
    strcpy(reservations[count].number, "00254558");
    reservations[count].age = 32;
    strcpy(reservations[count].statut, "annule");
    reservations[count].date.jour = 18;
    reservations[count].date.mois = 12;
    reservations[count].date.anne = 2024;
    reservations[count].ref = ++count;

    do {
        printf("\n 1. Ajouter une reservation \n");
        printf(" 2. Afficher tous les reservation\n");
        printf(" 3. Afficher une reservation\n");
        printf(" 4. Modifier une reservation\n");
        printf(" 5. Supprimer une reservation\n");
        printf(" 6. Rechercher une reservation\n");
        printf(" 7. Trier tous les reservation\n");
        printf(" 8. Calculer le moyen d age\n");
        printf(" 9. Quitter\n");
        printf("\n Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ajouter();
                break;
            case 2:
                affichertous();
                break;
            case 3:
                afficher();
                break;
            case 4:
                modiffier();
                break;
            case 5:
                suprrimer();
                break;
            case 6:
                recherche();
                break;
            case 7:
                trier();
                break;
            case 8:
                cma();
                break;
            case 9:
                printf("Merci et au revoir!\n");
                return 0;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                Sleep(3000);
                system("cls");
        }
    } while (choice != 9);

    return 0; }