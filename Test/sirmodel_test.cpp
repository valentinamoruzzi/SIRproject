#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "doctest.h"
#include "sirdata.hpp"
#include "sirmodel.hpp"
#include <vector>

using namespace std;
using namespace Sirmodel;

bool isequal (vector<sirdata> v1, vector<sirdata> v2) {
    int i = 0;
    int dim = (int)v1.size();
    while (v1[i] == v2[i] && i<dim ) i++;

        if (i == dim ) return true;
    else return false;
}
TEST_CASE("non mi irocordo cosa devo scrivere "){
    sirdata test_sm = {3980, 2, 0};

    CHECK(test_sm.get_susc() == 3980);
    CHECK(test_sm.get_inf() == 2);
    CHECK(test_sm.get_rec() == 0);
}

TEST_CASE("Testing class Sirmodel"){
    sirmodel test_sirmodel ={0.6, 0.1};
    CHECK(test_sirmodel.get_beta() == 0.6);
    CHECK(test_sirmodel.get_gamma() == 0.1);
}

TEST_CASE("bla bla bla"){
    sirdata initial_state = {3980, 2, 0};
    sirmodel test_ml ={&initial_state, 0.6, 0.1};
    int duration{10};
    vector<sirdata> expected_data = {
      {3980, 2, 0}, {3979, 3, 0}, {3978, 4, 0}, {3976, 6, 0},
      {3973, 9, 0}, {3968, 14, 0},  {3960, 21, 1}, {3948, 31, 3}, 
      {3930, 46, 6},{3903, 69, 10},  {3863, 103, 16}, {3804, 152, 26}};
    
    auto result = test_ml.generate_data(duration);
    CHECK(isequal(result, expected_data)==true);
}