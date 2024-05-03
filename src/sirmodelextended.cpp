#include "sirmodelextended.hpp"
#include <vector>

sirmodelextended::sirmodelextended() {

  set_alpha(alpha_default);
  set_R0();
}

sirmodelextended::sirmodelextended(double a) {

  set_alpha(a);
  set_R0();
}

sirmodelextended::sirmodelextended(double b, double g,
                                   double a) {

  set_beta(b);
  set_gamma(g);
  set_alpha(a);
  set_R0();
}

double sirmodelextended::get_alpha() const { return alpha; }
void sirmodelextended::set_alpha( double a) {
  if (a < 0 && a > 1)
    throw std::runtime_error{ "Error: the value of alpha is not correct"};
  else
    alpha = a;
}

std::vector<sirdata> sirmodelextended::generate_data( int duration) {
  std::vector<sirdata> result;
  sirdata s = get_state();
    result.push_back(s); 

    const int pop_now = s.get_pop(); // now
    for (int i = 0; i < duration ; i++) {

      sirdata state_i = result.back();
      const int newinf =
          (int)((get_beta() * state_i.get_susc() * state_i.get_inf()) /
                pop_now);
      const int newrec = (int)(get_gamma() * state_i.get_inf());
      const int newsusc = (int)(get_alpha() * state_i.get_rec());

      s.set_susc(state_i.get_susc() - newinf + newsusc);
      s.set_inf(state_i.get_inf() + newinf - newrec);
      s.set_rec(state_i.get_rec() + newrec - newsusc);

      if (!s.check_pop())
        throw std::runtime_error{"Error: population do not correspond to the sum of S,R,I!\n"};
      result.push_back(s);
    }
  
  return result;
}

