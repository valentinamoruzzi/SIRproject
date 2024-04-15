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

using namespace std;
using namespace Sirmodel;

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
  string r, model;
  vector<sirdata> results;

  try {
    sirmanage *file = new sirmanage("sirmodel.cfg");

    // LEGGI BETA e GAMMA e ALFA
    r = file->read_row_fromfile();
    if (r != "") {
      beta = atof(r.c_str());
    }

    r = file->read_row_fromfile();
    if (r != "") {
      gamma = atof(r.c_str());
    }

    r = file->read_row_fromfile();
    if (r != "") {
      alpha = atof(r.c_str());
    }

    // LEGGI S,I,R
    r = file->read_row_fromfile();
    if (r != "") {
      susc = stoi(r.c_str(), 0, 10);
    }

    r = file->read_row_fromfile();
    if (r != "") {
      inf = stoi(r.c_str(), 0, 10);
    }

    r = file->read_row_fromfile();
    if (r != "") {
      rec = stoi(r.c_str(), 0, 10);
    }

    // LEGGI DURATA
    r = file->read_row_fromfile();
    if (r != "") {
      duration = stoi(r.c_str(), 0, 10);
    }

    // LEGGI MODELO
    model = file->read_row_fromfile();
    file->set_modeltype(model);

    // SETTO LO STATO INZIALE
    sirdata *initial_state = new sirdata(susc, inf, rec);

    if (model == "sirmodel") {
      cout << file->get_modeltype() << endl;
      cout << "ok1" << endl;
      sirmodel *m = new sirmodel(beta, gamma);
      m->set_state(initial_state);
      results = m->generate_data(duration);
      sirprint *sir_print = new sirprint(file, m);
      sir_print->printdata(results, duration);

    } else if (model == "sirmodelextended") {
      cout << file->get_modeltype() << endl;
      sirmodelextended *ex = new sirmodelextended(beta, gamma, alpha);
      ex->set_state(initial_state);
      results = ex->generate_data(duration);
      sirprint *sir_print = new sirprint(file, ex);
      sir_print->printdata(results, duration);
    }

  } catch (const char *message) {
    cout << message << endl;
  }
}
