#ifndef sirmanage_HPP
#define sirmanage_HPP
#include <iostream>

class sirmanage {
private:
  std::string in_filepath;
  std::string out_filepath;
  char output_type;
  std::string modeltype;
  std::ifstream sr;
  std::ofstream sw;

public:
  sirmanage() = default ;
  sirmanage(const std::string &in_filep);

  std::string get_modeltype();
  void set_modeltype(const std::string &m);

  std::string get_in_filepath();
  void set_in_filepath(const std::string &filepath);

  std::string get_out_filepath();
  void set_out_filepath(const std::string &filepath);

  char get_output_type();
  void set_output_type(const char &out_type);

  std::ofstream get_sw();

  std::string read_row_fromfile();
};

#endif