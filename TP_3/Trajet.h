/*************************************************************************
                           Trajet  -  description
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
//-------- Interface de la classe <Trajet> (fichier Trajet.h) ------------

// Header Guard
#if ! defined (TRAJET_H)
#define TRAJET_H
//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <cstring>
using namespace std;


//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// This is served as base class for TrajetCompose and TrajetSimple
// The aim of this class is to work with simple and compound differently
//------------------------------------------------------------------------

class Trajet
{
public:

//----------------------------------------------------- Méthodes publiques

    virtual void Afficher();
    // Mode d'emploi :
    // Displays the path
    // Contrat :
    // None

    virtual void Afficher(ostream& path);
    // Mode d'emploi :
    // Displays the path
    // Contrat :
    // None

    char* getDepart();
    // Mode d'emploi :
    // Returns the departure city string
    // Contrat :
    // None

    char* getArrivee();
    // Mode d'emploi :
    // Returns the arribal city string
    // Contrat :
    // None
//-------------------------------------------- Constructeurs - destructeur

    Trajet();
    // Mode d'emploi :
    // Constructor of empty Trajet
    // Contrat :
    // None

    Trajet(char* depart_param, char* arrivee_param);
    // Mode d'emploi :
    // Constructor of Trajet with departure and arrival strings passed in 
    // Contrat :
    // Strings must be valid

    virtual ~Trajet();
    // Mode d'emploi :
    // Destructor of Trajet
    // Contrat :
    // None
protected:

//----------------------------------------------------- Attributs protégés
    char* depart;
    char* arrivee;

private:
};



#endif // TRAJET_H