/*************************************************************************
                           Catalogue  -  description
                             -------------------

    début                : 22/11/2022
    copyright            : (C) 2022 par NGUYEN Le Tuan Khai, SU Yikang, WYNCOLL Marnie
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr, marnie.wyncoll@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "ListeChainee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Catalogue::Init ( void )
// Algorithme :

{
    ListeChainee ls;
    

    cout << "--- Catalogue ---" << endl;
    cout << "Entrez le numero" << endl;
    cout << "1: Afficher le catalogue" << endl;
    cout << "2: Ajouter un trajet simple" << endl;
    cout << "3: Ajouter un trajet compose" << endl;
    cout << "4: Recherche simple" << endl;
    cout << "5: Recherche avancee" << endl;
    cout << "6: Quitter" << endl;

    int c;
    while (cin >> c) {
        switch (c) {
            case 1:
                // Afficher();
                break;
            case 2:
                Catalogue::AjouterTrajetSimple();
                break;
            case 3:
                // Ajouter trajetCompose
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                // Exit the program
                break;
                
            default:
                cout << "Numero incorrect!" << endl;
        }

    }
} //----- Fin de Méthode


void Catalogue::Afficher() 
// Algorithme : Display all journeys in the linked list ls
{

}

void Catalogue::AjouterTrajetSimple()
// Algorithme :
{
    char *depart, *arrivee, *modeTransport;
    cout << "Entrez le lieu de depart" << endl;
    cin >> depart;
    cout << "Entrez le lieu d'arrivee" << endl;
    cin >> arrivee;
    cout << "Entrez le moyen de transport" << endl;
    cin >> modeTransport;
    
    Trajet trajetSimple(depart, arrivee, modeTransport);
    Cell oneCell;
    
    

    
    
}

void Catalogue::AjouterTrajetCompose()
// Algorithme :
{
    
}

void Catalogue::RechercheSimple()
// Algorithme :
{
    
}

void Catalogue::RechercheAvancee()
// Algorithme :
{

}




//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
