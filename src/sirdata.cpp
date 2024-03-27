#include "sirdata.hpp"
#include <iostream>

using namespace std;

namespace sirmodel {
 sirdata::sirdata(int susceptibles, int infected, int recovered){
        
        set_susc(susceptibles);
        set_inf(infected);
        set_rec(recovered);
        set_pop(susceptibles + infected + recovered);
    }

int sirdata::get_susc() {return susc;}
void sirdata::set_susc( int susceptibles) {
    
    if (susceptibles < 0) 
        throw "Error: susceptibles less than 0\n";
    else 
        susc = susceptibles;}

int sirdata::get_inf() {return inf;}
void sirdata::set_inf( int infected) {
       if (infected < 0) 
        throw "Error: infected less than 0\n";
    else 
        inf = infected;}

int sirdata::get_rec() {return rec;}
void sirdata::set_rec( int recovered) {
       if (recovered < 0) 
        throw "Error: recovered less than 0\n";
    else 
        rec = recovered;}

int sirdata::get_pop() {return pop;}
void sirdata::set_pop(int population) {
       if (population < 0) 
        throw "Error: population less than 0\n";
    else 
        pop = population;}

bool sirdata::check_pop(){

    if (pop == susc + inf + rec) 
    return true;
    else 
    return false;
}

void sirdata::toString() {
    
    cout << "S:"<< get_susc()<< endl;
    cout <<"I:"<< get_inf() << endl;
    cout << "R:" << get_rec() << endl;
}

bool sirdata::operator == (sirdata d) {
    if(d.get_susc() == get_susc() && d.get_inf() == get_inf() && d.get_rec() == d.get_rec()) return true;
    else return false;
}
}