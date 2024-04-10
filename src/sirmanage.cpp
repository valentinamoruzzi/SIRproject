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
    sirmanage::sirmanage(const string &in_filep){
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
    void sirmanage::set_in_filepath(const string &filepath){
        if (filepath != "") in_filepath = filepath;
        else throw "Error: file path is empty";
    }

    string sirmanage::get_out_filepath(){return out_filepath;}
    void sirmanage::set_out_filepath(const string &filepath){
        if (filepath != "") out_filepath = filepath;
        else throw "Error: file path is empty";
    }

    char sirmanage::get_output_type(){return output_type;}
    void sirmanage::set_output_type(const char &out_type){
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

    void sirmanage::draw(vector <sirdata> &results, const int &duration, const string &model){
        //setting window parameters
        sf::RenderWindow window(sf::VideoMode(1200,800), "SFMLplot", sf::Style::Default);

        //setting plotting parameters
        plot_tmp.setSize(sf::Vector2f(1200,800));
        plot_tmp.setTitle(model);
        plot_tmp.setFont("./font.ttf");
        plot_tmp.setXLabel("Time");
        plot_tmp.setYLabel("Population");
        plot_tmp.setTitleColor(sf::Color::Black);

        //creating curves
        sf::plot::Curve &s_curve = plot_tmp.createCurve("Susceptibles", sf::Color::Red);
        s_curve.setThickness(2);
        s_curve.setFill(false);
        s_curve.setLabel("Susceptibles");

        sf::plot::Curve &i_curve = plot_tmp.createCurve("Infected", sf::Color::Blue);
        i_curve.setThickness(2);
        i_curve.setFill(false);
        i_curve.setLabel("Infected");

        sf::plot::Curve &r_curve = plot_tmp.createCurve("Recovered", sf::Color::Green);
        r_curve.setThickness(2);
        r_curve.setFill(false);
        r_curve.setLabel("Recovered");

        //adding points
        for(int x =0; x<duration; x++){
            s_curve.addValue(results[x].get_susc());
            i_curve.addValue(results[x].get_inf());
            r_curve.addValue(results[x].get_rec());
        }

    plot_tmp.prepare();
        while(window.isOpen()){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                window.close();
            }
            window.clear();
            window.draw(plot_tmp);
            window.display();

        }

    }

    void sirmanage::printdata(vector <sirdata> results, const int &duration, const string &model){
        
        if(get_output_type() == 'S'){
            for(auto &data : results){
                cout << data.toString() << endl;
            }
        }
        else if(get_output_type() == 'F'){
            for(auto &data : results){
                *sw << data.toString() << endl;
            }
        }
        else if(get_output_type() == 'P') {
            plot(results, duration, model);
        }
        else throw "Errore: output errato";
        }
    }




