/*************************************************************************
                           Catalogue  -  description
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

//----- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -----

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Note: catalogue is a protected attribute of class ListChainee

// Algorithme : 
// Call to the Afficher function in class ListChainee
void Catalogue::Afficher() {
    catalog.Afficher();
} //----- Fin de Afficher

// Algorithme :
// Call to the function PopCell in class ListChainee
void Catalogue::PopCell() {
    catalog.PopCell();
} //----- Fin de PopCell

// Algorithme :
// Call to the function AddTrajetSimple in class ListChainee
void Catalogue::addTrajetSimple(char* depart_param, char* arrivee_param, char* mode_param) {
    catalog.AddTrajetSimple(depart_param, arrivee_param, mode_param);
} //----- Fin de addTrajetSimple

// Algorithme :
// Call to the function AddTrajetCompose in class ListChainee
void Catalogue::addTrajetCompose(Trajet * trajet) {
    catalog.AddTrajetCompose(trajet);
} //----- Fin de addTrajetCompose

// Algorithme :
// The direct search algorithm using strcmp method
void Catalogue::searchDirect(char* depart_param, char* arrivee_param) {
    Cell* cursor = catalog.getHead();
    // If head is not null
    if (cursor != nullptr) {
        while (1) {
            // If departure and destination all match arguments passed in 
            // Using De Morgan's law: 
            if (!( strcmp(cursor->getDepart(), depart_param) || strcmp(cursor->getArrivee(), arrivee_param))) {
                cursor->Afficher();
            }
            // If reached end of list
            if (cursor->next==nullptr) {
                break;
            }
            // Iterate by moving the cursor to the next cell
            cursor = cursor->next;
        }
    }
} //----- Fin de searchDirect

// Algorithme :
// The depth-first search algorithm which also calls the function searchUnity
void Catalogue::searchAll(char* depart_param, char* arrivee_param) {
    ListeChainee tempList;
    Cell * cursor = catalog.getHead();
    if (cursor != nullptr) {
        // Unconditional while loop
        while (1) {
            // If departure matches input argument
            if (!strcmp(cursor->getDepart(), depart_param)) {
                searchUnity(cursor, arrivee_param, tempList);
            }
            // If reached end of list
            if (cursor->next == nullptr) {
                break;
            }
            // Iterate by moving the cursor to the next cell
            cursor = cursor->next;
        }
    }
    // test using cout
    // cout << "I'm still fine" << endl;
} //----- Fin de searchAll

// Algorithme :
// A further implementation of depth-first seartch algorithm
void Catalogue::searchUnity(Cell * current, char* arrivee_param, ListeChainee & liste) {
    liste.AddCellBonus(current);

    // If route found
    if (!strcmp(current->getArrivee(), arrivee_param)) {
        liste.Afficher();
        liste.PopCell();
        return;
    }
    // If not found
    Cell * cursor = catalog.getHead();
    if (cursor != nullptr) {
        while (1) {
            // If the departure of cell pointed by cursor matches current arrival,
            // i.e., connecting path is available
            if (!strcmp(cursor->getDepart(), current->getArrivee())) {
                // Recursive call of function searchUnity
                searchUnity(cursor, arrivee_param, liste);
            }
            // If reached end of list
            if (cursor->next == nullptr) {
                break;
            }
            // Iterate by moving the cursor to the next cell
            cursor = cursor->next;
        }
    }
    
    // Remove added route
    liste.PopCell();
} //----- Fin de searchUnity

//-------------------------------------------- Constructeurs - destructeur
// Algorithme :
// Constructor of an empty catalogue 
Catalogue::Catalogue() {
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif        
} //----- Fin de Catalogue

// Algorithme :
// Destructor of Catalogue at the end of the program cycle
Catalogue::~Catalogue() 
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

} //----- Fin de ~Catalogue