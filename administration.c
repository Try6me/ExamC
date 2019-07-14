#include "gestionCompte.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestionClient.h"
#include <time.h>

int countLineInFile(char * filename)
{
    int count = 0;
    char line[1024];
    FILE* fichier = fopen(filename, "r");
    if(fichier != NULL)
    {
        while (fgets(line, 1024, fichier))
        {
            count++;
        }
    }
    return count;
}

void interetsC()
{
    Compte * cmpt = malloc(countLineInFile("bddcomptes.csv"));
    cmpt = chargementCmpt();
    int nbCompte = countLineInFile("bddcomptes.csv");
    int i = 0;
    float totalSmall = 0;
    float totalMedium = 0;
    float totalBig = 0;
}

int SommeCompte()
{
    Compte * cmpt = malloc(countLineInFile("bddcomptes.csv"));
    cmpt =chargementCmpt();

    int nbCompte = countLineInFile("bddcomptes.csv");
    int i,total = 0;

        for(i=0;i<nbCompte;i++)
        {
            total += cmpt[i].solde;
        }
return total;
}
