#ifndef sirmodelextended_HPP
#define sirmodelextended_HPP
#define ALPHA_DEFAULT 0.8
#include <vector>
#include "sirmodel.hpp"

namespace sirmodel{
    class sirmodelextended: public sirmodel{
    private: 
        double alpha;
    public:
        sirmodelextended();
        sirmodelextended( double a);
        sirmodelextended( double b, double g, double a);
        double get_alpha();
        void set_alpha(double a);
        vector<sirdata> generate_data(int duration);

    };
}




#endif