/*************************************************************************
                           main  -  description
                             -------------------
                             
    début                : 22/11/2022
    copyright            : (C) 2022 par NGUYEN Le Tuan Khai, 
                                        SU Yikang, 
                                        WYNCOLL Marnie
    e-mail               : le.nguyen@insa-lyon.fr, 
                           yikang.su@insa-lyon.fr, 
                           marnie.wyncoll@insa-lyon.fr
*************************************************************************/
//---------- Réalisation du module <main> (fichier main.cpp) -------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeChainee.h"
#include "Catalogue.h"
#include "TrajetCompose.h"

// Define maximum length of a string allocated
#define MAX_LENGTH 40

// Disable warnings
#pragma warning( push )
#pragma warning( disable : 4100 )

// Definition of the void function serviceLoop()
void serviceLoop();


int main(int argc, char const *argv[])
// Algorithme : 
{
    // Call of the void function serviceLoop
    serviceLoop();
    
    // Exit the program with return value of 0
    return 0;
} //----- Fin de main


// Initialization of void function serviceLoop()
void serviceLoop() 
// Algorithme : 
/* feifje
 */
{
    // s and s1 are variables of type char and are used to 
    // be assigned values from the input stream. We choose 
    // this type to deal with unexpected inputs like 
    char s, s1;
    // Initialization of cstrings of 
    char* depart = new char[MAX_LENGTH];
    char* arrivee = new char[MAX_LENGTH];
    char* modeTransport = new char[MAX_LENGTH];

    // Instantiation of class Catalogue
    Catalogue cat;
    // Instantiation of a pointer of class TrajetCompose
    TrajetCompose* complex;

    
    cout << "--------- Menu ---------" << endl;
    cout << "1: Add Simple Path" << endl;
    cout << "2: Add Compound Path" << endl;
    cout << "3: See Catalogue" << endl;
    cout << "4: Search Direct Paths" << endl;
    cout << "5: Search All Paths" << endl; 
    cout << "0: Quit" << endl;

    // While the input from the input stream is true
    while (cin >> s) {

        // Here we set a boolean value to false in order to use
        // it later for the case '0' and the if statement as means 
        // of exiting the while loop, i.e. exiting the program.
        bool quit = false;
        switch(s) {
            // Case of quitting the program
            case '0':
                quit = true;
                break;

            // Case when choosing to add a simple path to category
            case '1':
                cout << "--- Creating Simple Path -----" << endl;
                cout << "Enter city of departure: ";
                cin >> depart;
                cout << "Enter city of arrival: ";
                cin >> arrivee;
                cout << "Add mode of Transport: ";
                cin >> modeTransport;
                cout << "------------------------------" << endl;
                cat.addTrajetSimple(depart, arrivee, modeTransport);
                break;

            // Case when choosing to add a compound path to category
            case '2':
                cout << "--------- Creating Compound Path ---------" << endl;
                cout << "For example, if the path is a -> b -> c," << endl;
                cout << "Enter \"a\" and then \"c\" as start and finish" << endl;
                cout << "------------------------------------------" << endl;
                cout << "Enter city of departure: ";
                cin >> depart;
                cout << "Enter ultimate city of arrival: ";
                cin >> arrivee;
                cout << endl;
                // First create an instance of class TrajetCompose outside while
                complex = new TrajetCompose(depart, arrivee);
                cout << "Following the last example, first sub-path is" << endl;
                cout << "a -> b, so select \"1: Add Simple Path\"," << endl;
                cout << "enter \"a\" and then \"b\"." << endl;
                cout << "------------------------------------------" << endl;
                cout << "1: Add Simple Path" << endl;
                cout << "0: Exit Compound Path" << endl;

                // while input stream passed to variable s1 is true
                while (cin >> s1) { 
                    
                    // if input is 0, exit compound path creation
                    if (s1 == '0') {
                        break;
                    
                    // if input is 1, continue compound path creation
                    // by adding simple path as sub-element
                    } else if (s1 == '1') {
                        cout << "--------- Add Simple Path -----" << endl;
                        cout << "Enter city of departure: ";
                        cin >> depart;
                        cout << "Enter city of arrival: ";
                        cin >> arrivee;
                        cout << "Add mode of Transport: ";
                        cin >> modeTransport;
                        cout << "------------------------------" << endl;
                        // call of the function addTrajetSimple
                        complex->addTrajetSimple(depart, arrivee, modeTransport);
                    
                    // if input in invalid, show error message and continue while
                    } else {
                        cout << "Please enter 0 or 1" << endl;
                        continue;
                    }
                    cout << "1: Add Simple Path" << endl;
                    cout << "0: Exit Compound Path" << endl;
                }

                // add complex to cat of class Catalogue
                cat.addTrajetCompose(complex);
                cout << "----------------------------" << endl;
                break; 

            // Case when choosing to display all journeys stored in the category
            case '3':
                cat.Afficher();
                break;
            
            // Case of inquiring the direct search 
            case '4':
                cout << "Enter city of departure: ";
                cin >> depart;
                cout << "Enter city of arrival: ";
                cin >> arrivee;
                cat.searchDirect(depart, arrivee);
                break;

            // Case of inquiring the complex search (Depth-first search)
            case '5':
                cout << "Enter city of departure: ";
                cin >> depart;
                cout << "Enter city of arrival: ";
                cin >> arrivee;
                cat.searchAll(depart, arrivee);
                break;

            // Case of not entering a valid number
            default:
                cout << "Invalid input, please select a number from 0 to 5 inclusive..." << endl;
        }
        
        // If entry is '0'
        if (quit) {
            break;
        }

        // Beginning a new session and creating a menu
        cout << endl;
        cout << "--------- Menu ---------" << endl;
        cout << "1: Add Simple Path" << endl;
        cout << "2: Add Compound Path" << endl;
        cout << "3: See Catalogue" << endl;
        cout << "4: Search Direct Paths" << endl;
        cout << "5: Search All Paths" << endl; 
        cout << "0: Quit" << endl;
    }
    // Delete the three allocated strings
    delete[] depart;
    delete[] arrivee;
    delete[] modeTransport;
}
