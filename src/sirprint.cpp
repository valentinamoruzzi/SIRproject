#include "sirprint.hpp"
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "sfml/plot.h"

sirprint::sirprint(const sirmanage &c, const sirmodel &_sir) : cfg(c.get_in_filepath()), sir(_sir){}
sirprint::sirprint(const sirmanage &c, const sirmodelextended &_sirs) : cfg(c.get_in_filepath()), sirs(_sirs){}

void sirprint::print_tostdout(const std::vector<sirdata> &results, int duration) {

  int pop = results[0].get_susc() + results[0].get_inf() + results[0].get_rec();

  std::cout << "|" << std::setw(5) << "Time" << "|" << std::setw(5) << "Susc" << "|" << std::setw(5)
       << "Inf" << "|" << std::setw(5) << "Rec" << "|" << std::setw(5) << "Beta" << "|"
       << std::setw(5) << "Gamma";

  if (cfg.get_modeltype() == "sirmodelextended")
    std::cout << "|" << std::setw(5) << "Alpha";

  std::cout << "|" << std::setw(5) << "Pop" << "|" << "\n";
  for (int day = 0; day < duration; day++) {

    std::cout << "|" << std::setw(5) << day << "|" << std::setw(5) << results[day].get_susc()
         << "|" << std::setw(5) << results[day].get_inf() << "|" << std::setw(5)
         << results[day].get_rec();
    if (cfg.get_modeltype() == "sirmodel")
      std::cout << "|" << std::setw(5) << sir.get_beta();
    else
      std::cout << "|" << std::setw(5) << sirs.get_beta();
    if (cfg.get_modeltype() == "sirmodel")
      std::cout << "|" << std::setw(5) << sir.get_gamma();
    else
      std::cout << "|" << std::setw(5) << sirs.get_gamma();
    if (cfg.get_modeltype() == "sirmodelextended")
      std::cout << "|" << std::setw(5) << sirs.get_alpha();
    std::cout << "|" << std::setw(5) << pop << "|" << "\n";
  }
}
void sirprint::print_tofile( std::vector<sirdata> results, int duration) {
  for (int i = 0; i < duration; i++) {
    cfg.get_sw() << results[i].toString() << "\n";
  }
}
void sirprint::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(plot_, states);
}
void sirprint::plot(const std::vector<sirdata> &results, int duration) {

  // setting window parameters
  sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML plot",
                          sf::Style::Default);

  // setting plotting parameters
  plot_.setSize(sf::Vector2f(1200, 800));
  plot_.setTitleColor(sf::Color::Black);
  plot_.setTitle("\t\t\t\t\t\t\t\t\t\t\t\t" + cfg.get_modeltype() +
                 "\nRed: Susceptibles - Green: Removed - Blue: Infected");
  plot_.setFont("./font.ttf");
  plot_.setXLabel("Time");
  plot_.setYLabel("Populations");

  // Creating curves
  sf::plot::Curve &s_curve = plot_.createCurve("Susceptibles", sf::Color::Red);
  s_curve.setThickness(2);
  s_curve.setFill(false);
  s_curve.setLabel("Susceptibles");

  sf::plot::Curve &r_curve = plot_.createCurve("Recovered", sf::Color::Green);
  r_curve.setThickness(2);
  r_curve.setFill(false);
  r_curve.setLabel("Recovered");

  sf::plot::Curve &i_curve = plot_.createCurve("Infected", sf::Color::Blue);
  i_curve.setThickness(2);
  i_curve.setFill(false);
  i_curve.setLabel("Infected");

  for (int x = 0; x < duration; x++) {
    s_curve.addValue(results[x].get_susc());
    r_curve.addValue(results[x].get_rec());
    i_curve.addValue(results[x].get_inf());
  }

  plot_.prepare();
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.clear(sf::Color::White);
    window.draw(plot_);
    window.display();
  }
}

void sirprint::printdata(const std::vector<sirdata> &results, int duration) {
  std::cout << cfg.get_output_type() << "\n";
  if (cfg.get_output_type() == 'S') {
    print_tostdout(results, duration);
    }
  else if (cfg.get_output_type() == 'F') {
    print_tofile(results, duration);
    }
  else if (cfg.get_output_type() == 'P'){
    plot(results, duration);
    }
  else{
    throw std::runtime_error{ "Error: unknown output type\n"};
    }
}
