#ifndef sirmodel_HPP
#define sirmodel_HPP
#include "sirdata.hpp"
#include <vector>

class sirmodel {
private:
  double beta;
  double gamma;
  double R0;
  static constexpr double beta_default = 0.6;
  static constexpr double gamma_default = 0.1;
  sirdata state;

public:
  sirmodel();
  sirmodel( double b, double g);
  sirmodel(const sirdata &state, double b, double g);
  sirdata get_state() const;
  void set_state(const sirdata& s);
  double get_beta() const;
  void set_beta(double b);
  double get_gamma() const ;
  void set_gamma(double g);
  double get_R0() const;
  void set_R0();

  std::vector<sirdata> generate_data(int duration);
};

#endif