/*************************************************************************
                           ListeChainee  -  description
                             -------------------
    début                : 22/11/2022
    copyright            : (C) 2022 par 
                           NGUYEN Le Tuan Khai, 
                           SU Yikang, 
                           WYNCOLL Marnie
    e-mail               : le.nguyen@insa-lyon.fr, 
                           yikang.su@insa-lyon.fr, 
                           marnie.wyncoll@insa-lyon.fr
*************************************************************************/
//---- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----

// Header Guard
#if ! defined (LISTECHAINEE_H)
#define LISTECHAINEE_H


#define MAX_LENGTH 40

//--------------------------------------------------- Interfaces utilisées
#include "Cell.h"

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
// This is a liked list of Cell
// It contains the pointer pointing to the head of the cell
//------------------------------------------------------------------------
class ListeChainee 
{
//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
    void AddCell(Cell* aCell);
    // Mode d'emploi :
    // Add a cell to the linked list
    // Contrat :
    // None


    void PopCell();
    // Mode d'emploi :
    // Pop the head of the cell in the linked list
    // Contrat :
    // None

    Cell * getHead();
    // Mode d'emploi :
    // Returns the pointer to the first element of the category
    // Contrat :
    // None

    void AddTrajetSimple(char* depart_param, char* arrivee_param, char* mode_param);
    // Mode d'emploi :
    // Add simple path to a new cell
    // Contrat :
    // None

    void AddTrajetCompose(Trajet* trajet);
    // Mode d'emploi :
    // Add compound path to a new cell
    // Contrat :
    // None

    int findLength();
    // Mode d'emploi :
    // Returns the length of the linked list, i.e., the number of Cells
    // Contrat :
    // None

    void Afficher();
    // Mode d'emploi :
    // Displays the paths in the Cells in the linked list
    // Contrat :
    // None

    void Afficher(ostream& path);
    // Mode d'emploi :
    // Save the catalog to a file without filter
    // Contrat :
    // Passed in path should be a valid file

    void AfficherByType(ostream& path);
    // Mode d'emploi :
    // Save the catalog to a file with type filter
    // Contrat :
    // Passed in path should be a valid file

    void AfficherByLocation(ostream& path);
    // Mode d'emploi :
    // Save the catalog to a file with location filter
    // Contrat :
    // Passed in path should be a valid file

    void AfficherByIndex(ostream& path);
    // Mode d'emploi :
    // Save the catalog to a file with index filter
    // Contrat :
    // Passed in path should be a valid file

//-------------------------------------------- Constructeurs - destructeur
    ListeChainee();
    // Mode d'emploi :
    // Constructor of an empty linked list
    // Contrat :
    // None

    ListeChainee(Cell* head_param);
    // Mode d'emploi :
    // Constructor of a linked list with a pointer of Cell as argument
    // Contrat :
    // None

    virtual ~ListeChainee();
    // Mode d'emploi :
    // Destructor of ListChainee
    // Will destroy all Cells and Trajets in the list
    // Contrat :
    // This destructor will automatically destroy all elements in the list.
protected:
//----------------------------------------------------- Attributs protégés
    Cell * tmpCell {nullptr};
    Trajet * tmpTrajet {nullptr};
    Cell * head {nullptr};

private:
};


#endif // LISTECHAINEE_H