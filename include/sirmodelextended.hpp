#ifndef sirmodelextended_HPP
#define sirmodelextended_HPP
#include "sirmodel.hpp"
#include <iostream>

class sirmodelextended : public sirmodel {
private:
  double alpha;
  static constexpr double alpha_default = 0.8;

public:
  sirmodelextended();
  sirmodelextended( double a);
  sirmodelextended( double b,  double g, double a);
  double get_alpha();
  void set_alpha( double a);
  std::vector<sirdata> generate_data( int duration);
};

#endif