/*************************************************************************
                           Cell  -  description
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
//---------- Interface de la classe <Cell> (fichier Cell.h) --------------

// Header Guard
#if ! defined (CELL_H)
#define CELL_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"


//------------------------------------------------------------------------
// Rôle de la classe <Cell>
// Each Cell represents a Trajet and a pointer to the next Cell.
//
//------------------------------------------------------------------------
class Cell 
{
//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
    void Afficher();
    // Mode d'emploi :
    // Displays the path contained in the cell
    // Contrat :
    // None

    void Afficher(ostream& path);
    // Mode d'emploi :
    // Displays the path contained in the cell
    // Contrat :
    // None

    void deleteTrajet();
    // Mode d'emploi :
    // Deletes the path contained in the cell
    // Contrat :
    // Never do this unless absolutely necessary

    char* getDepart();
    // Mode d'emploi :
    // Get city of departure contained in the cell
    // Contrat :
    // None
    char* getArrivee();
    // Mode d'emploi :
    // Get the ultimate city of arrival in the cell
    // Contrat :
    // None

    Trajet* getTrajet();
    // Mode d'emploi :
    // Get the trajet in the cell
    // Contrat :
    // None
//-------------------------------------------- Constructeurs - destructeur
    Cell();
    // Mode d'emploi :
    // Constructs an empty cell
    // Contrat :
    // None

    Cell(Trajet* trajet_param);
    // Mode d'emploi :
    // Constructs a cell containing a pointer to a path passed in as argument
    // Contrat :
    // None

    Cell(Trajet* trajet_param, Cell* next_param);
    // Mode d'emploi :
    // Constructs a cell containing a pointer to a path
    // and a pointer to the next Cell
    // Contrat :
    // None

    Cell(Cell & aCell);
    // Mode d'emploi (constructeur de copie) :
    // Copy construct using reference of a cell instance
    // Contrat :
    // None

    virtual ~Cell();
    // Mode d'emploi :
    // Destroys the cell.
    // This will iteratively destroy all elements in the linked list,
    // as "delete next" is called.
    // Contrat :
    // None

    // Pointer of class Cell
    // Should be made protected though
    Cell* next {nullptr};

protected:
//----------------------------------------------------- Attributs protégés
    // Pointer of class Trajet
    Trajet* trajet;

private:
};


#endif // CELL_H