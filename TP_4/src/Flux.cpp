/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : 03/01/2023
    copyright            : (C) 2023 par NGUYEN Le Tuan Khai, SU Yikang
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Flux> (fichier Flux.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

//------------------------------------------------------ Include personnel
#include "Flux.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Request Flux::Read_line(string line)
// Alogrithme :
// Parse the line into a Request object
{
    Request re;
    string word;
    stringstream ss(line);

    // Getting rid of the first part of the line
    getline(ss, word, ' ');
    re.IP = word;

    // Getting rid of the second part of the line
    getline(ss, word, ' ');
    re.log_name = word;

    // Getting rid of the third part of the line
    getline(ss, word, ' ');
    re.user_name = word;

    // Getting the time
    getline(ss, word, ']');
    re.time = word + "]";

    // Getting the target
    getline(ss, word, '"');
    getline(ss, word, '"');
    re.target = '"' + word + '"';

    // Getting the return code
    getline(ss, word, ' ');
    re.return_code = word;

    // Getting the data size
    getline(ss, word, ' ');
    re.data_size = word;

    // Getting the reference
    getline(ss, word, '"');
    getline(ss, word, '"');
    re.reference = '"' + word + '"';

    // Getting the client
    getline(ss, word, '"');
    getline(ss, word, '"');
    re.client = '"' + word + '"';

    // Returning the Request object
    return re;

}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Flux::Flux ( const Flux & unFlux )
// Algorithme :
// Constructor of copy
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Flux>" << endl;
#endif
} //----- Fin de Flux (constructeur de copie)


Flux::Flux ( )
// Algorithme :
// Default constructor
{
#ifdef MAP
    cout << "Appel au constructeur de <Flux>" << endl;
#endif
} //----- Fin de Flux


Flux::~Flux ( )
// Algorithme :
// Destructor
{
#ifdef MAP
    cout << "Appel au destructeur de <Flux>" << endl;
#endif
} //----- Fin de ~Flux


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

