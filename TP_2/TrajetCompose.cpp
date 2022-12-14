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
//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Algorithme :
// Display the contents of compound path
void TrajetCompose::Afficher(){
    cout << "\n";
    cout << "=======================================" << endl;
    cout << "\n";
    Trajet::Afficher();
    cout << "-------------" << endl;
    liste.Afficher();
    cout << "=======================================" << endl;
}

// Algorithme :
// Add simple path to compound path
void TrajetCompose::addTrajetSimple(char* depart_param, char* arrivee_param, char* mode_param){
    liste.AddTrajetSimple(depart_param, arrivee_param, mode_param);
}



//-------------------------------------------- Constructeurs - destructeur
// Algorithme :
// Constructor of empty compound path
TrajetCompose::TrajetCompose()
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif        
}

// Algorithme :
// Constructor of a compound path
TrajetCompose::TrajetCompose(char* depart_param, char* arrivee_param)
: Trajet(depart_param, arrivee_param)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif 
}

// Algorithme :
// Destructor of compound path
TrajetCompose::~TrajetCompose(){
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

} 