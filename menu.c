#include <stdio.h>
#include <stdlib.h>


void stat (int tableau[][]);

int main(void)
{

	printf("::::::::: Menu Gestion des Salles :::::::::\n\n");
	printf("1. Ajouter une salle\n");
	printf("2. Charger une salle à partir d'un fichier\n");
	printf("3. Réserver un ou des sièges\n");
	printf("4. Libérer un ou des sièges\n");
	printf("5. Statistiques des salles\n");

	printf("\r\n");

	int choix=0;



	printf("Veuillez rentrez le chiffre correspondant : ");
	if(scanf("%d", &choix)== 1 || choix == 0)
	{
		switch (choix)
{

case 1:
	printf("Votre choix : Ajouter une salle.\r\n");
	// Ajouter une salle, saisir un nombre de sièges
	
	

	break;

case 2:
	printf("Votre choix : Charger une salle à partir d'un fichier.\r\n");
	// Charger une salle avec un fichier existant, localiser le fichier 
	
	FILE* fichier = NULL;
    int caractereActuel = 0;
 
    fichier = fopen("test.txt", "r");
 
    if (fichier != NULL)
    {	
    	printf("Voici la salle :\n");
        // Boucle de lecture des caractères un à un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
 
        fclose(fichier);
    }
	


	break;
	
	
case 3:
	printf("Votre choix : Réserver un ou des sièges\r\n");
	// Sélection de la salle puis des n° de sieges à réserver
	
	

	break;
	
	
case 4:
	printf("Votre choix : Libérer un ou des sièges.\r\n");
	// Sélection de la salle puis des n° de sieges a liberer
	
	

	break;
	
	
case 5:
	printf("Votre choix : Statistiques des salles.\r\n");
	// Afficher la liste des salles et demander un choix, demander ensuite la stat voulue
	
	
	stat(salle1);

	break;

default: 
	printf("\nMauvaise saisie veuillez recommencer.");
	scanf("%d", &choix);
}
	}
}


void stat (int tableau[][])
{

int v_count = 0;
int tot_count = 0; 
int tableau[taille1][taille2];
int i,j;
float pourcent;

for(i=0 ; i < taille1 ; i++)
{               
      for(j=0 ; j < taille2 ; j++)
      {         
			v_count = v_count + 1;
			tot_count = tot_count + 1;
	  }
}
	
pourcent = 100-((v_count/tot_count)*100);

printf("Le nombre de siège total est : %d", tot_count);
printf("Le nombre de siège vide est : %d", v_count);
printf("Les sièges sont occupés à %f %", pourcent);

}
