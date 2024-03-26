#ifndef sirmanage_HPP
#define sirmanage_HPP
#include <string>
#include "SirData.hpp"

using namespace std;

namespace sirmodel {
class sirmanage{
    private:
    string in_filepath;
    string out_fliepath;
    char output_type;
    ifstream *sr = NULL;
    ofstream *sw = NULL;
    public:
    sirmanage();
    ~sirmanage();
    sirmanage(string in_filep);

    string get_in_filepath();
    void set_in_filepath(string filepath);

    string get_out_filepath();
    void set_out_filepath(string filepath);

    char get_output_type();
    void set_output_type( char out_type);

    string read_row_fromfile();
    void printdata(sirdata d);

};

}
#endif