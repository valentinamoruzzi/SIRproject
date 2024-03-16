#include <iostream>
#include<string>
#include<cmath>
#include "sirdata.hpp"


using namespace std;


int main () {
    sirdata *sirdata_test = NULL;
    sirdata_test = new sirdata(1000,10,2);

    cout << "suscettibili:" << sirdata_test -> get_susc() << endl;
    cout << "infetti:" << sirdata_test -> get_inf() << endl;
    cout << "rimossi:" << sirdata_test -> get_rim() << endl;

}