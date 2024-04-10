#ifndef sirmanage_HPP
#define sirmanage_HPP
#include <string>
#include "sirdata.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "sfml/plot.h"

using namespace std;

namespace Sirmodel {
class sirmanage: public sf::Drawable{
    private:
    string in_filepath;
    string out_filepath;
    char output_type;
    ifstream *sr = NULL;
    ofstream *sw = NULL;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void plot(vector <sirdata> &results, const int &n, const string &model);
    sf::plot::Plot plot_tmp;
    public:
    sirmanage();
    ~sirmanage();
    sirmanage(const string &in_filep);

    string get_in_filepath();
    void set_in_filepath(const string &filepath);

    string get_out_filepath();
    void set_out_filepath(const string &filepath);

    char get_output_type();
    void set_output_type( const char &out_type);

    string read_row_fromfile();
    void draw(vector<sirdata> &results, const int &duration, const string &model);
    void printdata(vector<sirdata> results, const int &duration, const string &model);
};

}
#endif