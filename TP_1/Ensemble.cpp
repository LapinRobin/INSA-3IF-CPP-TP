#include <iostream>

using namespace std;

#include "Ensemble.h"



void Ensemble::Afficher (void)
{
    cout << cardActuelle << "\r\n";
    cout << cardMax << "\r\n";

    if (cardActuelle == 0) {
        cout << "{}" << "\r\n";
    } else {
        cout<<"{";
        tri();
        unsigned int i;

        for (i = 0; i < cardActuelle - 1; i++) {
            cout << element[i] << ",";
        }
        cout << element[cardActuelle - 1] << "}" << "\r\n";
    }

    
}

Ensemble::Ensemble (unsigned int cMax)
{
    #ifdef MAP
        cout << "Appel au constructeur de Ensemble" << endl;
    #endif

    cardMax = cMax;
    cardActuelle = 0;
    if (cardMax == 0) {
        element = NULL;
    } else {
        element = new int[cMax];
    }
       
}

Ensemble::Ensemble (int t[], unsigned int nbElements)
{
    #ifdef MAP
        cout << "Appel au constructeur de Ensemble" << endl;
    #endif

    cardMax = nbElements;
    element = new int[cardMax];
    cardActuelle = 0;
    
    for (unsigned int i = 0; i < nbElements; i++) {
        if (!doublon(t[i])) {
            element[cardActuelle] = t[i];
            cardActuelle++;
        }
    
    }
    tri();
}

Ensemble::~Ensemble (void)
{
    #ifdef MAP
        cout << "Appel au destructeur de <Ensemble>" << endl;
    #endif

	delete[](element);
}

bool Ensemble::EstEgal (const Ensemble & unEnsemble) const
{
    unsigned int i, j;
	if (cardActuelle == unEnsemble.cardActuelle) {
        for (i = 0; i < cardActuelle; i++) {
            bool stat = false; 
            for (j = 0; j < cardActuelle; j++) {
                if (element[i] == unEnsemble.element[j]) {
                    stat = true;
                    break;
                }
            }
            if (!stat) {
                return false;
            }
        }  
        return true;
    } else {
        return false;
    }  
}

crduEstInclus Ensemble::EstInclus (const Ensemble & unEnsemble) const
{
    if (EstEgal(unEnsemble)) {
        return INCLUSION_LARGE;
    } else {
        unsigned int i, j;
        bool stat;

        for (i = 0; i < cardActuelle; i++) {
            stat = false;
            for (j = 0; j < unEnsemble.cardActuelle; j++) {
                if (unEnsemble.element[j] == element[i]) {
                    stat = true;
                    break;
                }
            }
            if (!stat) {
                return NON_INCLUSION;
            }
        }
        return INCLUSION_STRICTE;
    }
}

crduAjouter Ensemble::Ajouter (int aAjouter)
{
    if (doublon(aAjouter)) {
        return DEJA_PRESENT;
    } else if (cardActuelle == cardMax) {
        return PLEIN;
    } else {
        element[cardActuelle] = aAjouter;
        cardActuelle++;
        return AJOUTE;
    }
}

unsigned int Ensemble::Ajuster (int delta)
{

    if (delta == 0) {
        return cardMax;
    } else if (delta > 0) {
        int *temp = new int [cardMax + delta];
        for (unsigned int i = 0; i < cardMax; i++) {
            temp[i] = element[i];
        }
        delete[](element);
        element = temp;
        cardMax += delta;
        return cardMax;
    } else {
        if ((int)cardMax + delta < (int)cardActuelle || (int)cardMax < (0 - delta)) {
            int *temp = new int [cardActuelle];
            for (unsigned int i = 0; i < cardActuelle; i++) {
                temp[i] = element[i];
            }
            delete[](element);
            element = temp;
            cardMax = cardActuelle;
            return cardMax;  
        } else {
            int *temp = new int [cardMax + delta];
            for (unsigned int i = 0; i < cardMax + delta; i++) {
                temp[i] = element[i];
            }
            delete[](element);
            element = temp;
            cardMax += delta;
            return cardMax; 
        }
    }
}

bool Ensemble::Retirer (int elem) 
{
    if (!doublon(elem)) {
        Ajuster(-(int) cardMax);
        return false;
    } else {
        
        unsigned int i, j;
        for (i = 0; i < cardActuelle; i++) {
            if (element[i] == elem) {
                for (j = i; j < cardActuelle - 1; j++) {
                    element[j] = element[j + 1];
                }
                cardActuelle--;
                Ajuster(-(int) cardMax);
            }
        }
        return true;
    }
}

unsigned int Ensemble::Retirer (const Ensemble & unEnsemble)
{
    unsigned int i, counter = 0, tempMax = cardMax, tempAct = unEnsemble.cardActuelle;

    int *temp = new int[unEnsemble.cardActuelle];
    for (i = 0; i < tempAct; i++) {
        temp[i] = unEnsemble.element[i];
    } 
    for (i = 0; i < tempAct; i++) {
        if (Retirer(temp[i])) {
            counter++;
        }
    }
    Ajuster(tempMax - cardMax);
    tri();
    delete [](temp);
    return counter;

    // but why ? Why does unEnsemble change ? So bizzare...

    // unsigned int cpt = 0;
    // unsigned int cardMaxConserver = cardMax;
    // int cAc=unEnsemble.cardActuelle;
    // int *tabCopie= new int[unEnsemble.cardActuelle];
    // for( unsigned int i=0;i< unEnsemble.cardActuelle;i++)
    // {
    //     tabCopie[i]=unEnsemble.element[i];
    // }

    // for( unsigned int i=0;i< cAc;i++)
    // {
    //     if(Retirer(tabCopie[i]))
    //     {
    //         cpt++;
    //     }
    // }
    // Ajuster(cardMaxConserver-cardMax);
    // tri();
    // delete [] tabCopie;
    // return cpt;
}

int Ensemble::Reunir (const Ensemble & unEnsemble)
{
    unsigned int i, j, tempAct = unEnsemble.cardActuelle;
    int count = 0;
    int *temp = new int[tempAct];
    bool reajuster = false;

    for (i = 0; i < tempAct; i++) {
        temp[i] = unEnsemble.element[i];
    }
    for (i = 0; i < tempAct; i++) {
        
        if (!doublon(temp[i])) {

            if (cardActuelle == cardMax) {
                reajuster = true;
                int *adjust = new int[cardMax + 1];
                for (j = 0; j < cardMax; j++) {
                    adjust[j] = element[j];
                }
                adjust[cardMax] = temp[i];
                delete[] element;
                element = adjust;

                //delete[] adjust;
                count++;
                cardActuelle++;
                cardMax++;
            } else {
                Ajouter(temp[i]);
                count++;
            }
            // if (Ajouter(temp[i]) == 1) {
            //     reajuster = true;
            //     int *adjust = new int[cardMax + 1];
            //     for (j = 0; j < cardMax; j++) {
            //         adjust[j] = element[j];
            //     }
            //     adjust[cardMax] = temp[i];
            //     delete[](element);
            //     element = adjust;
            //     delete[](adjust);
            // }
        }
    }

    if (count == 0) {
        return 0;
    } else if (reajuster == true) {
        return -1 * count;
    } else {
        return count;
    }
    
}

unsigned int Ensemble::Intersection (const Ensemble & unEnsemble)
{
    int *inter;
    inter = new int[cardActuelle];
    int common = 0;
    for (unsigned int i = 0; i < cardActuelle; i++) {
        for (unsigned int j = 0; j < unEnsemble.cardActuelle; j++) {
            if (unEnsemble.element[j] == element[i]) {
                inter[common] = element[i];
                common++;
            }
        } 
    }
    int numDelete = cardActuelle - common;
    delete[](element);
    element = inter;
    cardActuelle = common;
    Ajuster(-cardMax);
    return numDelete;
}


void Ensemble::tri (void)
{
    bool fin;
    unsigned int i, j;
    for (i = 0; i < cardActuelle && cardActuelle != 0; i++) {
        fin = true;
        for (j = cardActuelle - 1; j >= i + 1; j--) {
            if (element[j] < element[j - 1]) {
                fin = false;
                int temp;
                temp = element[j];
                element[j] = element[j - 1];
                element[j - 1] = temp;
            }
        }
        if (fin)
            break;
    }
}

bool Ensemble::doublon (int value) {
    unsigned int i;
    if (cardActuelle == 0) {
        return false;
    } else {
        for (i = 0; i < cardActuelle; i++) {
            if (element[i] == value) {
                return true;
            }
        }
        return false;
    }
}





