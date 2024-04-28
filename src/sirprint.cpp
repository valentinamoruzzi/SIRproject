#include "sirprint.hpp"
#include "sirdata.hpp"
#include "sirmanage.hpp"
#include "sirmodel.hpp"
#include "sirmodelextended.hpp"
#include <fstream>
#include <string>
#include <iomanip>

sirprint::sirprint(const sirmanage &c, const sirmodel &sir) {
  set_cfg(c);
  set_model(sir);
}

sirprint::sirprint(const sirmanage &c, const sirmodelextended &sirs) {
  set_cfg(c);
  set_modelextended(sirs);
}

void sirprint::set_cfg(const sirmanage &c) {
  if (c != NULL)
    cfg = c;
  else
    throw "Configurator tool is empty";
}
void sirprint::set_model(const sirmodel &sir_) {
  if (sir_ != NULL)
    sir = sir_;
  else
    throw "Unknown model";
}

void sirprint::set_modelextended(const sirmodelextended &sirs_) {
  if (sirs_ != NULL)
    sirs = sirs_;
  else
    throw "Unknown model";
}

void sirprint::print_tostdout(vector<sirdata> results, int duration) {

  int pop = results[0].get_susc() + results[0].get_inf() + results[0].get_rec();

  std::cout << "|" << setw(5) << "Time" << "|" << setw(5) << "Susc" << "|" << setw(5)
       << "Inf" << "|" << setw(5) << "Rec" << "|" << setw(5) << "Beta" << "|"
       << setw(5) << "Gamma";

  if (cfg.get_modeltype() == "sirmodelextended")
    std::cout << "|" << setw(5) << "Alpha";

  std::cout << "|" << setw(5) << "Pop" << "|" << "\n";
  for (int day = 0; day < duration; day++) {

    std::cout << "|" << setw(5) << day << "|" << setw(5) << results[day].get_susc()
         << "|" << setw(5) << results[day].get_inf() << "|" << setw(5)
         << results[day].get_rec();
    if (cfg.get_modeltype() == "sirmodel")
      std::cout << "|" << setw(5) << sir->get_beta();
    else
      std::cout << "|" << setw(5) << sirs->get_beta();
    if (cfg.get_modeltype() == "sirmodel")
      std::cout << "|" << setw(5) << sir->get_gamma();
    else
      std::cout << "|" << setw(5) << sirs->get_gamma();
    if (cfg.get_modeltype() == "sirmodelextended")
      std::cout << "|" << setw(5) << sirs->get_alpha();
    std::cout << "|" << setw(5) << pop << "|" << endl;
  }
}
void sirprint::print_tofile(std::vector<sirdata> results, int duration) {
  for (int i = 0; i < duration; i++) {
    cfg.get_sw() << results[i].toString() << "\n";
  }
}
void sirprint::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(plot_, states);
}
void sirprint::plot(vector<sirdata> &results, int duration) {

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

void sirprint::printdata(std::vector<sirdata> results, int duration) {
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
    throw "Error: unknown output type";
    }
}
