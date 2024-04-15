#ifndef sirdata_HPP
#define sirdata_HPP
#include <string>
using namespace std;

class sirdata {

private:
  int pop;
  int susc;                           // susceptibles
  int inf;                            // infected
  int rec;                            // recovered
  void set_pop(const int population); // può cambiarlo solo la classe
public:
  sirdata(const int &susceptibles, const int &infected, const int &recovered);
  int get_susc();
  void set_susc(const int &susceptibles);
  int get_inf();
  void set_inf(const int &infected);
  int get_rec();
  void set_rec(const int &recovered);
  int get_pop();
  bool check_pop();
  string toString();
  bool operator==(sirdata d);
};

#endif
