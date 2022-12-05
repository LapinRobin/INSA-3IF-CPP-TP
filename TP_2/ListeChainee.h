/*************************************************************************
                           ListeChainee  -  description
                             -------------------

    début                : 22/11/2022
    copyright            : (C) 2022 par NGUYEN Le Tuan Khai, SU Yikang, WYNCOLL Marnie
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr, marnie.wyncoll@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----------------
#if ! defined ( LISTECHAINEE_H )
#define LISTECHAINEE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include "Trajet.h"
#include "Cell.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
//
//
//-------------------------ic Trajet-----------------------------------------------

class ListeChainee
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


    // Mode d'emploi :
    //
    // Contrat :
    //
    void addElem(Cell * unCell);
    void Afficher();

//------------------------------------------------- Surcharge d'opérateurs
    ListeChainee & operator = ( const ListeChainee & unListeChainee );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ListeChainee ( const ListeChainee & unListeChainee );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ListeChainee ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ListeChainee (Cell * headPtr_param);
    // Mode d'emploi :
    //
    // Contrat :
    //


    virtual ~ListeChainee ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Cell *headPtr = NULL;
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    

};

//-------------------------------- Autres définitions dépendantes de <ListeChainee>

#endif // XXX_H
