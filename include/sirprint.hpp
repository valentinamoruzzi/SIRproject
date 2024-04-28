#ifndef SIRPRINT_HPP
#define SIRPRINT_HPP
#define SFML_NO_DEPRECATED_WARNINGS
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "sfml/plot.h"

class sirprint : public sf::Drawable {
private:
  sirmanage cfg;
  sirmodel sir;
  sirmodelextended sirs;
  void set_cfg(const sirmanage &c);
  void set_model(const sirmodel &sir_);
  void set_modelextended(const sirmodelextended &sirs_);
  void print_tostdout(std::vector<sirdata> results, int n);
  void print_tofile(std::vector<sirdata> results, int n);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void plot(std::vector<sirdata> &results, int n);
  sf::plot::Plot plot_;

public:
  sirprint(const sirmanage &c, const sirmodel &model);
  sirprint(const sirmanage &c, const sirmodelextended &model);
  void printdata(std::vector<sirdata> results, int duration);
};
#endif