#ifndef GESTIONCLIENT_H_INCLUDED
#define GESTIONCLIENT_H_INCLUDED

    typedef struct
    {
        int id;
        char nom[100];
        char prenom[100];
        char profession[200];
        char telephone[10];

    }Client;


    Client searchClient(int id);
    void ModifClient(int id);

    void InsererCsv(Client client1, char nomfichier[], int retourLigne);
    void SupprClient(int id);

    Client * listeClient(char * sousNom);

    void Menuclient();
    void MenuAjoutClient();
    void MenuSupprimerClientCSV();
    void modifClient();
    void searchClientMenu();
    void listeClientChar();


    #endif

