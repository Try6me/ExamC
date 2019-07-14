#include <stdio.h>
#include <stdlib.h>
#include "gestionClient.h"
#include "gestionCompte.h"
#include <Windows.h>


void retrait()
{
    int return_value;
    int montant = 0;
    int id;

    do
    {
        printf("Rentrez votre ID de compte:\n");
        return_value = scanf("%d", &id);
    }while(rechercheCompte(id).idcompte == 0);


    if (return_value == EOF || return_value == 0 || id < 0)
        fprintf(stderr, "id invalid\n");

    printf("Rentrez le montant a retirer:\n");
    return_value = scanf("%d", &montant);
    if (return_value == EOF || return_value == 0 || montant <= 0)
        fprintf(stderr, "montant invalid\n");

    Compte compte = SupprimerCompteCSV(id);
    insertCmptCSV(compte.nom, compte.idclient, "compte.csv", compte.idcompte, compte.solde - montant);
    historique(compte, compte, montant, 2, "historique.csv");
}

void depot()
{
        int retour;
        int montant = 0;
        int id;

            printf("Rentrez votre ID de compte:\n");
            retour = scanf("%d", &id);

        if (retour == EOF || retour == 0 || id < 0)
            fprintf(stderr, "id invalide\n");

        printf("Rentrez le montant a deposer:\n");
        retour = scanf("%d", &montant);
        if (retour == EOF || retour == 0 || montant <= 0)
            fprintf(stderr, "Invalide\n");

        Compte compte = SupprimerCompteCSV(id);
        insertCmptCSV(compte.nom, compte.idclient, "compte.csv", compte.idcompte, compte.solde + montant);

        historique(compte, compte, montant, 1, "historique.csv");
}

void virement()
{
    int retour;
    int montant = 0;
    int cmpt_emetteur;
    int cmpt_dest;

    do
    {
        printf("Rentrez votre ID de compte:\n");
        retour = scanf("%d", &cmpt_emetteur);
    }while(rechercheCompte(cmpt_emetteur).idcompte == 0);

    if (retour == EOF || retour == 0 || cmpt_emetteur < 0)
        fprintf(stderr, "id invalid\n");

    do
    {
        printf("Rentrez l'ID du compte vers qui faire le virement:\n");
        retour = scanf("%d", &cmpt_dest);
    }while(rechercheCompte(cmpt_dest).idcompte == 0);

    if (retour == EOF || retour == 0 || cmpt_dest < 0)
        fprintf(stderr, "id invalid\n");

    printf("Rentrez le montant du virement:\n");
    retour = scanf("%d", &montant);
    if (retour == EOF || retour == 0 || montant <= 0)
        fprintf(stderr, "montant invalid\n");

    Compte compteEmetteur = SupprimerCompteCSV(cmpt_emetteur);
    insertCmptCSV(compteEmetteur.nom, compteEmetteur.idclient, "compte.csv", compteEmetteur.idcompte,
                  compteEmetteur.solde - montant);
    Compte compteDestinataire = SupprimerCompteCSV(cmpt_dest);
    insertCmptCSV(compteDestinataire.nom, compteDestinataire.idclient, "compte.csv", compteDestinataire.idcompte,
                  compteDestinataire.solde + montant);
    historique(compteEmetteur, compteDestinataire, montant, 1, "historique.csv");
}

void gestionOp()
{
    int choix;
    printf("\n******************************************\n");
    printf("Quelle operation souhaitez-vous faire ?\n\n");
    printf("1 - Faire un depot \n");
    printf("2 - Faire un retrait\n");
    printf("3 - Faire un virement\n");

    while (scanf("%d", &choix) != 1) {
        int c;
        while ((c=getchar()) != '\n' && c != EOF);
    }

    switch (choix)
    {
        case 1:
            depot();
            break;
        case 2:
            retrait();
            break;
        case 3:
            virement();
            break;
        default:
            printf("Saisie est invalide");
            gestionOp();
          break;
    }

}


void historique(Compte emetteur, Compte destinataire,int montant, int typeTransaction, char nomfichier[])
{

    SYSTEMTIME str_t;
    GetSystemTime(&str_t);

    FILE *fichier;
    char separateur [] = ";";
    char ligne [1024];
    fichier = fopen (nomfichier, "a+");

    char idEmetteur[10];
    itoa(emetteur.idcompte, idEmetteur, 10);
    char idDestinataire[10];
    itoa(destinataire.idcompte, idDestinataire, 10);
    char montantString[10];
    itoa(montant, montantString, 10);
    char annee[10];
    itoa(str_t.wYear, annee, 10);
    char mois[10];
    itoa(str_t.wMonth, mois, 10);
    char jour[10];
    itoa(str_t.wDay, jour, 10);

    if (fichier != NULL)
    {
        strcat(ligne, idEmetteur);
        strcat(ligne, separateur);
        strcat(ligne, idDestinataire);
        strcat(ligne, separateur);
        strcat(ligne, montantString);
        strcat(ligne, separateur);
        strcat(ligne, annee);
        strcat(ligne, "/");
        strcat(ligne, mois);
        strcat(ligne, "/");
        strcat(ligne, jour);
        strcat(ligne, separateur);
        fputs(ligne, fichier);
        fputs("\n", fichier);

        fclose(fichier);
    }
    else
    {
        printf("Impossible d'ouvrir le fichier");
    }
}
