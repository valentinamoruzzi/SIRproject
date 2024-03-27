#include "sirmodelextended.hpp"
#include <iostream>

using namespace std;

namespace sirmodel{
    sirmodelextended::sirmodelextended(){

        set_alpha(ALPHA_DEFAULT);
    }

    sirmodelextended::sirmodelextended(double a) {

        set_alpha(a);

    }

    sirmodelextended::sirmodelextended( double b, double g, double a){

        set_beta(b);
        set_gamma(g);
        set_alpha(a);
    }

    double sirmodelextended::get_alpha() {return alpha;}
    void sirmodelextended::set_alpha(double a)
    {if (a < 0 && a>1)
        throw "Error: the value of alpha is not correct";
    else 
        alpha = a;
    }

    vector<sirdata> sirmodelextended::generate_data(int duration){
         vector<sirdata> result;
    if (state != NULL)
    {
        result.push_back(*state); // serve l'asterisco perché solo state è gia un puntatore
        cout << "Tempo =:"<< endl;
        cout << "S:"<< state->get_susc()<< endl;
        cout <<"I:"<< state ->get_inf() << endl;
        cout << "R:" << state ->get_rec() << endl;

        const int pop_now = state ->get_pop(); //now
        for (int i = 0; i < duration; i++ ){

            sirdata *state_i = &result.back();
            int newinf = round((beta/pop_now) * state_i ->get_susc()* state_i ->get_inf());
            int newrec = (int)(gamma * state_i ->get_inf());
            int newsusc = (int)(alpha * state_i ->get_rec()); 

            state_i -> set_susc(state_i -> get_susc()- newinf + newsusc);
            state_i -> set_inf(state_i -> get_inf() + newinf - newrec); //riguarda 
            state_i -> set_rec(state_i ->get_rec() + newrec - newsusc);

            cout << "Tempo " << i+1 << endl;
            state->toString();

        if(!state->check_pop())
            throw "Errore: valore popolazione non corrisponde alla somma di s,r,i!";
        result.push_back(*state);

        }
    }
return result;
}
    }

