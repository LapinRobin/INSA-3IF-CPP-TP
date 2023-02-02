/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : 03/01/2023
    copyright            : (C) 2023 par NGUYEN Le Tuan Khai, SU Yikang
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Stats> (fichier Stats.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <sstream>
#include "Flux.h"

//------------------------------------------------------ Include personnel
#include "Stats.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


Connection Stats::request_to_connection(Request re)
// Alogrithme :
// Parse the Request object into a Connection object
{
    // Creating a new connection instance
    Connection con;
    string s = re.reference;
    string word, small_word;
    
    // Getting rid of GET, POST, etc...
    string s_target = re.target.substr(1, re.target.length()-2);
    stringstream ss1(s_target);
    getline(ss1, word, ' ');
    getline(ss1, word, ' ');

    // Dealing with ? in the target
    stringstream ss2(word);
    getline(ss2, small_word, '?');
    con.target = small_word;
    
    // Shortening the reference
    std::regex r("//");
    std::sregex_iterator it(s.begin(), s.end(), r);
    std::sregex_iterator end;
    string sub = "-";
    int last = -1;
    vector<int> slash_placement;
    while (it != end) {
        last = it->position();
        slash_placement.push_back(it->position());
        ++it;
    }

    // Dealing with the reference
    if(slash_placement.size() == 1){
        sub = s.substr(slash_placement[0], s.length()-slash_placement[0]);
        stringstream ss(sub);
        getline(ss, word, '/');
        getline(ss, word, '/');
        getline(ss,word, '/');
        getline(ss, word);
        sub = "/" + word.substr(0, word.length()-1);   
    }else if(slash_placement.size() > 0){
        sub = s.substr(slash_placement[0], s.length() - slash_placement[0]);
        stringstream sss(sub);
        getline(sss, word, '/');
        getline(sss, word, '/');
        getline(sss,word, '/');
        sub = "/" + word.substr(0, word.length());  

    }

    con.reference = sub;

    return con;
} //----- Fin de Méthode

void Stats::read_file(string path, int option_e, int option_t)
// Algorithme :
// Read the file and store the data in the map
{
    string line, word;
    ifstream file(path);
    Flux flux;
    Request re;
    string ret_code;
    Connection con;

    if (file.is_open()) {
        while (getline(file, line)) {
            re = flux.Read_line(line);  
            con = request_to_connection(re);
            ret_code = re.data_size;
            // Filter for return codes with 4xx or 5xx
            if (ret_code[0] == '4' || ret_code[0] == '5') {
                continue;
            }

            // Filter for extensions
            if(option_e >= 0){
                string extensions[] = {".jpg", ".jpeg", ".png", ".gif", ".bmp", ".jpeg", ".css", ".js", ".ico"};
                bool exclusion = false;
                
                // If fileExt out of range
                if (con.target.find_last_of(".") != string::npos) {
                    string fileExt = con.target.substr(con.target.find_last_of("."));

                    // Check if fileExt is in the array
                    for (const auto& ext : extensions) {
                        if (fileExt == ext) {
                            exclusion = true;
                            break;
                        }
                    }
                    if (exclusion) continue;
                }
            }


            // Filter for time intervals
            if(option_t >= 0){
                string time = re.time;
                string word;
                stringstream ss(time);

                getline(ss, word, ':');
                getline(ss, word, ':');

                int actual_hour = stoi(word);
            

                if (actual_hour != option_t) {
                    continue;
                }
            }

            
            if (connectMap.count(con) > 0) {
                connectMap[con] += 1;
            } else {
                connectMap[con] = 1;
            }

            if (nodeMap.count(con.target) > 0){
                nodeMap[con.target] += 1;
            }else{
                nodeMap[con.target] = 1;
            }

            if (nodeMap.count(con.reference) == 0){
                nodeMap[con.reference] = 0;
            }
        }
        file.close();
    }else {
        cout << "Unable to open file";
    }
} //----- Fin de Méthode

void Stats::write_to_file(string path, map<string, string>& labelMap)
// Algorithme :
// Open, write and close the file
{
    ofstream file(path);
    if (file.is_open()) {
        file << "digraph {" << std::endl;

        for(auto it = labelMap.begin(); it != labelMap.end(); it++){
            file << it->second << " [label=" << '"' << it->first << '"' << "];" << endl;
        }

        for(auto it = connectMap.begin(); it != connectMap.end(); it++){
            file << labelMap[it->first.reference] << " -> " << labelMap[it->first.target] << "[label=" << '"' << it->second << '"' << "];" << endl;
        }

        file << "}" << endl;
        file.close();
        cout << "Dot-file " << path << " generated" << endl;
    } else {
        std::cout << "Failed to open file" << std::endl;
    }

}

void Stats::full_response(string read, string write, int option_e = -1, int option_t = -1)
// Algorithme :
// Read the file, sort the map, write the file, print first 10 elements
{
    read_file(read, option_e, option_t);

    // Sorting the map by value
    vector<pair<string, int> > vec(nodeMap.begin(), nodeMap.end());
    sort(vec.begin(), vec.end(), CompareByValue());

    
    // Creating the new map
    int index = 0;
    string label;
    map<string, string> labelMap;
    for(const pair<string, int>& item : vec) {
        label = "node" + to_string(index);
        labelMap[item.first] = label;
        index ++;
    }

    // Writing the file
    write_to_file(write, labelMap);

    // Printing the first 10 elements   
    index = 0;
    for (const pair<string, int>& item : vec) {
        if (index == 10){
            break;
        }
        std::cout << item.first << " : " << item.second << std::endl;
        index ++;
    }
} //----- Fin de Méthode

void Stats::console_response(string read, int option_e = -1, int option_t = -1)
// Algorithme :
// Display the 10 most requested pages in the console
{
    read_file(read, option_e, option_t);

    // Sorting the map by value
    vector<pair<string, int> > vec(nodeMap.begin(), nodeMap.end());
    sort(vec.begin(), vec.end(), CompareByValue());

    // Printing the first 10 elements
    int index = 0;
    for (const pair<string, int>& item : vec) {
        if(index == 10){
            break;
        }
        std::cout << item.first << " : " << item.second << std::endl;
        index ++;
    }
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Stats::Stats ( const Stats & unStats )
// Algorithme :
// Constrctor by copy
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Stats>" << endl;
#endif
} //----- Fin de Stats (constructeur de copie)


Stats::Stats ( )
// Algorithme :
// Default constructor
{
#ifdef MAP
    cout << "Appel au constructeur de <Stats>" << endl;
#endif
} //----- Fin de Stats


Stats::~Stats ( )
// Algorithme : 
// Destructor
{
#ifdef MAP
    cout << "Appel au destructeur de <Stats>" << endl;
#endif
} //----- Fin de ~Stats


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

