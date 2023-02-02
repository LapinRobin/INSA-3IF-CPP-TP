/*************************************************************************
                           TrajetSimple  -  description
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
//---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----

#if ! defined (TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <cstring>
using namespace std;
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// TrajetSimple is a derived class of Trajet
// It contains city of departure and arrival, and mode of transport, 
// which are all store in allocated strings.
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    // Mode d'emploi :
    // Displays the simple path
    // Contrat :
    // None
    void Afficher();

    void Afficher(ostream& path);

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple();
    // Mode d'emploi :
    // Constructor of an empty simple path
    // Contrat :
    // None
    TrajetSimple(char* depart_param, char* arrivee_param, char* mode_param);
    // Mode d'emploi :
    // Constructor of a simple path
    // Contrat :
    // Strings must be valid
    virtual ~TrajetSimple();
    // Mode d'emploi :
    // Destructor of simple path
    // Contrat :
    // None
protected:
//----------------------------------------------------- Attributs protégés
    char* modeTransport;

private:
};

#endif // TRAJETSIMPLE_H