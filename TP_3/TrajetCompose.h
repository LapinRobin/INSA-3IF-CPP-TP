/*************************************************************************
                           TrajetCompose  -  description
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
//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
// Header Guard
#if ! defined (TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "ListeChainee.h"



//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// This class is a derived class of Trajet.
// The class contains linked list of simple paths to realize the 
// implementation of compound paths.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC    
public:
//----------------------------------------------------- Méthodes publiques
    void Afficher();
    // Mode d'emploi :
    // Display the contents of compound path
    // Contrat :
    // None

    void Afficher(ostream& path);
    // Mode d'emploi :
    // Display the contents of compound path
    // Contrat :
    // None

    void addTrajetSimple(char* depart_param, char* arrivee_param, char* mode_param);
    // Mode d'emploi :
    // Add simple path to compound path
    // Contrat :
    // Strings must be valid
//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose();
    // Mode d'emploi :
    // Constructor of empty compound path
    // Contrat :
    // None

    TrajetCompose(char* depart_param, char* arrivee_param);
    // Mode d'emploi :
    // Constructor of a compound path
    // Contrat :
    // Strings must be valid

    virtual ~TrajetCompose();
    // Mode d'emploi :
    // Destructor of compound path
    // Will automatically destroy all simple paths in the linked list
    // Contrat :
    // None

protected:
//----------------------------------------------------- Attributs protégés
    
    ListeChainee liste;

private:
};



#endif // TRAJETCOMPOSE_H