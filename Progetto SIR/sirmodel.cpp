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
    set_state(sirdata *state);
    set_beta(b);
    set_gamma(g);
}

sirmodel::sirdata* get_state() {return state;}
sirmodel::void set_state(sirdata *s)        
    {if (s = NULL)
        throw "Errore state";
    else s = state;
    }
double get_beta() {return beta;}
void set_beta(const double b) {if (b < 0 && b>1)
        throw "Errore beta";
    else 
        b = beta;
    }
double get_gamma() {return gamma;}
void set_gamma(const double g)
    {if (g < 0 && g>1)
        throw "Errore gamma";
    else 
        g = gamma;
    }
vector <sirdata> generate_data(int duration) {
    vector<sirdata> result = NULL;
    if (state =! NULL)
    {
        result.push_back(*state) // serve l'asterisco perché solo state è gia un puntatore
        cout << "Tempo =:"<< endl;
        cout << "S:"<< state->get_susc()<< endl;
        cout <<"I:"<< state ->get_inf() << endl;
        cout << "R:" << state ->get_rec() << endl;

        const int pop_now = state ->getPop(); //now
        for (int i = 0; i < duration; i++ ){

            sirdata *state_i = &result.back();
            int newinf = round((beta/pop_now) * state_i ->get_susc()* state_i ->get_inf());
            int newrec = (int)(gamma*state_i ->get_inf());

            state_i -> set_susc(state_i -> get_susc()- newinf);
            state_i -> set_inf(state_i -> get_inf() + newinf - newrec); //riguarda 
            state_i -> set_rec(state_i ->get_rec() + newrec);

            cout << "Tempo " << i+1 << endl;
            state->toString();

        if(!state->checkPop())
            throw "Errore: valore popolazione non corrisponde alla somma di s,r,i!";
        result.push_back(*state);

        }
    }
return result;
}
    