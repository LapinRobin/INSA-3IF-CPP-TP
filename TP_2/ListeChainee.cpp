/*************************************************************************
                           ListeChainee  -  description
                             -------------------

    début                : 22/11/2022
    copyright            : (C) 2022 par NGUYEN Le Tuan Khai, SU Yikang, WYNCOLL Marnie
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr, marnie.wyncoll@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeChainee.h"
#include "Cell.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ListeChainee::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


// Algorithme :
void ListeChainee::addElem(Cell * unCell)
{
  Cell *cursor = headPtr;
    if (headPtr == NULL) {
      headPtr = unCell;
    } else {
      while (1) {
        if (cursor->next != NULL) {
          cursor = cursor->next;
        } else {
          cursor->next = unCell;
          break;
        }
      }
    }
} //----- Fin de Méthode


void ListeChainee::Afficher()
{
  Cell *cursor = headPtr;
  while (1) {
    if (cursor->next != NULL) {
      cursor->Afficher();
      cursor = cursor->next;
    } else {
      break;
    }
  }
}
/*
//------------------------------------------------- Surcharge d'opérateurs
ListeChainee & ListeChainee::operator = ( const ListeChainee & unListeChainee )
// Algorithme :
//
{
} //----- Fin de operator =
*/

/*
//-------------------------------------------- Constructeurs - destructeur
ListeChainee::ListeChainee ( const ListeChainee & unListeChainee )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeChainee>" << endl;
#endif
} //----- Fin de ListeChainee (constructeur de copie)
*/

ListeChainee::ListeChainee ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif

} //----- Fin de ListeChainee


ListeChainee::ListeChainee (Cell * headPtr_param)
  : headPtr(headPtr_param)
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif

}


ListeChainee::~ListeChainee ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
} //----- Fin de ~ListeChainee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégée
