/*************************************************************************
                           Catalogue  -  description
                             -------------------

    début                : 22/11/2022
    copyright            : (C) 2022 par NGUYEN Le Tuan Khai, SU Yikang, WYNCOLL Marnie
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr, marnie.wyncoll@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// On pourrait:
// - Afficher le touts les trajets dans le catalogue courant
// - Ajouter des trajets simples ou composés
// - Rechercher le parcours dans le catalogue courant
//
//------------------------------------------------------------------------

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Init ( void );
    // Mode d'emploi :

    // Contrat :
    //

    void Afficher ( void );
    // Mode d'emploi :

    // Contrat :
    
    void AjouterTrajetSimple ( void );
    // Mode d'emploi :

    // Contrat :
    //

    void AjouterTrajetCompose ( void );
    // Mode d'emploi :

    // Contrat :
    //
    void RechercheSimple ( void );
    // Mode d'emploi :

    // Contrat :
    //    
    void RechercheAvancee ( void );
    // Mode d'emploi :

    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
    Catalogue & operator = ( const Catalogue & unCatalogue );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // XXX_H
