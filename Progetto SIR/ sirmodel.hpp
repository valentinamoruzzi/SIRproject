#ifndef sirmodel_HPP
#define sirmodel_HPP

#include "sirdata.hpp"
#include <vector>


using namespace std;


class sirmodel {
    private:
    sirdata *state;
    double beta;
    double gamma;

    public:
    sirmodel ();
    sirmodel (const double b, const double g);
    sirmodel (sirdata *state, const double b, const double g);
    sirdata* get_state();
    void set_state(sirdata *s);
    double get_beta();
    void set_beta(const double b);
    double get_gamma();
    void set_gamma(const double g);
    vector<sirdata> generate_data(int duration);



};



#endif
