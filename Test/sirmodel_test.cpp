#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sirdata.hpp"
#include "sirmodel.hpp"
#include "sirmodelextended.hpp"
#include <vector>

bool isequal(const std::vector<sirdata> &v1, const std::vector<sirdata> &v2){
int i = 0;
for(i=0; i<v1.size() && v1[i]==v2[i]; i++);
if (i == v1.size()){
  return true;
}
else
{
  return false;
}
}


TEST_CASE("Testing class sirdata ") {
  sirdata test_sm = {3980, 2, 0};

  CHECK(test_sm.get_susc() == 3980);
  CHECK(test_sm.get_inf() == 2);
  CHECK(test_sm.get_rec() == 0);
};

TEST_CASE("Testing class Sirmodel") {
  sirmodel test_sirmodel = {0.6, 0.1};
  CHECK(test_sirmodel.get_beta() == 0.6);
  CHECK(test_sirmodel.get_gamma() == 0.1);
}

TEST_CASE("SIR model") {
  sirdata initial_state = {3980, 2, 0};
  sirmodel test_ml = {initial_state, 0.6, 0.1};
  int duration{10};
  std::vector<sirdata> expected_data = {
      {3980, 2, 0},  {3979, 3, 0},   {3978, 4, 0},    {3976, 6, 0},
      {3973, 9, 0},  {3968, 14, 0},  {3960, 21, 1},   {3948, 31, 3},
      {3930, 46, 6}, {3903, 69, 10}, {3863, 103, 16}, {3804, 152, 26}};

  std::vector <sirdata> result = test_ml.generate_data(duration);
  CHECK(isequal(result, expected_data) == true);
}

TEST_CASE("SIR model extended") {
  sirdata initial_state = {3980, 2, 0};
  sirmodelextended test_ex = sirmodelextended(0.6, 0.1, 0.5);
  test_ex.set_state(initial_state);
  int duration{10};
  std::vector<sirdata> expected_data = {
      {3980, 2, 0},  {3979, 3, 0},  {3978, 4, 0},    {3976, 6, 0},
      {3973, 9, 0},  {3968, 14, 0}, {3960, 21, 1},   {3948, 31, 3},
      {3931, 46, 5}, {3906, 69, 7}, {3869, 103, 10}, {3814, 153, 15}};

  std:: vector<sirdata> result = test_ex.generate_data(duration);
  CHECK(isequal(result, expected_data) == true);
}

TEST_CASE("SIR model extended alpha tend to 0") {
  sirdata initial_state = {3980, 2, 0};
  sirmodelextended test_ex = sirmodelextended(0.6, 0.1, 0);
  test_ex.set_state(initial_state);
  int duration{10};
  std::vector<sirdata> expected_data = {
      {3980, 2, 0},  {3979, 3, 0},   {3978, 4, 0},    {3976, 6, 0},
      {3973, 9, 0},  {3968, 14, 0},  {3960, 21, 1},   {3948, 31, 3},
      {3930, 46, 6}, {3903, 69, 10}, {3863, 103, 16}, {3804, 152, 26}};

  std::vector <sirdata> result = test_ex.generate_data(duration);
  CHECK(isequal(result, expected_data) == true);
}