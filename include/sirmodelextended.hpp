#ifndef sirmodelextended_HPP
#define sirmodelextended_HPP
#define ALFA_DEFAULT 0.8
#include <vector>
#include "sirmodel.hpp"

namespace sirmodel{
    class sirmodelextended: public sirmodel{
    private: 
        double alfa;
    public:
        sirmodelextended();
        sirmodelextended( double a);
        sirmodelextended( double b, double g, double a);
        double get_alfa();
        void set_alfa(double a);
        vector<sirdata> generate_data(int duration);

    }
}




#endif