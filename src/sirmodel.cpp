#include "sirdata.hpp"
#include "sirmodel.hpp"
#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

namespace Sirmodel {

sirmodel::sirmodel (){
    set_beta(BETA_DEFAULT);
    set_gamma(GAMMA_DEFAULT);
    set_R0();
}

sirmodel::sirmodel ( double b, double g){
    set_beta(b);
    set_gamma(g);
    set_R0();
}

sirmodel::sirmodel (sirdata *state, double b, double g){
    set_state(state);
    set_beta(b);
    set_gamma(g);
    set_R0();
}

sirdata* sirmodel::get_state() {return state;}
void sirmodel::set_state(sirdata *s)        
    {if (s == NULL)
        throw "Error: state empty"; //stato nullo
    else state = s;
    }
double sirmodel::get_beta() {return beta;}
void sirmodel::set_beta(const double b) 
{if (b < 0 && b>1)
        throw "Error: the value of beta is not correct";
    else 
        beta = b;
    }
double sirmodel::get_gamma() {return gamma;}
void sirmodel::set_gamma(const double g)
    {if (g < 0 && g>1)
        throw "Error: the value of gamma is not correct";
    else 
        gamma = g;
    }

    double sirmodel:: get_R0(){return R0;}
    void sirmodel::set_R0(){
        double r_zero = get_beta()/get_gamma() ;
        if(r_zero < 1 ){
            throw "Error....";
        }
        else R0 = r_zero;
    };

vector<sirdata> sirmodel::generate_data(int duration) {
    vector<sirdata> result;
    if (state != NULL)
    {
        result.push_back(*state); // serve l'asterisco perché solo state è gia un puntatore
        //cout << "Tempo 0 :"<<endl;
        //cout << "S:"<< state->get_susc()<< endl;
        //cout <<"I:"<< state ->get_inf() << endl;
        //cout << "R:" << state ->get_rec() << endl;

        const int pop_now = state ->get_pop(); //now
        for (int i = 0; i < duration; i++ ){

            sirdata *state_i = &result.back();
            const int newinf = (int)((get_beta()*state_i->get_susc()* state_i->get_inf())/pop_now);
            const int newrec = (int)(get_gamma()*state_i->get_inf());

            state -> set_susc(state_i -> get_susc()- newinf);
            state -> set_inf(state_i -> get_inf() + newinf - newrec); 
            state -> set_rec(state_i -> get_rec() + newrec);

        if(!state->check_pop())
            throw "Errore: valore popolazione non corrisponde alla somma di s,r,i!";
        result.push_back(*state);

        }
    }
return result;
}
}
    