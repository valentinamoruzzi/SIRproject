#include "sirdata.hpp"
#include "sirmanage.hpp"
#include "sirmodel.hpp"
#include "sirmodelextended.hpp"
#include "sirprint.hpp"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

int main() {
  /*
   try
  {
      char a;
      sirmodel *m = new sirmodel(0.6,0.5);
      sirdata *initial_state = new sirdata(5000,98,2);
      m->set_state(initial_state);
      vector<sirdata> results = m->generate_data(1000);

      for(int i=0; i<1000; i++)
      {
          results[i].toString();
      }
  }
  catch(const char *message){
      cout << "Errore: " << message;
  }
  */

  int duration;
  double beta, gamma, alpha;
  int susc = 0, inf = 0, rec = 0;
  std::vector<sirdata> results;

  try {
  
    sirmanage file("sirmodel.cfg");

    // LEGGI BETA e GAMMA e ALFA
    auto r = file.read_row_fromfile();
    if (r.empty()) {
      beta = atof(r.c_str());
    }

    r = file.read_row_fromfile();
    if (r.empty()) {
      gamma = atof(r.c_str());
    }

    r = file.read_row_fromfile();
    if (r.empty()) {
      alpha = atof(r.c_str());
    }

    // LEGGI S,I,R
    r = file.read_row_fromfile();
    if (r.empty()) {
      susc = std::stoi(r.c_str(), 0, 10);
    }

    r = file.read_row_fromfile();
    if (r.empty()) {
      inf = std::stoi(r.c_str(), 0, 10);
    }

    r = file.read_row_fromfile();
    if (r.empty()) {
      rec = std::stoi(r.c_str(), 0, 10);
    }

    // LEGGI DURATA
    r = file.read_row_fromfile();
    if (r.empty()) {
      duration = std::stoi(r.c_str(), 0, 10);
    }

    // LEGGI MODELO
    auto model = file.read_row_fromfile();
    file.set_modeltype(model);

    // SETTO LO STATO INZIALE
    
    sirdata initial_state(susc, inf, rec);

    if (model == "sirmodel") {
      std::cout << file.get_modeltype() << "\n";
      std::cout << "ok1" << "\n";
      sirmodel m(beta, gamma);
      m.set_state(initial_state);
      results = m.generate_data(duration);
      sirprint sir_print(file, m);
      sir_print.printdata(results, duration);

    } else if (model == "sirmodelextended") {
      std::cout << file.get_modeltype() << "\n";
      sirmodelextended ex(beta, gamma, alpha);
      ex.set_state(initial_state);
      results = ex.generate_data(duration);
      sirprint sir_print(file, ex);
      sir_print.printdata(results, duration);
    }

  } catch (const std::exception &exc) {
    std::cerr << exc.what() << "\n";
    return EXIT_FAILURE;
  }
  catch(...){
    std::cerr<<"unkown exception"<< "\n"
  };
}
