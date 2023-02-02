/*************************************************************************
                           Flux  -  description
                             -------------------
    début                : 03/01/2023
    copyright            : (C) 2023 par NGUYEN Le Tuan Khai, SU Yikang
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Flux> (fichier Flux.h) ----------------
#if ! defined ( FLUX_H )
#define FLUX_H


//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

struct Request{
    string IP;
    string log_name;
    string user_name;
    string time;
    string target;
    string return_code;
    string data_size;
    string reference;
    string client;
};

//------------------------------------------------------------------------
// Rôle de la classe <Flux>
// This class is used to read a line from a file and parse it into a Request object
//
//------------------------------------------------------------------------

class Flux
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Request Read_line(string path);
    // Mode d'emploi :
    // Parse the line into a Request object
    // Contrat :
    // Path has to be a valid path to a file

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Flux ( const Flux & unFlux );
    // Mode d'emploi (constructeur de copie) :
    // Construction by copy
    // Contrat :
    // None

    Flux ( );
    // Mode d'emploi :
    // Default constructor
    // Contrat :
    // None of the attributes are initialized

    virtual ~Flux ( );
    // Mode d'emploi :
    // Destructor
    // Contrat :
    // The destructor is virtual to allow the destruction of derived classes

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Flux>

#endif // FLUX_H

