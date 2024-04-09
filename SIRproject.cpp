#include <iostream>
#include <string>
#include <cmath>
#include "sirdata.hpp"
#include "sirmodel.hpp"
#include "sirmanage.hpp"
#include "sirmodelextended.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <cmath>

using namespace std;
using namespace Sirmodel;


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

   int duration;
   double beta, gamma, alpha;
   int susc = 0, inf=0, rec=0;
   string r;
   vector<sirdata> results;

   try {
    sirmanage *file = new sirmanage("sirmodel.cfg");

    //LEGGI BETA e GAMMA e ALFA
    r = file -> read_row_fromfile();
    if(r != "") {beta = atof(r.c_str());}

    r = file -> read_row_fromfile();
    if(r != "") {gamma = atof(r.c_str());}

    r = file -> read_row_fromfile();
    if(r != "") {alpha = atof(r.c_str());}

    // LEGGI S,I,R
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
    cout << "r:"<<r<<endl;

    // SETTO LO STATO INZIALE
    sirdata *initial_state = new sirdata(susc, inf, rec);
    if(r.compare("sirmodel")){
       cout << beta<< endl;
        cout << gamma<< endl;
        cout << beta/gamma<< endl; 
        sirmodel *f = new sirmodel(beta, gamma);
        f->set_state(initial_state);
        results = f-> generate_data(duration);
        
    }
    else {
        sirmodelextended *ex = new sirmodelextended(beta, gamma, alpha);
        ex->set_state(initial_state);
        results = ex->generate_data(duration);
        cout << "ok"<<endl;
    }
    for (auto &data : results) file ->printdata(data);
    
   }
   catch(const char *message){
    cout << message << endl;
   }
   
   

  /*try{
        sirmodel *ex = new sirmodel(0.4,0.5);
        cout << ex->get_beta() << endl;
        cout << ex->get_gamma() << endl;
        //cout << ex->get_alpha() << endl;
        ex->generate_data(10);
    }
    catch(const char *message){
        cout << message<< endl;
    }
    return 0;  
  */  
} 


