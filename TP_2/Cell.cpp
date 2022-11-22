/*************************************************************************
                           Cell  -  description
                             -------------------

    début                : 22/11/2022
    copyright            : (C) 2022 par NGUYEN Le Tuan Khai, SU Yikang
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Cell> (fichier Cell.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cell.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cell::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Cell::Afficher()
// Algorithme :
//
//{
//} //----- Fin de Méthode
{
  trajet->Afficher();

}


//------------------------------------------------- Surcharge d'opérateurs
//Cell & Cell::operator = ( const Cell & unCell )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Cell::Cell ( const Cell & unCell )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cell>" << endl;
#endif
} //----- Fin de Cell (constructeur de copie)
*/

Cell::Cell ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
} //----- Fin de Cell


Cell::Cell (Trajet* & unTrajet)
 : trajet(unTrajet)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif


} //----- Fin de Cell


Cell::Cell (Trajet* unTrajet, Cell* next_param)
  : trajet(unTrajet), next(next_param)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
} //----- Fin de Cell


Cell::~Cell ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cell>" << endl;
#endif
} //----- Fin de ~Cell


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
