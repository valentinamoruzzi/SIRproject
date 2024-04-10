#ifndef sirmodel_HPP
#define sirmodel_HPP

#include "sirdata.hpp"
#include <vector>
#include <cstddef>

#define BETA_DEFAULT 0.6
#define GAMMA_DEFAULT 0.1

using namespace std;
namespace Sirmodel{
class sirmodel {
private:
    double beta;
    double gamma;
    double R0;
protected:
    void set_R0();
public:
    sirdata *state = NULL;
    sirmodel ();
    sirmodel ( const double &b, const double &g);
    sirmodel (sirdata *state, const double &b, const double &g);
    sirdata* get_state();
    void set_state(sirdata *s);
    double get_beta();
    void set_beta(const double &b);
    double get_gamma();
    void set_gamma(const double &g);
    double get_R0();
    
    vector<sirdata> generate_data(const int &duration);

};
}
#endif