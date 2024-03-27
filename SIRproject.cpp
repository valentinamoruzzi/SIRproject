#include <iostream>
#include<string>
#include<cmath>
#include"sirdata.hpp"
#include"sirmodel.hpp"
#include "sirmanage.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;
using namespace sirmodel;


int main () {
    /*
     try
    {
        char a;
        sirmodel *m = new sirmodel(0.6,0.5);
        sirdata *initial_state = new sirdata(5000,98,2);
        m->set_state(initial_state);
        vector<sirdata> results = m->generate_data(1000);

        for(int i=0; i<1000; i++)
        {
            results[i].toString();
        }
    }
    catch(const char *message){
        cout << "Errore: " << message;
    }
    */

   /* int duration;
   double beta, gamma;
   int susc, inf, rec;
   string r;
   vector<sirdata> results;

   try {
    sirmanage *file = new sirmanage("sirmodel.cfg");

    //LEGGI BETA e GAMMA
    r = file -> read_row_fromfile();
    if(r != "") {beta = atof(r.c_str());}

    r = file -> read_row_fromfile();
    if(r != "") {gamma = atof(r.c_str());}

    // LEGGI S,R,I
    r = file -> read_row_fromfile();
    if(r !="") {susc = stoi(r.c_str(), 0, 10); }

     r = file -> read_row_fromfile();
    if(r !="") {inf = stoi(r.c_str(), 0, 10); }

     r = file -> read_row_fromfile();
    if(r !="") {rec = stoi(r.c_str(), 0, 10); }

    //LEGGI DURATA 
     r = file -> read_row_fromfile();
    if(r !="") {duration = stoi(r.c_str(), 0, 10); }

    // LEGGI MODELO
    r = file -> read_row_fromfile();

    // SETTO LO STATO INZIALE
    sirdata *initial_state = new Sirdata(susc, inf, rec);
    if(r.compare("sirmodel")){
        sirmodel *f = new sirmodel(beta, gamma);
        f ->setstate(initiel_state);
        result= m -> generate_data(duration);
    }
    else {
        sirmodelextended *ex = new sirmpdelextende(beta, gamma, delta);
        ex->set_state(initial_state);
        results = ex->generate_data(duration);
    }
    for (auto &data : results) file ->printdata(data);
   }
   catch(const char *message){
    cout << message << endl;
   }
   
   */
    
} 


