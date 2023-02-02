/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : 03/01/2023
    copyright            : (C) 2023 par NGUYEN Le Tuan Khai, SU Yikang
    e-mail               : le.nguyen@insa-lyon.fr, yikang.su@insa-lyon.fr
*************************************************************************/
//---------- Réalisation de la classe <Stats> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Stats.h"
#include "Stats.h"
#include "Flux.h"
using namespace std;

//------------------------------------------------------------- PUBLIC
int main(int argc, char* argv[]) 
// Algorithme :
// Main function of the program
{
    bool check_graph = false, check_file_graph = false, check_except = false, check_time_cond = false, check_time = false, check_read_log = false;

    string file_graph;
    string file_log;
    string argument;
    int hour = -1;
    for (int i = 1; i < argc; i++) {
        
        argument = string(argv[i]);

        if(argument == "-g"){
            
            check_graph = true;

        }else if(argument == "-e"){
            
            check_except = true;

        }else if(argument == "-t"){
            
            check_time = true;

        }else if(argument.rfind(".dot") == argument.length() - 4 && argument.length() >= 4){
            // Check if there is more than one .dot file
            if(check_file_graph){
                // More than one .dot file
                cout << "[Warning] Output is more than 1 file. Keeping the name of the original file" << endl;
            }else{
                check_file_graph = true;
                file_graph = argument;
            }

        }else if(argument.rfind(".log") == argument.length() - 4 && argument.length() >= 4){
            if(check_read_log){
                // More than one .log file
                cout << "[Warning] Input is more than 1 file. Reading only the first file" << endl;
            }else{
                check_read_log = true;
                file_log = argument;
            }
            
        }else{
            stringstream ss(argument);
            if(ss >> hour){   
                check_time_cond = true;
                int i = 1;
                // Take number of character of hour
                while(true){
                    if(hour < pow(10,i) && hour >= 0){
                        break;
                    }else if(abs(hour) < pow(10,i)){
                        i++;
                        break;
                    }
                    i++;
                }

                // Compare to length or argument
                if(i != argument.length()){
                    cout << "[Warning] Command not recognized [" + argument + "]" << endl;
                    hour = -1;
                    check_time_cond = false;
                }

            }else{
                cout << "[Warning] Command not recognized [" + argument + "]" << endl;
            }
        }
        
    }

    // Check -g -t intergrities
    if(check_graph && !check_file_graph){
        cout << "[Error] No output file." << endl;
        exit (1);
    }else if(!check_graph && check_file_graph){
        cout << "[Warning] No [-g] option but there exists a .dot file. Program will not output." << endl;
    }

    if(check_time && !check_time_cond){
        cout << "[Error] No time condition" << endl;
        exit (1);
    }
        
    if(!check_time && check_time_cond){
        cout << "[Warning] No [-t] option but there exist a target time. Will not filter." << endl;
    }

    if(check_time && check_time_cond && (hour > 23 or hour < 0)){
        cout << "[Error] Time of [" + to_string(hour) + "] not within correct interval." << endl;
        exit (1);
    }

        
    // Check if .log can be opened
    if(check_read_log){
        ifstream file(file_log);
        if(!file.good()){
            cerr << "[Error] Log file doesn't exist." << endl;
        exit (1);
        }
    }else{
        cerr << "[Error] No log to read from." << endl;
        exit (1);
    }


    Stats stats;
    // Start of program

    // if check_graph is true, then do the following
    if(check_graph) {
        
        // 111
        if(check_except and check_time){
            stats.full_response(file_log, file_graph, 0, hour);
        }

        // 110
        if(check_except and !check_time){
            stats.full_response(file_log, file_graph, 0, -1);
        }

        // 101
        if(!check_except and check_time){
            stats.full_response(file_log, file_graph, -1, hour);
        }

        // 100
        if(!check_except and !check_time){
            stats.full_response(file_log, file_graph, -1, -1);
        }

    } else {

        // 011
        if(check_except and check_time){
            stats.console_response(file_log, 0, hour);
        }

        // 010
        if(check_except and !check_time){
            stats.console_response(file_log, 0, -1);
        }

        // 001
        if(!check_except and check_time){
            stats.console_response(file_log, -1, hour);
        }

        // 000
        if(!check_except and !check_time){
            stats.console_response(file_log, -1, -1);
        }

    }
    return 0;
}