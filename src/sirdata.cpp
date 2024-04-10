#include "sirdata.hpp"
#include <iostream>
#include <sstream>

using namespace std;


 sirdata::sirdata(const int &susceptibles, const int &infected, const int&recovered){
        
        set_susc(susceptibles);
        set_inf(infected);
        set_rec(recovered);
        set_pop(susceptibles + infected + recovered);
    }

int sirdata::get_susc() {return susc;}
void sirdata::set_susc( const int &susceptibles) {
    
    if (susceptibles < 0) 
        throw "Error: susceptibles less than 0\n";
    else 
        susc = susceptibles;}

int sirdata::get_inf() {return inf;}
void sirdata::set_inf( const int &infected) {
       if (infected < 0) 
        throw "Error: infected less than 0\n";
    else 
        inf = infected;}

int sirdata::get_rec() {return rec;}
void sirdata::set_rec( const int &recovered) {
       if (recovered < 0) 
        throw "Error: recovered less than 0\n";
    else 
        rec = recovered;}

int sirdata::get_pop() {return pop;}
void sirdata::set_pop(const int &population) {
       if (population < 0) 
        throw "Error: population less than 0\n";
    else 
        pop = population;}

bool sirdata::check_pop(){

    if (get_pop() == get_susc() + get_inf() + get_rec()) 
    return true;
    else 
    return false;
}

string sirdata::toString() {
    
    stringstream ss;
    ss << get_susc()<< ";"<< get_inf() << ";" << get_rec() << endl;
    return ss.str();
}

bool sirdata::operator == (sirdata d) {
    if(d.get_susc() == get_susc() && d.get_inf() == get_inf() && d.get_rec() == d.get_rec()) return true;
    else return false;
}
