#include "sirdata.hpp"
#include "sirmodel.hpp"
#include "sirmanage.hpp"
#include <fstream>
#include <iostream>

using namespace std;

namespace Sirmodel {

    sirmanage::sirmanage() {}
    sirmanage::~sirmanage() {
        if(sr != NULL ) sr ->close();
        if(sw != NULL ) sw ->close();
    }
    sirmanage::sirmanage(string in_filep){
        string str;
        set_in_filepath(in_filep);
        sr = new ifstream(in_filep, ios::in); //riguarda

        //Reading output type
        if(sr != NULL) str = read_row_fromfile();
        if (str != "") set_output_type('S');
        //Reading output file 
        if (sr != NULL) str = read_row_fromfile();
        if(str != ""){
            set_out_filepath(str);
            sw =new ofstream(get_out_filepath());
        
        }

    }

    string sirmanage::get_in_filepath() {return in_filepath;}
    void sirmanage::set_in_filepath(string filepath){
        if (filepath != "") in_filepath = filepath;
        else throw "Error: file path is empty";
    }

    string sirmanage::get_out_filepath(){return out_filepath;}
    void sirmanage::set_out_filepath(string filepath){
        if (filepath != "") out_filepath = filepath;
        else throw "Error: file path is empty";
    }

    char sirmanage::get_output_type(){return output_type;}
    void sirmanage::set_output_type(char out_type){
        if (out_type != '\0') output_type = out_type;
        else throw "Error: file path is empty";
    }

    string sirmanage::read_row_fromfile(){
        string row;
        int pos = -1; // riguarda
        if(sr != NULL){
            getline(*sr,row);
            pos = row.find("=");
            if(pos != -1){
                row = row.substr(pos +1);
                return row;
            }
            else return "";
        }
        else return "";
    }

    void sirmanage::printdata(sirdata d){
        if (get_output_type() == 'S') cout << d.toString();
        else if (get_output_type() == 'F') *sw << d.toString();
    }



}
