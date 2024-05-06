#include "sirdata.hpp"
#include <string>
#include <sstream>

sirdata::sirdata(int susceptibles, int infected,
                 int recovered) {

  set_susc(susceptibles);
  set_inf(infected);
  set_rec(recovered);
  set_pop(susceptibles + infected + recovered);
}

int sirdata::get_susc() const { return susc; }
void sirdata::set_susc( int susceptibles) {

  if (susceptibles < 0)
    throw std::runtime_error{"Error: susceptibles less than 0\n"};
  else
    susc = susceptibles;
}

int sirdata::get_inf() const { return inf; }
void sirdata::set_inf( int infected) {
  if (infected < 0)
    throw std:: runtime_error{"Error: infected less than 0\n"};
  else
    inf = infected;
}

int sirdata::get_rec() const { return rec; }
void sirdata::set_rec( int recovered) {
  if (recovered < 0)
    throw std::runtime_error{"Error: recovered less than 0\n"};
  else
    rec = recovered;
}

int sirdata::get_pop() const { return pop; }
void sirdata::set_pop(const int population) {
  if (population < 0)
    throw std::runtime_error{ "Error: population less than 0\n"};
  else
    pop = population;
}

bool sirdata::check_pop() {

  if (get_pop() == get_susc() + get_inf() + get_rec())
    return true;
  else
    return false;
}

std::string sirdata::toString() {

  std::stringstream ss;
  ss << get_susc() << ";" << get_inf() << ";" << get_rec() << '\n';
  return ss.str();
}

bool operator== ( sirdata d1, sirdata d2) {
  if (d1.get_susc() == d2.get_susc() && d1.get_inf() == d2.get_inf() &&
      d1.get_rec() == d2.get_rec())
    return true;
  else
    return false;
}
