#ifndef sirmodel_HPP
#define sirmodel_HPP

#include "sirdata.hpp"
#include <vector>

#define BETA_DEFAULT 0.6
#define GAMMA_DEFAULT 0.1

using namespace std;
namespace sirmodel{
class sirmodel {
private:
    double beta;
    double gamma;

public:
    sirdata *state = NULL;
    sirmodel ();
    sirmodel ( double b, double g);
    sirmodel (sirdata *state, double b, double g);
    sirdata* get_state();
    void set_state(sirdata *s);
    double get_beta();
    void set_beta(const double b);
    double get_gamma();
    void set_gamma(const double g);
    vector<sirdata> generate_data(int duration);

};
}
#endif