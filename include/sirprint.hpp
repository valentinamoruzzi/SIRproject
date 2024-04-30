#ifndef SIRPRINT_HPP
#define SIRPRINT_HPP
#define SFML_NO_DEPRECATED_WARNINGS
#include "sirmodel.hpp"
#include "sirmodelextended.hpp"
#include "sirmanage.hpp"
#include "sfml/plot.h"

class sirprint : public sf::Drawable {
private:
  sirmanage cfg;
  sirmodel sir;
  sirmodelextended sirs;
  void print_tostdout(const std::vector<sirdata> &results, int n);
  void print_tofile(const std::vector<sirdata> &results, int n);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void plot(const std::vector<sirdata> &results, int n);
  sf::plot::Plot plot_;

public:
  sirprint();
  sirprint(const sirmanage &c, const sirmodel &model);
  sirprint(const sirmanage &c, const sirmodelextended &model);
  void printdata(const std::vector<sirdata> &results, int duration);
};
#endif