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

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------- Méthodes publiques

// Algorithme :
// Displays the simple path
void TrajetSimple::Afficher(){
    
    cout << "\n";
    Trajet::Afficher();
    cout << "Mode of Transport: " << modeTransport << endl;
    cout << "\n";
}

//-------------------------------------------- Constructeurs - destructeur
// Algorithme :
// Constructor of an empty simple path
TrajetSimple::TrajetSimple()
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} // ----- Fin de TrajetSimple

// Algorithme :
//
TrajetSimple::TrajetSimple(char* depart_param, char* arrivee_param, char* mode_param)
: Trajet(depart_param, arrivee_param)
{
    modeTransport = new char[strlen(mode_param + 1)];
    strcpy(modeTransport,mode_param);

}  // ----- Fin de TrajetSimple

// Algorithme :
// Destructor of simple path
TrajetSimple::~TrajetSimple()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete[] modeTransport;

} // ----- Fin de ~TrajetSimple