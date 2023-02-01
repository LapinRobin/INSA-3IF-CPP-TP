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

//----- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -----

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Note: catalogue is a protected attribute of class ListChainee

// Algorithme : 
// Call to the Afficher function in class ListChainee
void Catalogue::Afficher() {
    catalog.Afficher();
} //----- Fin de Afficher

// Algorithme :
// Call to the function PopCell in class ListChainee
void Catalogue::PopCell() {
    catalog.PopCell();
} //----- Fin de PopCell

// Algorithme :
// Call to the function AddTrajetSimple in class ListChainee
void Catalogue::addTrajetSimple(char* depart_param, char* arrivee_param, char* mode_param) {
    catalog.AddTrajetSimple(depart_param, arrivee_param, mode_param);
} //----- Fin de addTrajetSimple

// Algorithme :
// Call to the function AddTrajetCompose in class ListChainee
void Catalogue::addTrajetCompose(Trajet * trajet) {
    catalog.AddTrajetCompose(trajet);
} //----- Fin de addTrajetCompose

// Algorithme :
// The direct search algorithm using strcmp method
void Catalogue::searchDirect(char* depart_param, char* arrivee_param) {
    Cell* cursor = catalog.getHead();
    // If head is not null
    if (cursor != nullptr) {
        while (1) {
            // If departure and destination all match arguments passed in 
            // Using De Morgan's law: 
            if (!( strcmp(cursor->getDepart(), depart_param) || strcmp(cursor->getArrivee(), arrivee_param))) {
                cursor->Afficher();
            }
            // If reached end of list
            if (cursor->next==nullptr) {
                break;
            }
            // Iterate by moving the cursor to the next cell
            cursor = cursor->next;
        }
    }
} //----- Fin de searchDirect



// Algorithme :
// A further implementation of depth-first seartch algorithm

// If return -1, means that file cannot be opened
//            0, means that properly executed
int Catalogue::Save(string fileName) {
    // Boolean value quit to be used in filter selection loop.
    bool quit = false;
    // Character s to be assigned with user input.
    char s;

    ofstream myFile(fileName);
    
    // If we can't open the file, exit
    if (!myFile.is_open()) {
        cout << "Unable to open file" << endl;
        return -1;
    }

    // When quit is false
    while (!quit) {
        // Change quit value to true
        quit = !quit;

        // Menu selection of filter conditions
        cout << "Choose Filter Condition: " << endl;
        cout << "1: None " << endl;
        cout << "2: Type of Trajet" << endl;
        cout << "3: Arrival/Departure Location" << endl;
        cout << "4: Index Range" << endl;
        cout << endl;
    
        cin >> s;
        switch (s)
        {
        case '1':
            catalog.Afficher(myFile);
            break;
        
        case '2':
            catalog.AfficherByType(myFile);
            break;
        
        case '3':
            catalog.AfficherByLocation(myFile);
            break;
        
        case '4':
            catalog.AfficherByIndex(myFile);
            break;
        
        default:
            cout << "Invalid input, retry" << endl;
            // Set quit to false, redo the while loop
            quit = !quit;
        }
    }
    // close myFile to free up memory
    myFile.close();
    return 0;
}

// Algorithme :
// Algorithm to load catalogue into the designated file,
// with multiple filter conditions available
int Catalogue::Load(string fileName) {
    bool quit = false;
    char s;
    bool in_complex = false;
    bool cur_simple, cur_complex, pathInc;
    int index = 0;
    char e, s1;
    int pathIndex;

    string depart, arrivee, modeTransport;
    string depart_complex, arrivee_complex;
    string departureCity;
    string arrivalCity;

    TrajetCompose* complex;

    string line;
    ifstream file(fileName);
    string word;

    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        return -1;
    }

    while (!quit) {

        quit = !quit;
        // Menu selection of filter condition
        cout << "Choose Filter Condition: " << endl;
        cout << "1: None " << endl;
        cout << "2: Type of Trajet" << endl;
        cout << "3: Arrival/Departure Location" << endl;
        cout << "4: Index Range" << endl;
        cout << endl;
    
        cin >> s;
        switch (s)
        {
        // No filter
        case '1':
            // Parse text into lines
            while (getline(file, line)) {
                index = 0;
                stringstream ss(line);
                while (ss >> word) {
                    // Run into first word
                    if (word == "{") {
                        in_complex = true;
                        break;
                    
                    // Reached the end of compound path
                    } else if (word == "}") {
                        in_complex = false;
                        catalog.AddTrajetCompose(complex);
                        break;
                    // If pure simple path
                    } else if (word == "TS:" && !in_complex) {
                        cur_simple = true;
                        cur_complex = false;
                    // If compound path
                    } else if (word == "TC:") {
                        cur_complex = true;
                        cur_simple = false;
                    // If simple path contained in a compound path
                    } else if (word == "TS:") {
                        cur_simple = true;
                    }

                    // The condition specify that
                    // 1, Every route within the brackets {} are a part of a Compound Trajet
                    
                    // If cur_simple is true and cur_complex is false, we are treating a Simple Trajet
                    if (!cur_complex && cur_simple) {
                        if (index == 1) {
                            depart = word;
                        } else if (index == 3) {
                            arrivee = word;
                        } else if (index == 5) {
                            modeTransport = word;
                            catalog.AddTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                        }
                    }

                    // If cur_simple is false and cur_complex is true, we are treating a Compound Trajet
                    if (cur_complex && !cur_simple) {
                        if (index == 1) {
                            depart = word;
                        } else if (index == 3) {
                            arrivee = word;
                            complex = new TrajetCompose(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()));
                        }
                    }

                    // If cur_simple is true and cur_complex is true, we are treating a Simple Trajet in a Compound Trajet
                    if (cur_complex && cur_simple) {
                        if (index == 1) {
                            depart = word;
                        } else if (index == 3) {
                            arrivee = word;
                        } else if (index == 5) {
                            modeTransport = word;
                            complex->addTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                        }
                    }
                    index += 1;
                }
            }
            break;
        
        // Filter simple or compound path
        case '2':
            cout << endl;
            cout << "Type 0 for Simple Path, any other key for Compound Path" << endl;
            cin >> e;

            bool chooseSimple;

            // If choose to select only simple paths
            if (e =='0') {
                chooseSimple = true;
            // If not
            } else {
                chooseSimple = false;
            }

            while (getline(file, line)) {
                index = 0;
                stringstream ss(line);
                while (ss >> word) {
                    // Run into first word
                    if (word == "{") {
                        in_complex = true;
                        break;
                    } else if (word == "}") {
                        // Reached the end of compound path
                        in_complex = false;
                        if (!chooseSimple) {
                            catalog.AddTrajetCompose(complex); 
                        } else {
                            delete complex;
                        }
                        break;
                    } else if (word == "TS:" && !in_complex) {
                        cur_simple = true;
                        cur_complex = false;
                    } else if (word == "TC:") {
                        cur_complex = true;
                        cur_simple = false;
                    } else if (word == "TS:") {
                        cur_simple = true;
                    }

                    // The condition specify that
                    // 1, Every route within the brackets {} are a part of a Compound Trajet
                    
                    // If cur_simple is true and cur_complex is false, we are treating a Simple Trajet
                    if (!cur_complex && cur_simple && chooseSimple) {
                        if (index == 1) {
                            depart = word;
                        } else if (index == 3) {
                            arrivee = word;
                        } else if (index == 5) {
                            modeTransport = word;
                            catalog.AddTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                        }
                    }

                    // If cur_simple is false and cur_complex is true, we are treating a Compound Trajet
                    if (cur_complex && !cur_simple) {
                        if (index == 1) {
                            depart = word;
                        } else if (index == 3) {
                            arrivee = word;
                            complex = new TrajetCompose(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()));
                        }
                    }

                    // If cur_simple is true and cur_complex is true, we are treating a Simple Trajet in a Compound Trajet
                    if (cur_complex && cur_simple) {
                        if (index == 1) {
                            depart = word;
                        } else if (index == 3) {
                            arrivee = word;
                        } else if (index == 5) {
                            modeTransport = word;
                            complex->addTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                        }
                    }

                    
                    index += 1;
                }
            }

            break;
        
        // Departure and arrival filter
        case '3':
            cout << endl;
            cout << "Choose your condition: (0) Departure   (1) Arrival   (2) Both" << endl;

            while (cin >> s1) {
                
                quit = true;

                switch (s1)
                {
                case '0':
                    cout << "Match departure city" << endl;
                    cin >> departureCity;
                    
                    while (getline(file, line)) {
                        index = 0;
                        stringstream ss(line);
                        while (ss >> word) {
                            // Run into first word
                            if (word == "{") {
                                in_complex = true;
                                break;
                            } else if (word == "}") {
                                // Reached the end of compound path
                                in_complex = false;
                                if (depart_complex == departureCity) {
                                    catalog.AddTrajetCompose(complex);
                                } else {
                                    delete complex;
                                }
                                break;
                            } else if (word == "TS:" && !in_complex) {
                                cur_simple = true;
                                cur_complex = false;
                            } else if (word == "TC:") {
                                cur_complex = true;
                                cur_simple = false;
                            } else if (word == "TS:") {
                                cur_simple = true;
                            }

                            // The condition specify that
                            // 1, Every route within the brackets {} are a part of a Compound Trajet
                            
                            // If cur_simple is true and cur_complex is false, we are treating a Simple Trajet
                            if (!cur_complex && cur_simple) {
                                if (index == 1) {
                                    depart = word;
                                } else if (index == 3) {
                                    arrivee = word;
                                } else if (index == 5) {
                                    modeTransport = word;
                                    if (depart == departureCity) {
                                        catalog.AddTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                                    }
                                }
                            }

                            // If cur_simple is false and cur_complex is true, we are treating a Compound Trajet
                            if (cur_complex && !cur_simple) {
                                if (index == 1) {
                                    depart_complex = word;
                                } else if (index == 3) {
                                    arrivee_complex = word;
                                    complex = new TrajetCompose(const_cast<char*>(depart_complex.c_str()), const_cast<char*>(arrivee_complex.c_str()));
                                }
                            }

                            // If cur_simple is true and cur_complex is true, we are treating a Simple Trajet in a Compound Trajet
                            if (cur_complex && cur_simple) {
                                if (index == 1) {
                                    depart = word;
                                } else if (index == 3) {
                                    arrivee = word;
                                } else if (index == 5) {
                                    modeTransport = word;
                                    complex->addTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                                }
                            }
                            index += 1;
                        }
                    }

                    break;

                case '1':
                    cout << "Match arrival city" << endl;
                    cin >> arrivalCity;

                    while (getline(file, line)) {
                        index = 0;
                        stringstream ss(line);
                        while (ss >> word) {
                            // Run into first word
                            if (word == "{") {
                                in_complex = true;
                                break;
                            } else if (word == "}") {
                                // Reached the end of compound path
                                in_complex = false;
                                if (arrivee_complex == arrivalCity) {
                                    catalog.AddTrajetCompose(complex);
                                } else {
                                    delete complex;
                                }
                                break;
                            } else if (word == "TS:" && !in_complex) {
                                cur_simple = true;
                                cur_complex = false;
                            } else if (word == "TC:") {
                                cur_complex = true;
                                cur_simple = false;
                            } else if (word == "TS:") {
                                cur_simple = true;
                            }

                            // The condition specify that
                            // 1, Every route within the brackets {} are a part of a Compound Trajet
                            
                            // If cur_simple is true and cur_complex is false, we are treating a Simple Trajet
                            if (!cur_complex && cur_simple) {
                                if (index == 1) {
                                    depart = word;
                                } else if (index == 3) {
                                    arrivee = word;
                                } else if (index == 5) {
                                    modeTransport = word;
                                    if (arrivee == arrivalCity) {
                                        catalog.AddTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                                    }
                                }
                            }

                            // If cur_simple is false and cur_complex is true, we are treating a Compound Trajet
                            if (cur_complex && !cur_simple) {
                                if (index == 1) {
                                    depart_complex = word;
                                } else if (index == 3) {
                                    arrivee_complex = word;
                                    complex = new TrajetCompose(const_cast<char*>(depart_complex.c_str()), const_cast<char*>(arrivee_complex.c_str()));
                                }
                            }

                            // If cur_simple is true and cur_complex is true, we are treating a Simple Trajet in a Compound Trajet
                            if (cur_complex && cur_simple) {
                                if (index == 1) {
                                    depart = word;
                                } else if (index == 3) {
                                    arrivee = word;
                                } else if (index == 5) {
                                    modeTransport = word;
                                    complex->addTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                                }
                            }

                            
                            index += 1;
                        }
                    }

                    break;

                case '2':
                    cout << "Match departure and arrival city" << endl;
                    cout << "Departure:" << endl;
                    cin >> departureCity;
                    cout << "Arrival:" << endl;
                    cin >> arrivalCity;

                    while (getline(file, line)) {
                        index = 0;
                        stringstream ss(line);
                        while (ss >> word) {
                            // Run into first word
                            if (word == "{") {
                                in_complex = true;
                                break;
                            } else if (word == "}") {
                                // Reached the end of compound path

                                in_complex = false;
                                if (depart_complex == departureCity && arrivalCity == arrivee_complex) {
                                    catalog.AddTrajetCompose(complex);
                                } else {
                                    delete complex;
                                }
                                break;
                            } else if (word == "TS:" && !in_complex) {
                                cur_simple = true;
                                cur_complex = false;
                            } else if (word == "TC:") {
                                cur_complex = true;
                                cur_simple = false;
                            } else if (word == "TS:") {
                                cur_simple = true;
                            }

                            // The condition specify that
                            // 1, Every route within the brackets {} are a part of a Compound Trajet
                            
                            // If cur_simple is true and cur_complex is false, we are treating a Simple Trajet
                            if (!cur_complex && cur_simple) {
                                if (index == 1) {
                                    depart = word;
                                } else if (index == 3) {
                                    arrivee = word;
                                } else if (index == 5) {
                                    modeTransport = word;
                                    if (depart == departureCity && arrivee == arrivalCity) {
                                        catalog.AddTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                                    }
                                }
                            }

                            // If cur_simple is false and cur_complex is true, we are treating a Compound Trajet
                            if (cur_complex && !cur_simple) {
                                if (index == 1) {
                                    depart_complex = word;
                                } else if (index == 3) {
                                    arrivee_complex = word;
                                    complex = new TrajetCompose(const_cast<char*>(depart_complex.c_str()), const_cast<char*>(arrivee_complex.c_str()));
                                }
                            }

                            // If cur_simple is true and cur_complex is true, we are treating a Simple Trajet in a Compound Trajet
                            if (cur_complex && cur_simple) {
                                if (index == 1) {
                                    depart = word;
                                } else if (index == 3) {
                                    arrivee = word;
                                } else if (index == 5) {
                                    modeTransport = word;
                                    complex->addTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                                }
                            }
                            index += 1;
                        }
                    }

                    break;

                default:
                    quit = false;
                    cout << "Invalid response, retry" << endl;
                }

                if (quit) break;
            }

            break;
        
        // Filter using index range
        case '4':
            int n, m;
            pathIndex = 0;
            
            while (1) {
                cout << endl;
                cout << "Index range [n, m] inclusive" << endl;
                cout << "First path has index 0, second with index 1, and so on." << endl;
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

            
            while (getline(file, line)) {
                index = 0;
                pathInc = false;
                bool inRange = false;
                stringstream ss(line);

                while (ss >> word) {
                    
                    if (pathIndex >= n && pathIndex <= m) {
                        inRange = true;
                    }

                    // Run into first word

                    if (word == "{") {
                        in_complex = true;
                        pathInc = false;
                        break;
                    } else if (word == "}") {
                        // Reached the end of compound path
                        in_complex = false;
                        pathInc = true;
                        if (inRange) {
                            catalog.AddTrajetCompose(complex);
                        } else {
                            delete complex;
                        }
                        break;
                    } else if (word == "TS:") {
                        cur_simple = true;
                        cur_complex = true;
                        pathInc = false;
                        if (!in_complex) {
                            cur_complex = false;
                            pathInc = true;
                            
                        }

                    } else if (word == "TC:") {
                        cur_complex = true;
                        cur_simple = false;
                        pathInc = false;
                        
                    }

                    


                    
                    // If purely simple path, i.e, if cur_simple is true and cur_complex is false
                    if (!cur_complex && cur_simple) {
                        if (index == 1) {
                            depart = word;
                        } else if (index == 3) {
                            arrivee = word;
                        } else if (index == 5) {
                            modeTransport = word;
                            if (inRange) {
                                catalog.AddTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                            }
                        }
                    }

                    // If simple path inside a compound path, i.e., cur_simple is true and cur_complex is true
                    if (cur_complex && cur_simple) {
                        if (index == 1) {
                            depart = word;
                        } else if (index == 3) {
                            arrivee = word;
                        } else if (index == 5) {
                            modeTransport = word;
                            complex->addTrajetSimple(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()), const_cast<char*>(modeTransport.c_str()));
                        }
                    }

                    // If compound path, i.e., if cur_simple is false and cur_complex is true
                    if (cur_complex && !cur_simple) {
                        if (index == 1) {
                            depart = word;
                        } else if (index == 3) {
                            arrivee = word;
                            complex = new TrajetCompose(const_cast<char*>(depart.c_str()), const_cast<char*>(arrivee.c_str()));
                        }
                    }     
                    index += 1;
                }
                if (pathInc) pathIndex += 1;
            }

            // If some index is out of range, show message
            if (n >= pathIndex || m >= pathIndex || n < 0 || m < 0) {
                cout << endl;
                cout << "Warning: Index out of range, loaded what's in range" << endl;
            }

            break;
        
        default:
            cout << "Invalid input, retry" << endl;
            // Set quit to false and redo the while loop
            quit = !quit;
        }
    }

    return 0;
    
}




//-------------------------------------------- Constructeurs - destructeur
// Algorithme :
// Constructor of an empty catalogue 
Catalogue::Catalogue() {
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif        
} //----- Fin de Catalogue

// Algorithme :
// Destructor of Catalogue at the end of the program cycle
Catalogue::~Catalogue() 
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

} //----- Fin de ~Catalogue