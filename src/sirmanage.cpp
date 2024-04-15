#include "sirmanage.hpp"

using namespace std;

namespace Sirmodel {

sirmanage::sirmanage() {}
sirmanage::~sirmanage() {
  if (sr != NULL)
    sr->close();
  if (sw != NULL)
    sw->close();
}
sirmanage::sirmanage(const string &in_filep) {
  string str;
  set_in_filepath(in_filep);
  sr = new ifstream(in_filep, ios::in); // riguarda

  // Reading output type
  if (sr != NULL) {
    str = read_row_fromfile();
    set_output_type(str[0]);
  }

  // Reading output file
  if (sr != NULL)
    str = read_row_fromfile();
  if (str != "") {
    set_out_filepath(str);
    sw = new ofstream(get_out_filepath());
  }
}

string sirmanage::get_modeltype() { return modeltype; }
void sirmanage::set_modeltype(const string &m) {
  if (m != "")
    modeltype = m;
  else
    throw "ERROR";
}

string sirmanage::get_in_filepath() { return in_filepath; }
void sirmanage::set_in_filepath(const string &filepath) {
  if (filepath != "")
    in_filepath = filepath;
  else
    throw "Error: file path is empty";
}

string sirmanage::get_out_filepath() { return out_filepath; }
void sirmanage::set_out_filepath(const string &filepath) {
  if (filepath != "")
    out_filepath = filepath;
  else
    throw "Error: file path is empty";
}

char sirmanage::get_output_type() { return output_type; }
void sirmanage::set_output_type(const char &out_type) {
  if (out_type != '\0')
    output_type = out_type;
  else
    throw "Error: file path is empty";
}

string sirmanage::read_row_fromfile() {
  string row;
  int pos = -1; // riguarda
  if (sr != NULL) {
    getline(*sr, row);
    pos = row.find("=");
    if (pos != -1) {
      row.erase(remove(row.begin(), row.end(), ' '), row.end());
      row = row.substr(pos);
      return row;
    }

    else
      return "";
  } else
    return "";
}

ofstream *sirmanage::get_sw() { return sw; }
} // namespace Sirmodel
