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

//--------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) -------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
//------------------------------------------------------ Include personnel
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// Algorithme :
// Displays the path
void Trajet::Afficher() {
    cout << "From: " << depart << " - To: " << arrivee << endl; 
}

// Algorithme :
// Returns the departure city string
char* Trajet::getDepart() {
    return depart;
}

// Algorithme :
// Returns the arrival city string
char* Trajet::getArrivee() {
    return arrivee;
}

//-------------------------------------------- Constructeurs - destructeur
// Algorithme :
// Constructor of empty Trajet
Trajet::Trajet() 
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet

// Algorithme :
// Constructor of Trajet with departure and arrival strings passed in 
Trajet::Trajet(char* depart_param, char* arrivee_param)
{
    depart = new char[strlen(depart_param+1)];
    arrivee = new char[strlen(arrivee_param+1)];
    strcpy(depart, depart_param);
    strcpy(arrivee, arrivee_param);
} //----- Fin de Trajet

// Algorithme :
// Destructor of Trajet
Trajet::~Trajet()
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif

    delete[] depart;
    delete[] arrivee;
} //----- Fin de ~Trajet