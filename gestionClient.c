#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestionClient.h"

Client searchClient(int id)
{
    char line[1024];
    char * pch;
    int i,j = 0;
    Client unClient;

    FILE* fichier = fopen("bddclients.csv", "r");
    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";"); //premiere fois pour trouver le delimiter

            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        unClient.id = atoi(pch);
                    case 1:
                        strcpy(unClient.nom,pch);
                    case 2:
                        strcpy(unClient.prenom,pch);
                    case 3:
                        strcpy(unClient.profession,pch);
                    case 4:
                        strcpy(unClient.telephone,pch);
                }
                j++;
                pch = strtok (NULL, ";");
            }

            if(unClient.id == id)
            {
                fclose(fichier);
                return unClient;
            }

            free(tmp);
            i++;
            j=0;
        }
    }

    fclose(fichier);

    //Si aucun client n'esst trouv�, on met toutes les valeurs de client � 0, pour ne pas retourner le dernier de la liste
    unClient.id = 0;
    strcpy(unClient.nom, "0");
    strcpy(unClient.prenom, "0");
    strcpy(unClient.profession, "0");
    strcpy(unClient.telephone, "0");
    return unClient;
}

void InsererCsv(Client unClient, char nomfichier[], int retourLigne)
{
    char *data;
    data = calloc(500, sizeof(char)); //La m�moire de "data" est "mal n�toy�e" lors des appels, il est mieux d'utilsier un pointeur pour utiliser "free(data)"

    if ( data == NULL )
    {
         fprintf(stderr,"Reallocation impossible");
         free(data);
         exit(EXIT_FAILURE);
    }


    char id[10];
    itoa(unClient.id, id, 10); //conversion de l'id int en char

    strcat(data, id);
    strcat(data, ";");
    strcat(data, unClient.nom);
    strcat(data, ";");
    strcat(data, unClient.prenom);
    strcat(data, ";");
    strcat(data, unClient.profession);
    strcat(data, ";");
    strcat(data, unClient.telephone);

    if(retourLigne == 1)
    {
        strcat(data, "\n");
    }

    FILE* fichier = fopen(nomfichier, "a+");
    if (fichier != NULL)
    {
        fputs(data, fichier);
    }
    fclose(fichier);
    free(data);
}

void SupprClient(int id)
{
    char line[1024];
    char * pch;
    int i = 0;
    int j = 0;
    Client unClient;

    FILE * fichier;
    fichier = fopen("bddclients.csv", "r");

    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";"); //premiere fois pour trouver le delimiter

            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        unClient.id = atoi(pch);
                    case 1:
                        strcpy(unClient.nom,pch);
                    case 2:
                        strcpy(unClient.prenom,pch);
                    case 3:
                        strcpy(unClient.profession,pch);
                    case 4:
                        strcpy(unClient.telephone,pch);
                }
                j++;
                pch = strtok (NULL, ";");
            }

            if(unClient.id != id)
            {
                InsererCsv(unClient, "clients_temp.csv", 0);
            }

            free(tmp);
            i++;
            j=0;
        }
    }
    //ici
    fclose(fichier);
    remove("bddclients.csv");
    rename("clients_temp.csv", "bddclients.csv");
}

void ModifClient(int id)
{
    int choix = 0;
    Client unClient;
    unClient.id = 0;
    int c;

    unClient = searchClient(id);

    if(unClient.id != 0)
    {

        SupprClient(unClient.id);

        printf("Que voulez-vous modifier ?\n");
        printf("(1) pour le nom ?\n");
        printf("(2) pour le prenom ?\n");
        printf("(3) pour le profession ?\n");
        printf("(4) pour le telephone ?\n");

        while (scanf("%d", &choix) != 1) {
            printf("Que voulez-vous modifier ? \n");
            while ((c=getchar()) != '\n' && c != EOF);
        }


        switch(choix)
        {
            case 1:
                printf("Nouveau nom: ");
                scanf("%s", unClient.nom);
                break;
            case 2:
                printf("Nouveau prenom: ");
                scanf("%s", unClient.prenom);
                break;
            case 3:
                printf("Nouveau profession: ");
                scanf("%s", unClient.profession);
                break;
            case 4:
                printf("Nouveau telephone: ");
                scanf("%s", unClient.telephone);
                break;
        }
        InsererCsv(unClient, "bddclients.csv", 0);
    }
    else printf("Aucun client trouve avec l'id [%d]\n", id);

}

int SubStringCompare(char *subString, char *plainString)
{
    int i = 0;
    char *plainStringToSubstring = malloc(strlen(subString) * sizeof(char));

    for(i = 0; i<strlen(subString);i++)
    {
        plainStringToSubstring[i] = plainString[i];
        plainStringToSubstring[i+1] = '\0';
    }

    if (strcmp(subString, plainStringToSubstring) == 0)
    { //comparaison true
        return 1;
    }
    else
    { // nope
        return 0;
    }

    free(plainStringToSubstring);
    return 0;
}

Client * listeClient(char * sousNom)
{
    char line[1024];
    char * pch;
    int i,j,k = 0;
    int nbClient;
    nbClient = 0;
    Client unClient;
    Client * lesClients = malloc(countLineInFile("bddclients.csv") * sizeof(Client));

    FILE* fichier = fopen("bddclients.csv", "r");
    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            char* tmp = strdup(line);
            pch = strtok (tmp,";"); //premiere fois pour trouver le delimiter

            while (pch != NULL)
            {
                switch(j)
                {
                    case 0:
                        unClient.id = atoi(pch);
                    case 1:
                        strcpy(unClient.nom,pch);
                    case 2:
                        strcpy(unClient.prenom,pch);
                    case 3:
                        strcpy(unClient.profession,pch);
                    case 4:
                        strcpy(unClient.telephone,pch);
                }
                j++;
                pch = strtok (NULL, ";");
            }

            if(SubStringCompare(sousNom,unClient.nom) == 1)
            {
                lesClients[k] = unClient;
                nbClient++;
                k++;
            }

            free(tmp);
            i++;
            j=0;
        }
    }

    fclose(fichier);
    printf("Nombre de client trouve: %d\n", nbClient);
    if(nbClient != 0) return lesClients;
    else return 1;
}

void Menuclient()
{
int choix, a;
int c;

    printf("\n******************** Gestion Client: Menu Principal ********************\n");
    printf("1 - Ajouter un client a la base\n");
    printf("2 - Supprimer un client de la base\n");
    printf("3 - Modifier un client de la base\n");
    printf("4 - Consulter les informations d'un client\n");
    printf("5 - Consulter un compte client a partir d'un nom incomplet\n");
    printf("Choix: ");

	while (scanf("%d", &choix) != 1) {
        printf("C'est a vous : ");
		while ((c=getchar()) != '\n' && c != EOF);
	}

    switch (choix)
    {
        case 1:
            MenuAjoutClient();
            break;
        case 2:
            MenuSupprimerClientCSV();
            break;
        case 3:
            modifClient();
            break;
        case 4:
            searchClientMenu();
            break;
        case 5:
            listeClientChar();
            break;
        default:
            printf("!! Votre saisie est incorrecte.\n");
            Menuclient();
          break;
    }
}
int GenererId()
{
    srand(time(NULL));
    int r = rand() % 1000000 + 1;
    Client client1 = searchClient(r);

    if(r == client1.id)
    {
        GenererId();
    }
    return r;
}

void MenuAjoutClient()
{
    Client client2;

    printf("Entrez un nom:\n");
    scanf("%s", client2.nom);

    printf("Entrez un prenom :\n");
    scanf("%s", client2.prenom);

    printf("Entrez une profession :\n");
    scanf("%s", client2.profession);

    printf("Entrez un numero de telephone (10 char):\n");
    scanf("%s", client2.telephone);

    client2.id = GenererId();
    printf("ID client genere: %d\n", client2.id);

    InsererCsv(client2, "bddclients.csv", 1);
}

void searchClientMenu()
{
    Client client1;
    int id = 0;

    printf("Entrez l'ID du client a chercher:\n");

	while (scanf("%d", &id) != 1) {
        printf("Entrez l'ID du client a chercher:\n");
        int c;
		while ((c=getchar()) != '\n' && c != EOF);
	}

    client1 = searchClient(id);

    if(client1.id != 0)
    {
            printf("\nInformations du client ayant l'id: [%d]\n\n", client1.id);
            printf("Nom: %s\n", client1.nom);
            printf("Prenom: %s\n", client1.prenom);
            printf("Métier: %s\n", client1.profession);
            printf("Telephone: %s\n", client1.telephone);
    }
    else printf("Client inexistant\n");
}

void modifClient()
{
    int id = 0;
    int c;
    printf("Entrez l'ID du client a modifier:\n");

    while (scanf("%d", &id) != 1) {
        printf("Entrez l'ID du client a modifier:");

        while ((c=getchar()) != '\n' && c != EOF);
    }

    ModifClient(id);
}

void MenuSupprimerClientCSV()
{
    int id = 0;
    int c;
    printf("ID du client a suppr ?:\n");
	while (scanf("%d", &id) != 1) {
        printf("Entrez l'ID du client a supprimer : ");
		while ((c=getchar()) != '\n' && c != EOF);
	}
    Client unClient = searchClient(id);

    if(unClient.id != 0)
    {
        SupprClient(id);
        printf("Le client avec l'id [%d] et le nom [%s] a ete supprime", id, unClient.nom);
    }
    else
    {
        printf("Aucun client avec l'id [%d]", id);
    }
}

void listeClientChar()
{

        printf("Entrez un debut de nom pour obtenir la liste des clients dont le nom commence par ces caractéres:\n");
        char sousNom[100];
        int i = 0;
        scanf("%s", &sousNom);
        Client * clients = listeClient(sousNom);

        printf("*******************************************\n");
        if(clients == 1) printf("Aucun client trouve\n");
        else
        {
            for(i = 0; i < sizeof(clients); i++)
            {
                    printf("ID: %d\n", clients[i].id);
                    printf("Nom: %s\n", clients[i].nom);
                    printf("Prenom: %s\n", clients[i].prenom);
                    printf("Profession: %s\n", clients[i].profession);
                    printf("Telephone: %s\n", clients[i].telephone);
                    printf("*******************************************\n");
            }
        }
}
