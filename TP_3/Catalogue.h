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
//------ Interface de la classe <Catalogue> (fichier Catalogue.h) --------

// Header Guard
#if ! defined (CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "ListeChainee.h"

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// We can:
// - Display all paths contained in the catalogue
// - Add simple or compound paths to the catalogue
// - Search for paths in the catalogue
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
    void Afficher();
    // Mode d'emploi :
    // Display all paths contained in the catalogue
    // Contrat :
    // None

    void PopCell();
    // Mode d'emploi :
    // Call to the function PopCell in class ListChainee
    // Contrat :
    // Used only in advanced search, when new cells are created

    void addTrajetSimple(char* depart_param, char* arrivee_param, char* mode_param);
    // Mode d'emploi :
    // Add a simple path to the catalogue using the terminal
    // Contrat :
    // None


    void addTrajetCompose(Trajet * trajet);
    // Mode d'emploi :
    // Add a compound path to the catalogue using the terminal
    // Contrat :
    // None


    void searchDirect(char* depart_param, char* arrivee_param);
    // Mode d'emploi :
    // Search paths by passing in arguments of the departure and arrival city
    // Contrat :
    // Inputs strings must not contain spaces
    // Length of the string should be less than or equal to (MAX_LENGTH - 1)


    int Save(string fileName);
    // Mode d'emploi :
    // Save the existing catalog to the fileName given by the user
    // Contrat :
    // Input passed by the user should be a valid string.
    // The extension .txt should not be included.
    // The destination file should be in the same directory.

    int Load(string fileName);
    // Mode d'emploi :
    // Load the file from the fileName given by the user
    // Contrat :
    // Input passed by the user should be a valid string.
    // The extension .txt should not be included.
    // The load file should be in the same directory as the code.

//-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Mode d'emploi :
    // Constructor of an empty catalogue
    // Contrat :
    // None
    virtual ~Catalogue();
    // Mode d'emploi :
    // Complete destruction of the catalogue
    // Contrat :
    // None
protected:
//----------------------------------------------------- Attributs protégés
    ListeChainee catalog;
private:
};


#endif // CATALOGUE_H