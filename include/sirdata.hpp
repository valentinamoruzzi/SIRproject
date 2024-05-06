#ifndef sirdata_HPP
#define sirdata_HPP
#include <iostream>

class sirdata
{
 private:
  int pop;
  int susc;                     // susceptibles
  int inf;                      // infected
  int rec;                      // recovered
  void set_pop(int population); // può cambiarlo solo la classe
 public:
  sirdata() = default;
  sirdata(int susceptibles, int infected, int recovered);
  int get_susc() const;
  void set_susc(int susceptibles);
  int get_inf() const;
  void set_inf(int infected);
  int get_rec() const;
  void set_rec(int recovered);
  int get_pop() const;
  bool check_pop();
  std::string toString();
};

bool operator==(sirdata d1, sirdata d2);

#endif