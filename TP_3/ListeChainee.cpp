/*************************************************************************
                           ListeChainee  -  description
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

//--- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "ListeChainee.h"
#include "TrajetCompose.h"



//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

// Algorithme :
// Add a cell to the linked list by pointing next pointer to aCell
void ListeChainee::AddCell(Cell* aCell) {
    if (head == nullptr) {
        
        head = aCell;
    } else {
        Cell* cursor = head;
        while (1) {
            if (cursor->next != nullptr) {
                cursor = cursor->next;
            } else {
                
                cursor->next = aCell;
                break;
            }
        }
    }
}


// Algorithme :
// Pop the head of the cell in the linked list
void ListeChainee::PopCell() {
    if (head == nullptr)return;
    if (head->next == nullptr) {
        
        head = nullptr;
        return;
    }
    Cell* cursor = head;
    Cell* next = cursor->next;
    while (1) {
        if (next->next != nullptr) {
            cursor = next;
            next = next->next;
        } else {
            cursor->next =  nullptr;
            break;
        }
    }
    
}

// Algorithme :
// Returns the pointer to the first element of the category
Cell * ListeChainee::getHead() {
    return head;
}

// Algorithme :
// Add simple path to a new cell
void ListeChainee::AddTrajetSimple(char* depart_param, char* arrivee_param, char* mode_param) {
    tmpTrajet = new TrajetSimple(depart_param, arrivee_param, mode_param);
    tmpCell =  new Cell(tmpTrajet);
    AddCell(tmpCell);   
}

// Algorithme :
// Add compound path to a new cell
void ListeChainee::AddTrajetCompose(Trajet* trajet) {
    tmpCell = new Cell(trajet);
    AddCell(tmpCell);
}

// Algorithme :
// Returns the length of the linked list, i.e., the number of Cells
int ListeChainee::findLength() {
    if (head == nullptr) {return 0;}

    int count = 1;
    Cell * cursor = head;
    while (1) {
        if (cursor->next == nullptr)break;
        cursor = cursor->next;
        count ++;
    }
    return count;
}

// Algorithme :
// Displays the paths in the Cells in the linked list
void ListeChainee::Afficher() {
    if (head == nullptr) {
            cout << "Nothing" << endl;
            return;
    }
    Cell * cursor = head;
    head->Afficher();

    while (1) {
        if (cursor->next != nullptr) {
            cursor = cursor->next;
            cursor->Afficher();
        } else {
            break;
        }
    }
}

// Algorithme :
// Write the paths to the desired file
void ListeChainee::Afficher(ostream& path) {
    if (head == nullptr) {
            return;
    }
    Cell * cursor = head;
    head->Afficher(path);

    while (1) {
        if (cursor->next != nullptr) {
            cursor = cursor->next;
            cursor->Afficher(path);
        } else {
            break;
        }
    }
}

// Algorithme :
// Write the paths with filtered type to the file
void ListeChainee::AfficherByType(ostream& path) {
    char s;
    cout << endl;
    cout << "Type 0 for Simple Path, any other keys for Compound Path" << endl;
    cin >> s;
    
    // Only save simple paths
    if (s == '0') {
        
        if (head == nullptr) {
            return;
        }
        Cell * cursor = head;
        
        cout << "Im here";
        if (typeid(*(cursor->getTrajet())).name() == typeid(TrajetSimple).name()) {
            head->Afficher(path);
        }

        while (1) {
            if (cursor->next != nullptr) {
                cursor = cursor->next;
                if (typeid(*(cursor->getTrajet())).name() == typeid(TrajetSimple).name()) {
                    cursor->Afficher(path);
                }
            } else {
                break;
            }
        }
    
    // Only save compound paths
    } else {
        
        if (head == nullptr) {
            return;
        }
        Cell * cursor = head;
        
        cout << "Im here";
        if (typeid(*(cursor->getTrajet())).name() == typeid(TrajetCompose).name()) {
            head->Afficher(path);
        }

        while (1) {
            if (cursor->next != nullptr) {
                cursor = cursor->next;
                if (typeid(*(cursor->getTrajet())).name() == typeid(TrajetCompose).name()) {
                    cursor->Afficher(path);
                }
            } else {
                break;
            }
        }
    }
}

// Algorithme :
// Write paths with arrival and departure filter to the file
void ListeChainee::AfficherByLocation(ostream& path) {
    bool quit = false;
    char s;
    char* departureCity = new char[60];
    char* arrivalCity = new char[60];
    Cell * cursor;

    cout << "Choose your condition: (0) Departure   (1) Arrival   (2) Both" << endl;

    while (cin >> s) {
        
        quit = true;

        switch (s)
        {
        case '0':
            cout << "Match departure city" << endl;
            cin >> departureCity;
            
            if (head == nullptr) {
                    return;
            }
            cursor = head;
            if (!(strcmp(cursor->getDepart(), departureCity))) {
                head->Afficher(path);
            }

            while (1) {
                if (cursor->next != nullptr) {
                    cursor = cursor->next;
                    if (!(strcmp(cursor->getDepart(), departureCity))) {
                        cursor->Afficher(path);
                    }
                } else {
                    break;
                }
            }

            break;

        case '1':
            cout << "Match arrival city" << endl;
            cin >> arrivalCity;

            if (head == nullptr) {
                    return;
            }
            cursor = head;
            if (!(strcmp(cursor->getArrivee(), arrivalCity))) {
                head->Afficher(path);
            }

            while (1) {
                if (cursor->next != nullptr) {
                    cursor = cursor->next;
                    if (!(strcmp(cursor->getArrivee(), arrivalCity))) {
                        cursor->Afficher(path);
                    }
                } else {
                    break;
                }
            }

            break;

        case '2':
            cout << "Match departure and arrival city" << endl;
            cout << "Departure:" << endl;
            cin >> departureCity;
            cout << "Arrival:" << endl;
            cin >> arrivalCity;

            if (head == nullptr) {
                    return;
            }
            cursor = head;
            if (!(strcmp(cursor->getDepart(), departureCity)  ||  strcmp(cursor->getArrivee(), arrivalCity))) {
                head->Afficher(path);
            }

            while (1) {
                if (cursor->next != nullptr) {
                    cursor = cursor->next;
                    if (!(strcmp(cursor->getDepart(), departureCity)  ||  strcmp(cursor->getArrivee(), arrivalCity))) {
                        cursor->Afficher(path);
                    }
                } else {
                    break;
                }
            }

            break;

        default:
            quit = false;
            cout << "Invalid response. Retry" << endl;
        }

        if (quit) break;
    }

    delete[] departureCity;
    delete[] arrivalCity;
    

}


// Algorithme :
// Write the paths with index filtering to the file
void ListeChainee::AfficherByIndex(ostream& path) {
    int n, m;

    while (1) {
        cout << "Enter the value for n: ";
        cin >> n;
        cout << "Enter the value for m: ";
        cin >> m;

        if (m-n>=0) {
            break;
        } else {
            cout << "Values not satisfied. Retry" << endl;
        }
    }

    int index = 0;

    if (head == nullptr) {
            return;
    }
    Cell * cursor = head;

    if (n <= index && m >= index) {
        head->Afficher(path);
    }
    index ++;

    while (1) {
        if (cursor->next != nullptr) {
            cursor = cursor->next;
            if (n <= index && m >= index) {
                cursor->Afficher(path);
            }
            index++;
        } else {
            break;
        }
    }


}

//-------------------------------------------- Constructeurs - destructeur
// Algorithme :
// Constructor of an empty linked list
ListeChainee::ListeChainee()
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
}

// Algorithme :
// 
ListeChainee::ListeChainee(Cell* head_param)
: head(head_param)
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
#endif
}

// Algorithme :
// Destructor of ListChainee
// Will destroy all Cells and Trajets in the list
ListeChainee::~ListeChainee() {
#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
    
    delete head;
}