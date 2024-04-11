#ifndef sirmanage_HPP
#define sirmanage_HPP
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>


using namespace std;

namespace Sirmodel {
class sirmanage{
    private:
    string in_filepath;
    string out_filepath;
    char output_type;
    string modeltype;
    ifstream *sr = NULL;
    ofstream *sw = NULL;

    public:
    sirmanage();
    ~sirmanage();
    sirmanage(const string &in_filep);

    string get_modeltype();
    void set_modeltype(const string &m);

    string get_in_filepath();
    void set_in_filepath(const string &filepath);

    string get_out_filepath();
    void set_out_filepath(const string &filepath);

    char get_output_type();
    void set_output_type( const char &out_type);

    ofstream* get_sw();

    string read_row_fromfile();
    

};

}
#endif