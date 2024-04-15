#ifndef SIRPRINT_HPP
#define SIRPRINT_HPP
#define SFML_NO_DEPRECATED_WARNINGS
#include "sfml/plot.h"
#include "sirdata.hpp"
#include "sirmanage.hpp"
#include "sirmodel.hpp"
#include "sirmodelextended.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

namespace Sirmodel {
class sirprint : public sf::Drawable {
private:
  sirmanage *cfg;
  sirmodel *sir;
  sirmodelextended *sirs;
  void set_cfg(sirmanage *c);
  void set_model(sirmodel *sir_);
  void set_modelextended(sirmodelextended *sirs_);
  void print_tostdout(vector<sirdata> results, const int &n);
  void print_tofile(vector<sirdata> results, const int &n);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void plot(vector<sirdata> &results, const int &n);
  sf::plot::Plot plot_;

public:
  sirprint(sirmanage *c, sirmodel *model);
  sirprint(sirmanage *c, sirmodelextended *model);
  void printdata(vector<sirdata> results, const int &duration);
};
} // namespace Sirmodel
#endif