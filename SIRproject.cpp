#include <iostream>
#include<string>
#include<cmath>
#include"sirdata.hpp"
#include"sirmodel.hpp"

#include <cstdio>
#include <cstring>

using namespace std;


int main () {
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
    
}