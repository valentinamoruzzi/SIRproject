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

  try {

    int duration;
    double beta, gamma, alpha;
    int susc = 0, inf = 0 , rec = 0 ;
    std::vector<sirdata> results;
    sirmanage file("../../sirmodel.cfg");

    // LEGGI BETA e GAMMA e ALFA
    auto r = file.read_row_fromfile();
    if (!sirmanage::isfloatnumber(r)) 
    {
      throw std::runtime_error{"Error: beta is not a valid number \n"};
    }
    else
    {
      beta = atof(r.c_str());
    }

    r = file.read_row_fromfile();
    if (!sirmanage::isfloatnumber(r)) 
    {
      throw std::runtime_error{"Error: gamma is not a valid number \n"};
    }
    else
    {
      gamma = atof(r.c_str());
    }

    r = file.read_row_fromfile();
    if (!sirmanage::isfloatnumber(r)) 
    {
      throw std::runtime_error{"Error: alpha is not a valid number \n"};
    }
    else
    {
      alpha = atof(r.c_str());
    }

    // LEGGI S,I,R
    r = file.read_row_fromfile();
     if (!sirmanage::isfloatnumber(r)) 
    {
      throw std::runtime_error{"Error: Susc is not a valid number \n"};
    }
    else
    {
      susc = std::stoi(r.c_str(), 0, 10);
    }

    r = file.read_row_fromfile();
     if (!sirmanage::isfloatnumber(r)) 
    {
      throw std::runtime_error{"Error: Inf is not a valid number \n"};
    }
    else
    {
      inf = std::stoi(r.c_str(), 0, 10);
    }

    r = file.read_row_fromfile();
     if (!sirmanage::isfloatnumber(r)) 
    {
      throw std::runtime_error{"Error: Rec is not a valid number \n"};
    }
    else
    {
      rec = std::stoi(r.c_str(), 0, 10);
    }

    // LEGGI DURATA
     r = file.read_row_fromfile();
     if (!sirmanage::isfloatnumber(r)) 
    {
      throw std::runtime_error{"Error: duration is not a valid number \n"};
    }
    else
    {
      duration = std::stoi(r.c_str(), 0, 10);
    }

    // LEGGI MODELO
    auto model = file.read_row_fromfile();
    if(!model.empty() && (model == "sirmodel" || model == "sirmodelextended"))
    {
      file.set_modeltype(model);
    }
    else 
    {
      throw std::runtime_error{"Error: model value is empty or not valid"};
    }

    // SETTO LO STATO INZIALE
    
    sirdata initial_state(susc, inf, rec);

    if (model == "sirmodel") {
      sirmodel m(beta, gamma);
      m.set_state(initial_state);
      results = m.generate_data(duration);
      sirprint sir_print(file, m);
      sir_print.printdata(results, duration);

    } else if (model == "sirmodelextended") {
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
    std::cerr<<"unkown exception"<< "\n";
  };
}
