#ifndef GESTIONOPERATIONS_H_INCLUDED
#define GESTIONOPERATIONS_H_INCLUDED


void gestionOp();
void depot();
void retrait();
void virement();

void historique(Compte emetteur, Compte destinataire,int montant, char nomfichier[]);
#endif // GESTIONOPERATIONS_H_INCLUDED
