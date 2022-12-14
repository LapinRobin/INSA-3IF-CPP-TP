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



//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

// Algorithme :
//
void ListeChainee::AddCell(Cell* aCell){
    if(head == nullptr){
        
        head = aCell;
    }else{
        Cell* cursor = head;
        while(1){
            if(cursor->next != nullptr){
                cursor = cursor->next;
            }else{
                
                cursor->next = aCell;
                break;
            }
        }
    }
}
// Algorithme :
//
void ListeChainee::AddCellBonus(Cell* aCell){
    if(head == nullptr){
        head = new Cell(*aCell);
        
    }else{
        Cell* cursor = head;
        while(1){
            if(cursor->next != nullptr){
                cursor = cursor->next;
            }else{
                cursor->next = new Cell(*aCell);
                
                break;
            }
        }
    }
}

// Algorithme :
// Pop the head of the cell in the linked list
void ListeChainee::PopCell(){
    if(head == nullptr)return;
    if(head->next == nullptr){
        
        head = nullptr;
        return;
    }
    Cell* cursor = head;
    Cell* next = cursor->next;
    while(1){
        if(next->next != nullptr){
            cursor = next;
            next = next->next;
        }else{
            cursor->next =  nullptr;
            break;
        }
    }
    
}

// Algorithme :
// Returns the pointer to the first element of the category
Cell * ListeChainee::getHead(){
    return head;
}

// Algorithme :
// Add simple path to a new cell
void ListeChainee::AddTrajetSimple(char* depart_param, char* arrivee_param, char* mode_param){
    tmpTrajet = new TrajetSimple(depart_param, arrivee_param, mode_param);
    tmpCell =  new Cell(tmpTrajet);
    AddCell(tmpCell);   
}

// Algorithme :
// Add compound path to a new cell
void ListeChainee::AddTrajetCompose(Trajet* trajet){
    tmpCell = new Cell(trajet);
    AddCell(tmpCell);
}

// Algorithme :
// Returns the length of the linked list, i.e., the number of Cells
int ListeChainee::findLength(){
    if(head == nullptr){return 0;}

    int count = 1;
    Cell * cursor = head;
    while(1){
        if(cursor->next == nullptr)break;
        cursor = cursor->next;
        count ++;
    }
    return count;
}

// Algorithme :
// Displays the paths in the Cells in the linked list
void ListeChainee::Afficher(){
    if(head == nullptr){
            cout << "Nothing" << endl;
            return;
    }
    Cell * cursor = head;
    head->Afficher();

    while(1){
        if(cursor->next != nullptr){
            cursor = cursor->next;
            cursor->Afficher();
        }else{
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
ListeChainee::~ListeChainee(){
#ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
#endif
    
    delete head;
}