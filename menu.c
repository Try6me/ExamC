#include <stdio.h>
#include <stdlib.h>


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
	
	
	

	break;

default: 
	printf("\nMauvaise saisie veuillez recommencer.");
	scanf("%d", &choix);
}
	}
}
