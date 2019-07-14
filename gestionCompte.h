#ifndef GESTIONCOMPTE_H_INCLUDED
#define GESTIONCOMPTE_H_INCLUDED
typedef struct
{
    int idcompte;
    int idclient;
    int solde;
    char nom[100];
    char cat[100];
}Compte;

void gestionCompte();
void insertCmptCSV(char nom[100], int idclient, char nomfichier[], int identifiant, int solde);
void ajoutCompte();
void getTaux();
void cmptListe(int idclient, int k);
void detailC(int idcompte);
void afficherCompte();
void suppressionCompte();
Compte SupprimerCompteCSV(int id);
Compte rechercheCompte(int id);
Compte * ChargerComptes();

#endif // GESTIONCOMPTE_H_INCLUDED

