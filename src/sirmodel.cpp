#include "sirmodel.hpp"
#include "sirdata.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <cstddef>

sirmodel::sirmodel() {

  set_beta(beta_default);
  set_gamma(gamma_default);
  set_R0();
}

sirmodel::sirmodel( double b, double g) {
  set_beta(b);
  set_gamma(g);
  set_R0();
}

sirmodel::sirmodel(const sirdata &state, double b, double g) {
  set_state(state);
  set_beta(b);
  set_gamma(g);
  set_R0();
}

sirdata sirmodel::get_state() const { return state; }
void sirmodel::set_state(const sirdata &s) {
    state = s;
}

double sirmodel::get_beta() const { return beta; }
void sirmodel::set_beta( double b) {
  if (b < 0 && b > 1)
    throw std:: runtime_error{"Error: the value of beta is not correct\n"};
  else
    beta = b;
}
double sirmodel::get_gamma() const { return gamma; }
void sirmodel::set_gamma( double g) {
  if (g < 0 && g > 1)
    throw std::runtime_error{ "Error: the value of gamma is not correct\n"};
  else
    gamma = g;
}

double sirmodel::get_R0() const { return R0; }
void sirmodel::set_R0() {
  double r_zero = get_beta() / get_gamma();
  if (r_zero < 1) {
    throw std::runtime_error{"Error: The value of R0 is not correct"};
  } else
    R0 = r_zero;
};

std::vector<sirdata> sirmodel::generate_data(int duration) {
  std::vector<sirdata> result;
  //if (state != NULL) {
    result.push_back(state); // serve l'asterisco perché solo state è gia un puntatore

    const int pop_now = state.get_pop(); // now
    for (int i = 0; i < duration; i++) {

      sirdata state_i = result.back();
      const int newinf =
          (int)((get_beta() * state_i.get_susc() * state_i.get_inf()) /
                pop_now);
      const int newrec = (int)(get_gamma() * state_i.get_inf());

      state.set_susc(state_i.get_susc() - newinf);
      state.set_inf(state_i.get_inf() + newinf - newrec);
      state.set_rec(state_i.get_rec() + newrec);

      if (!state.check_pop())
        throw std::runtime_error{"Error: population do not correspond to the sum of S,R,I!\n"};
      result.push_back(state);
    }
  //}
  return result;
}

