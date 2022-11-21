#if ! defined (ENSEMBLE_H)
#define ENSEMBLE_H

#define CARD_MAX 5

enum crduEstInclus { NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE };
enum crduAjouter { DEJA_PRESENT, PLEIN, AJOUTE };

class Ensemble
{

    public:

        Ensemble (unsigned int cardMax = CARD_MAX);

        Ensemble (int t[], unsigned int nbElements);

        virtual ~Ensemble (void);

        void Afficher (void);

        bool EstEgal (const Ensemble & unEnsemble) const;

        crduEstInclus EstInclus (const Ensemble & unEnsemble) const;

        crduAjouter Ajouter (int aAjouter);

        unsigned int Ajuster (int delta);

        bool Retirer (int elem);

        unsigned int Retirer (const Ensemble & unEnsemble);
        
        int Reunir (const Ensemble & unEnsemble);

        unsigned int Intersection (const Ensemble & unEnsemble);





        
    protected:
        void tri();
        bool doublon(int value);
        unsigned int cardMax;
        unsigned int cardActuelle;
        int *element;
};

#endif