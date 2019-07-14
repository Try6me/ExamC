#include <stdio.h>
#include <stdlib.h>
#include "gestionClient.h"


int main()
{
    int i, choice;

    printf(".______        ___      .__   __.   ______      __    __   _______      _______  _______     _______. \n");
    printf("|   _   \      /   \     |  \ |  |  /  __  \    |  |  |  | |   ____|    /  _____||   ____|   /       |\n");
    printf("|  |_)  |    /  ^  \    |   \|  | |  |  |  |   |  |  |  | |  |__      |  |  __  |  |__     |   (----`\n");
    printf("|   _  <    /  /_\  \   |  . `  | |  |  |  |   |  |  |  | |   __|     |  | |_ | |   __|     \   \    \n");
    printf("|  |_)  |  /  _____  \  |  |\   | |  `--   l -.|  `--l  | |  |____    |  |__| | |  |____.----)   |   \n");
    printf("|______/  /__/     \__\ |__| \__|  \_____\_____\\______/  |_______|    \______| |_______|_______/    \n\n ");


    printf("1/ Create, delete, edit, view account info \n");
    printf("2/ Create, delete, edit, view  bank accounts info\n");
    printf("3/ Make deposit, withdraw or transfer \n");


  while (scanf("%d", &choice) != 1) {
        printf("Select an option ");
    while ((i=getchar()) != '\n' && i != EOF);
  }

    switch (choice)
    {
        case 1:
            Menuclient();
            break;
        case 2:
            gestionCompte();
            break;
        case 3:
            gestionOp();
            break;
        default:
            printf("Saisie incorrecte.\n");
            main();
          break;
    }
    return 0;
}
