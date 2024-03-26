#include "sirdata.hpp"
#include "sirmodel.hpp"
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

sirmodel::sirmodel (){
    set_beta(0.5);
    set_gamma(0.5);
}

sirmodel::sirmodel (const double b, const double g){
    set_beta(b);
    set_gamma(g);
}

sirmodel::sirmodel (sirdata *state, const double b, const double g){
    set_state(state);
    set_beta(b);
    set_gamma(g);
}

sirdata* sirmodel::get_state() {return state;}
void sirmodel::set_state(sirdata *s)        
    {if (s == NULL)
        throw "Errore state";
    else state = s;
    }
double sirmodel::get_beta() {return beta;}
void sirmodel::set_beta(const double b) 
{if (b < 0 && b>1)
        throw "Errore beta";
    else 
        beta = b;
    }
double sirmodel::get_gamma() {return gamma;}
void sirmodel::set_gamma(const double g)
    {if (g < 0 && g>1)
        throw "Errore gamma";
    else 
        gamma = g;
    }
vector<sirdata> sirmodel::generate_data(int duration) {
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
            int newrec = (int)(gamma*state_i ->get_inf());

            state_i -> set_susc(state_i -> get_susc()- newinf);
            state_i -> set_inf(state_i -> get_inf() + newinf - newrec); //riguarda 
            state_i -> set_rec(state_i ->get_rec() + newrec);

            cout << "Tempo " << i+1 << endl;
            state->toString();

        if(!state->check_pop())
            throw "Errore: valore popolazione non corrisponde alla somma di s,r,i!";
        result.push_back(*state);

        }
    }
return result;
}
    