/*************************************************************************
                           Cell  -  description
                             -------------------

    début                : 22/11/2022
    copyright            : (C) 2022 par NGUYEN Le Tuan Khai, SU Yikang
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Cell> (fichier Cell.h) ----------------
#if ! defined ( CELL_H )
#define CELL_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cell>
// The Cell represents a Trajet Simple and a pointer to the next Cell.
//
//------------------------------------------------------------------------

class Cell
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    // Cell & operator = ( const Cell & unCell );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Cell ( const Cell & unCell );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cell ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Cell (Trajet* unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Cell (Trajet* unTrajet, Cell* next_param);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cell ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Cell* next {NULL};
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  Trajet* trajet;

};

//-------------------------------- Autres définitions dépendantes de <Cell>

#endif // CELL_H
