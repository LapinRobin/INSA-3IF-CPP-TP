using namespace std;
#include <iostream>
#include "Ensemble.h"

int main() {
    int tab1[4] = {-20,5,99};
    int tab2[7] = {-22,0,2,4,97,98,99};
    int tab3[1] = {1};
    Ensemble e0;
    Ensemble e1(0);
    Ensemble e2(10);
    Ensemble e3(tab1, 3);
    Ensemble e4(tab2, 7);
    Ensemble e5(tab3, 1);
    // Ensemble e3(tab, 10);
    
    e0.Afficher();
    // e1.Afficher();
    // e2.Afficher();
    e3.Afficher();
    e4.Afficher();
    cout<<e4.EstInclus(e3)<<endl;
    cout<<e4.Reunir(e3)<<endl;
    e4.Afficher();

    // if (e3.EstEgal(e4)) {
    //     cout<<"yes"<<endl;
    // } else {
    //     cout<<"no"<<endl;
    // }


    
    return 0;

}