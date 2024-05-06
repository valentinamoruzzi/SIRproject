#ifndef sirmanage_HPP
#define sirmanage_HPP
#include <fstream>
#include <iostream>

class sirmanage
{
 private:
  std::string in_filepath;
  std::string out_filepath;
  char output_type;
  std::string modeltype;
  std::ifstream sr;
  std::ofstream sw;

 public:
  sirmanage();
  sirmanage(const std::string& in_filep);

  std::string get_modeltype() const;
  void set_modeltype(const std::string& m);

  std::string get_in_filepath() const;
  void set_in_filepath(const std::string& filepath);

  std::string get_out_filepath() const;
  void set_out_filepath(const std::string& filepath);

  char get_output_type() const;
  void set_output_type(const char& out_type);

  std::ofstream& get_sw();

  std::string read_row_fromfile();
  static bool isinteger(const std::string& s);
  static bool isfloatnumber(const std::string& s);
};

#endif