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
//---------- Réalisation de la classe <Cell> (fichier Cell.cpp) ------------


#include "Cell.h"
using namespace std;

//----------------------------------------------------- Méthodes publiques
// Algorithme :
// Displays the path contained in the cell
void Cell::Afficher(){
    trajet->Afficher();
}

// Algorithme :
// Deletes the path contained in the cell
void Cell::deleteTrajet(){
    delete trajet;
}

// Algorithme :
// Get city of departure contained in the cell
char* Cell::getDepart(){
    return trajet->Trajet::getDepart();
}

// Algorithme :
// Get the ultimate city of arrival in the cell
char* Cell::getArrivee(){
    return trajet->Trajet::getArrivee();
}

//-------------------------------------------- Constructeurs - destructeur
// Algorithme :
// Constructor of an empty cell
Cell::Cell()
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
} // ----- Fin de Cell

// Algorithme :
// Constructor of a cell containing a path
Cell::Cell(Trajet* trajet_param)
: trajet(trajet_param)
{
#ifdef MAP
    cout << "Appel au constructeur1 de <Cell>" << endl;
#endif  
} // ----- Fin de Cell

// Algorithme :
// Constructor of a cell containing path and pointer to the next cell
Cell::Cell(Trajet* trajet_param, Cell* next_param)
: trajet(trajet_param), next(next_param)
{
#ifdef MAP
    cout << "Appel au constructeur2 de <Cell>" << endl;
#endif  
} // ----- Fin de Cell

// Algorithme :
// Constructor by copy
Cell::Cell(Cell & aCell)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cell>" << endl;
#endif
    trajet = aCell.trajet;
} // ----- Fin de Cell

// Algorithme :
// Destructor of Cell
Cell::~Cell()
{
#ifdef MAP
    cout << "Appel au destructeur de <Cell>" << endl;
#endif
    
    delete trajet;
    delete next;
    
} // ----- Fin de ~Cell