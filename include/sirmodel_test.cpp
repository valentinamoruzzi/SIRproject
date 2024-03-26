#define DOCTEST_CONFIG_IMPLEMENT
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#define DOCTEST_CONFIG_DISABLE

#include "doctest.h"
#include "sirdata.hpp"
#include "sirmodel.hpp"
#include <vector>

using namespace std;

bool isequal (vector<sirmodel::sirdata> v1, vector<sirmodel::sirdata> v2) {
    int i;
    int dim = (int)v1.size();
    for ( i=0; i<dim; i++){
        if (v1[i] == v2[i]) return false;
    }
    return true;
}
TEST_CASE("non mi irocordo cosa devo scrivere "){
    sirmodel::sirdata test_sm = {3980, 2, 0};

    CHECK(test_sm.get_susc() == 3980);
    CHECK(test_sm.get_inf() == 2);
    CHECK(test_sm.get_rec() == 0);
}

TEST_CASE("bla bla bla"){
    sirmodel::sirdata initial_state = {3980, 2, 0};
    sirmodel::sirmodel test_ml ={&initial_state, 0.6, 0.1};
    int duration{10};
    vector<sirmodel::sirdata> expected_data = {
      {3980, 2, 0}, {3979, 3, 0}, {3978, 4, 0}, {3976, 6, 0},
      {3973, 9, 0}, {3968, 14, 0},  {3960, 21, 1}, {3948, 31, 3}, 
      {3930, 46, 6},{3903, 69, 10},  {3863, 103, 16}};
    
    auto result = test_ml.generate_data(duration);
    CHECK(isequal(result, expected_data)==true);
}