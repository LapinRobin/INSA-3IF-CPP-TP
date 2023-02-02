/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stats> (fichier Stats.h) ----------------
#if ! defined ( STATS_H )
#define STATS_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "Flux.h"
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Stats>
// This class is used to read a file and parse it into a map of connections
//
//------------------------------------------------------------------------
struct Connection{
    string reference;
    string target;

    // Overloading operators
    bool operator==(const Connection& unConnection) const {
        return reference == unConnection.reference && target == unConnection.target;
    }

    bool operator>(const Connection& other) const {
        if(reference == other.reference)
            return target > other.target;
        else
            return reference > other.reference;
    }

    bool operator<(const Connection& other) const {
        if(reference == other.reference)
            return target < other.target;
        else
            return reference < other.reference;
    }

    friend ostream& operator<<(ostream& os, const Connection& con){
        os << "Ref: " << con.reference << " - " << "Target: " << con.target;
        return os;
    }
};

struct CompareByValue {
    // Overloading operator
    bool operator()(const pair<string, int>& left, const pair<string, int>& right) const{
        return left.second > right.second;
    }
};


class Stats
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    void read_file(string path, int, int);
    // Mode d'emploi :
    // Read the file and store the data in the map
    // Contrat :
    // Path has to be a valid path to a file
    // The two int parameters are used to specify the options for the output

    Connection request_to_connection(Request re);
    // Mode d'emploi :
    // Parse the Request object into a Connection object
    // Contrat :
    // The Request object has to be valid

    void write_to_file(string path, map<string, string>& labelMap);
    // Mode d'emploi :
    // Write the map to a file
    // Contrat :
    // Path has to be a valid path to a file

    void full_response(string, string, int, int);
    // Mode d'emploi :
    // Print the full response to the console
    // Contrat :
    // The two string parameters are the path to the read file the write file
    // The two int parameters are used to specify the options for the output

    void console_response(string, int, int);
    // Mode d'emploi :
    // Print the response to the console
    // Contrat :
    // The string parameter is the path to the read file
    // The two int parameters are used to specify the options for the output

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Stats ( const Stats & unStats );
    // Mode d'emploi (constructeur de copie) :
    // Construction by copy
    // Contrat :
    // The Stats object has to be valid

    Stats ( );
    // Mode d'emploi :
    // Default constructor
    // Contrat :
    // None

    virtual ~Stats ( );
    // Mode d'emploi :
    // Destructor
    // Contrat :
    // None

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    map<Connection, int> connectMap;
    map<string, int> nodeMap;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Stats>

#endif // STATS_H
