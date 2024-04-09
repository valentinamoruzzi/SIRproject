#include "sirmodelextended.hpp"
#include <iostream>

using namespace std;

namespace Sirmodel{
    sirmodelextended::sirmodelextended(){

        set_alpha(ALPHA_DEFAULT);
        set_R0();
    }

    sirmodelextended::sirmodelextended(double a) {

        set_alpha(a);
        set_R0();

    }

    sirmodelextended::sirmodelextended( double b, double g, double a){

        set_beta(b);
        set_gamma(g);
        set_alpha(a);
        set_R0();
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
        cout << "Tempo 0:"<< endl;
        cout << "S:"<< state->get_susc()<< endl;
        cout <<"I:"<< state ->get_inf() << endl;
        cout << "R:" << state ->get_rec() << endl;

        const int pop_now = state ->get_pop(); //now
        for (int i = 0; i < duration; i++ ){

            sirdata *state_i = &result.back();
            const int newinf = (int)((get_beta()*state_i->get_susc()* state_i->get_inf())/pop_now);
            const int newrec = (int)(get_gamma()*state_i->get_inf());
            const int newsusc = (int)(get_alpha()*state_i ->get_rec());

            state -> set_susc(state_i -> get_susc()- newinf + newsusc);
            state -> set_inf(state_i -> get_inf() + newinf - newrec); 
            state -> set_rec(state_i -> get_rec() + newrec - newsusc);


        if(!state->check_pop())
            throw "Errore: valore popolazione non corrisponde alla somma di s,r,i!";
        result.push_back(*state);

        }
    }
return result;
}
    }

