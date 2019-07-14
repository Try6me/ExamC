#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestionClient.h"
#include "gestionCompte.h"


void gestionCompte()
{
    int choice;
    printf("Gestion de comptes : \n\n");
    printf("1/ Créer un compte\n");
    printf("2/ Consulter vos comptes\n");
    printf("3/ Supprimer un compte\n");


  while (scanf("%d", &choice) != 1) {
        printf("Saisir choix ");

    int c;
    while ((c=getchar()) != '\n' && c != EOF);
  }

    switch (choice)
    {
        case 1:
            ajoutCompte();
            break;
        case 2:
            affichageCompte();
            break;
        case 3:
            suppressionCompte();
            break;
        default:
            printf("Saisie incorrecte");
            gestionCompte();
          break;
    }
}

void affichageCompte()
{
    int idclient, idcompte;
    int choix = 0; // ID Client
    char nom[100];
    char categorie[100];
    int res = 0;
    int i = 0;

    printf("\n -- Menu Consultation de comptes --\n\n");

    printf("Saisir nom :\n");
    scanf("%s", nom);
    printf("%s, saisir l'identifiant :\n",nom);


  while (scanf("%d", &idclient) != 1) {
        printf("%s, saisir votre identifiant :\n",nom);
    while ((i=getchar()) != '\n' && i != EOF);
  }
    printf("%s vous avez saisi l'identifiant : %d \n\n",nom,idclient);

    printf("Voici l'ensemble des comptes liés a votre ID Client :");
    cmptListe(idclient,0);

    printf("Affichage detaillee de tout les comptes (2) ou seulement dun seul compte (1) ?\n");

  while (scanf("%d", &choix) != 1) {
        printf("Affichage de tous les comptes (2) ou un seul compte (1) ?\n");
    while ((i=getchar()) != '\n' && i != EOF);
  }

        if(choix == 1)
        {
        printf("Saisir l'identifiant du compte concerne : \n");
            while (scanf("%d", &idcompte) != 1) {
                printf("Saisir l'identifiant du compte concerne : ");

                while ((i=getchar()) != '\n' && i != EOF);
            }
        detailC(idcompte);
        }
        if(choix == 2)
        {
        cmptListe(idclient,1);
        }

   printf("\n Revenir au menu principal ? \n");
   printf("- 1 Oui\n");
   printf("- 2 Non\n");

  while (scanf("%d", &res) != 1) {
        printf("Souhaitez-vous revenir au menu principal ? \n");

    while ((i=getchar()) != '\n' && i != EOF);
  }

   if(res == 1)
   {
    main();
   }

}

void insertCmptCSV(char nom[100], int idclient, char nomfichier[], int identifiant, int solde_int)
{
    FILE *file;

    char separateur [] = ";"; //separateur dans le fichier
    char solde[100];
    file = fopen (nomfichier, "a+");

    char idcl[100];
    char idcompte[100];

    if (file != NULL)
    {
    itoa(solde_int, solde, 10); // function in C language converts int data type to string data type
        itoa(idcl, idcl, 10);
        itoa(identifiant, idcompte, 10);

        //concaténation de chaines
        strcat(nom, separateur);
        strcat(nom, idcompte);
        strcat(nom, separateur);
        strcat(nom, solde);

        strcat(nom, separateur);
        strcat(nom, idcl);
        strcat(nom, separateur);
        fputs(nom, file);
        fputs("\n", file);

        fclose(file);
    }
    else
    {printf("Impossible d'ouvrir le fichier");}
}

void ajoutCompte()
{
char nom [100];
int id = 0 ;
int res = 0;
int choice;
char categorie[100];
int identifiant = 0;
int solde = 0;
int c = 0;

    printf("Ajout de compte\n\n");

    printf("Saisir votre nom:\n");
    scanf("%s", nom);
    Client client1;

     do{
        printf("%s, Saisir votre identifiant\n",nom);
        while (scanf("%d", &id) != 1) {
            printf("%s, Saisir votre identifiant\n",nom);
            while ((c=getchar()) != '\n' && c != EOF);
        }

        printf("%s vous avez saisi l'identifiant suivant : %d \n\n",nom,id);

        client1 = searchClient(id);
    }while(choice != 1 || client1.id == 0);


    identifiant = GenererId();

   insertCmptCSV(nom, id, "compte.csv", identifiant, solde);

   printf("\n Compte créé\n");

   printf("\n Revenir menu ? \n");
   printf("1 Y\n");
   printf("2 N\n");
   scanf("%d", &res);

   if(res == 1)
   {
    main();
   }

}

void suppressionCompte()
{
    int id;
    int retour = 0;
    int c = 0;
    printf("\n Veuillez saisir l'identifiant du compte : ");


  while (scanf("%d", &id) != 1) {
        printf("Veuillez saisir l'identifiant du compte : ");
    int c;
    while ((c=getchar()) != '\n' && c != EOF);
  }
    SupprimerCompteCSV(id);
    printf("\n Operation terminée");

   printf("\n Revenir au menu principal ? \n");
   printf("1 O\n");
   printf("2 N\n");
   scanf("%d", &retour);

   if(retour == 1)
   {
    main();
   }
}

void detailC(int idcompte)
{
    char line[1024];
    char * pch;
    int i,j = 0;

    Compte cmpt2;

    printf("\nDetails du compte %d :\n", idcompte);
    FILE* fichier = fopen("compte.csv", "r");


    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";");

            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        strcpy(cmpt2.nom,pch);
                    case 1:
                        cmpt2.idcompte = atoi(pch);
                    case 2:
                        cmpt2.solde = atoi(pch);
                    case 4:
                        cmpt2.idclient = atoi(pch);

                }
                j++;
                pch = strtok (NULL, ";");
            }

            if(cmpt2.idcompte == idcompte)
            {
                printf("****************\n");
                printf("ID compte: %d\n", cmpt2.idcompte);
                printf("Solde: %d\n", cmpt2.solde);
            }

            free(tmp);
            i++;
            j=0;
        }
    }
    fclose(fichier);

}

Compte SupprimerCompteCSV(int id)
{
   char line[1024];
    char * pch;
    int i = 0;
    int j = 0;
  Compte cmpt;
  Compte deleted;

    FILE * fichier;
    fichier = fopen("compte.csv", "r");

    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";");

            while (pch != NULL)
                {
                    switch(j)
                    {
                        case 0:
                            strcpy(cmpt.nom,pch);
                        case 1:
                            cmpt.idcompte = atoi(pch);
                        case 2:
                            cmpt.solde = atoi(pch);
                        case 4:
                            cmpt.idclient = atoi(pch);

                    }
                j++;
                pch = strtok (NULL, ";");
            }

            if(cmpt.idcompte != id)
            {
                insertCmptCSV(cmpt.nom, cmpt.idclient, "compte_temp.csv", cmpt.idcompte,cmpt.solde);
            }
      else
      {
        deleted = cmpt;
      }
            free(tmp);
            i++;
            j=0;
        }
    }

    fclose(fichier);
    remove("compte.csv");
    rename("compte_temp.csv", "compte.csv");
  return deleted;
}

void cmptListe(int idclient, int k)
{
    char line[1024];
    char * pch;
    int i,j = 0;

    Compte cmpt1;

    printf("\nComptes avec votre ID Client (%d) :\n", idclient);
    FILE* fichier = fopen("compte.csv", "r");

    if(fichier != NULL)
    {while (fgets(line, 1024, fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";");

            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        strcpy(cmpt1.nom,pch);
                    case 1:
                        cmpt1.idcompte = atoi(pch);
                    case 2:
                        cmpt1.solde = atoi(pch);
                    case 4:
                        cmpt1.idclient = atoi(pch);

                }
                j++;
                pch = strtok (NULL, ";");
            }

            if(cmpt1.idclient == idclient && k == 0)
            {
                printf("****************\n");
                printf("ID Compte: %d\n", cmpt1.idcompte);
            }

            if(cmpt1.idclient == idclient && k == 1)
            {
                printf("****************\n");
                printf("ID du compte: %d\n", cmpt1.idcompte);
                printf("Le solde est de: %d\n", cmpt1.solde);}

            free(tmp);
            i++;
            j=0;
        }
    }
    fclose(fichier);

}

Compte rechercheCompte(int id)
{
    char line[1024];
    char * pch;
    int i,j = 0;
    Compte cmpt;

    FILE* fichier = fopen("compte.csv", "r");
    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";");
            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        strcpy(cmpt.nom,pch);
                    case 1:
                        cmpt.idcompte = atoi(pch); //transforme string en int si possible sinon renvoie 0
                    case 2:
                        cmpt.solde = atoi(pch);
                    case 4:
                        cmpt.idclient = atoi(pch);
                }
                j++;
                pch = strtok (NULL, ";");
            }

            if(cmpt.idcompte == id)
            {
                fclose(fichier);
                return cmpt;
            }

            free(tmp);
            i++;
            j=0;
        }
    }

    fclose(fichier);
    strcpy(cmpt.nom,"0");
    cmpt.idcompte = 0;
    cmpt.solde = 0;
    cmpt.idclient = 0;
    return cmpt;
}

Compte * chargementCmpt()
{
    char line[1024];
    char * pch;
    int i,j,k = 0;
    Compte cmpt1;
    Compte * lesComptes = malloc(countLineInFile("compte.csv") * sizeof(Compte)); //remplacer 100 par le nombre de ligne dans le fichier, soit le nb de clients

    FILE* fichier = fopen("compte.csv", "r");
    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";"); //The C library function strtok breaks string str into a series of tokens using the delimiter delim.



            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        strcpy(cmpt1.nom,pch);
                    case 1:
                        cmpt1.idcompte = atoi(pch);
                    case 2:
                        cmpt1.solde = atoi(pch);
                    case 4:
                        cmpt1.idclient = atoi(pch);
                }
                j++;
                pch = strtok (NULL, ";");
            }
                lesComptes[k] = cmpt1;
                k++;


            free(tmp);
            i++;
            j=0;
        }
    }
    printf("Taille: %d\n", sizeof(lesComptes));
    fclose(fichier);
    return lesComptes;
}
