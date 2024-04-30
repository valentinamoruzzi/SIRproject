#include "sirmanage.hpp"
#include <algorithm>
#include <fstream>
#include <string>

sirmanage::sirmanage():sirmanage("sirmodel.cfg"){}

sirmanage::sirmanage(const std::string &in_filep) {
  
  set_in_filepath(in_filep);
  sr.open(in_filep, std::ios::in); // riguarda

  // Reading output type
    std:: string str = read_row_fromfile();
    set_output_type(str[0]);

  // Reading output file
  str = read_row_fromfile();
  if (!str.empty()) {
    set_out_filepath(str);
    std::ofstream sw(get_out_filepath());
  }
}

std::string sirmanage::get_modeltype() const { return modeltype; }
void sirmanage::set_modeltype(const std::string &m) {
  if (!m.empty()){
    modeltype = m;
  }
  else {
    throw std::runtime_error{"Error: model type is empty\n"};
  }
}

std::string sirmanage::get_in_filepath() const { return in_filepath; }
void sirmanage::set_in_filepath(const std::string &filepath) {
  if (!filepath.empty()) {
    in_filepath = filepath;
  }
  else {
    throw std::runtime_error{"Error: file path is empty\n"};
  }
}

std::string sirmanage::get_out_filepath() const { return out_filepath; }
void sirmanage::set_out_filepath(const std::string &filepath) {
  if (!filepath.empty()) {
    out_filepath = filepath;
  }
  else {
    throw std::runtime_error{ "Error: file path is empty\n"};
  }
}

char sirmanage::get_output_type() const { return output_type; }
void sirmanage::set_output_type(const char &out_type) {
  if (out_type != '\0'){
    output_type = out_type;
  }
  else {
    throw std::runtime_error{ "Error: file path is empty\n"};
  }
}

std::string sirmanage::read_row_fromfile() {
  std::string row;
  int pos = -1; // riguarda

  if (sr.is_open()) {
    getline(sr, row);
    pos = row.find("=");
    if (pos != -1) {
      row.erase(remove(row.begin(), row.end(), ' '), row.end());
      row = row.substr(pos);
      return row;
    }

    else
      return "";
  } else
  std::runtime_error{"Error: input file is closed\n"};
    return "";
}
std::ofstream &sirmanage::get_sw() { return sw; }

bool sirmanage:: isinteger(const std::string &s){
  std::string::const_iterator it = s.begin();
  while(it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

bool sirmanage:: isfloatnumber(const std::string &s){
  std::string::const_iterator it = s.begin();
  while((it != s.end() && (std::isdigit(*it))) || *it == '.') ++it;
  return !s.empty() && it == s.end();
}

