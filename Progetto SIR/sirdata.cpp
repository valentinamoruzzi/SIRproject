#include "sirdata.hpp"
#include <cmath>
#include <iostream>

using namespace std;

 sirdata::sirdata(int suscettibili, int infetti, int rimossi){
        
        set_susc(suscettibili);
        set_inf(infetti);
        set_rim(rimossi);
        set_pop(suscettibili+ infetti+ rimossi);
    }

int sirdata::get_susc() {return susc;}
void sirdata::set_susc(const int suscettibili) {
    
    if (suscettibili < 0) 
        throw "Errore suscettibili minore di 0";
    else 
        susc = suscettibili;}

int sirdata::get_inf() {return inf;}
void sirdata::set_inf(const int infetti) {
       if (infetti < 0) 
        throw "Errore infetti minore di 0";
    else 
        inf = infetti;}

int sirdata::get_rim() {return rim;}
void sirdata::set_rim(const int rimossi) {
       if (rimossi < 0) 
        throw "Errore rimosssi minore di 0";
    else 
        rim = rimossi;}

int sirdata::get_pop() {return pop;}
void sirdata::set_pop(int population) {
       if (population < 0) 
        throw "Errore popolazione minore di 0";
    else 
        pop = population;}

bool sirdata::check_pop(){

    if (pop == susc + inf + rim) 
    return true;
    else 
    return false;
}
