#ifndef sirmodelextended_HPP
#define sirmodelextended_HPP
#define ALPHA_DEFAULT 0.8
#include <vector>
#include "sirmodel.hpp"

namespace Sirmodel{
    class sirmodelextended: public sirmodel{
    private: 
        double alpha;
    public:
        sirmodelextended();
        sirmodelextended(const double &a);
        sirmodelextended(const double &b, const double &g, const double &a);
        double get_alpha();
        void set_alpha(const double &a);
        vector<sirdata> generate_data(const int &duration);

    };
}




#endif