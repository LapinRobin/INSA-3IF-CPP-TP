/*************************************************************************
                           Xxx  -  description
                             -------------------
                             
    début                : 22/11/2022
    copyright            : (C) 2022 par NGUYEN Le Tuan Khai, SU Yikang
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Main.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int Main ( )
// Algorithme :
//
{
    // Crée un instance de Catalogue
    Catalogue c;
    // Appel à la fonction UI, qui affiche l'interface d'utilisateur
    c.UI();

    return 0;
} //----- fin de Main

