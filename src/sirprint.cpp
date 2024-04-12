#include "sirprint.hpp"
using namespace std;

namespace Sirmodel {

sirprint::sirprint(sirmanage *c, sirmodel *sir) { set_cfg(c); set_model(sir); }
sirprint::sirprint(sirmanage *c, sirmodelextended *sirs) { set_cfg(c); set_modelextended(sirs); }

void sirprint::set_cfg(sirmanage *c){
   if(c!=NULL) cfg = c;
   else throw "Configuratore nullo";
}
void sirprint::set_model(sirmodel *sir_){
   if(sir_ !=NULL) sir = sir_;
   else throw "Configuratore nullo";
}

void sirprint::set_modelextended(sirmodelextended *sirs_){
   if(sirs_ !=NULL) sirs = sirs_;
   else throw "Configuratore nullo";
}

void sirprint::print_tostdout(vector<sirdata> results, const int &duration){ 
   
   int pop = results[0].get_susc() + results[0].get_inf() + results[0].get_rec();
   
   cout << "|" << setw(5) << "Time"  
        << "|" << setw(5) << "Susc" 
        << "|" << setw(5) << "Inf" 
        << "|" << setw(5) << "Rec" 
        << "|" << setw(5) << "Beta" 
        << "|" << setw(5) << "Gamma";
  
   if(cfg->get_modeltype() == "sirmodelextended") cout << "|" << setw(5) << "Alpha";

   cout << "|" << setw(5) << "Pop" << "|" << endl;
   for(int day=0; day<duration; day++){  
      
   cout << "|" << setw(5) << day  
         << "|" << setw(5) << results[day].get_susc() 
         << "|" << setw(5) << results[day].get_inf() 
         << "|" << setw(5) << results[day].get_rec();
         if(cfg->get_modeltype() == "sirmodel") cout << "|" << setw(5) << sir->get_beta();
         else cout << "|" << setw(5) << sirs->get_beta();
         if(cfg->get_modeltype() == "sirmodel") cout << "|" << setw(5) << sir->get_gamma();
         else cout << "|" << setw(5) << sirs->get_gamma();
         if(cfg->get_modeltype() == "sirmodelextended") cout << "|" << setw(5) << sirs->get_alpha();
         cout << "|" << setw(5) << pop << "|" << endl;
   }
}
void sirprint::print_tofile(vector<sirdata> results, const int &duration){
   for(int i=0; i<duration; i++){
   	*cfg->get_sw() << results[i].toString() << endl;
   }
}
void sirprint::draw(sf::RenderTarget& target, sf::RenderStates states) const{  
   target.draw(plot_, states);
}
void sirprint::plot(vector<sirdata> &results, const int &duration){
   
   // setting window parameters
   sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML plot", sf::Style::Default);
   

   // setting plotting parameters
   plot_.setSize(sf::Vector2f(1200, 800));
   plot_.setTitleColor(sf::Color::Black);
   plot_.setTitle("\t\t\t\t\t\t\t\t\t\t\t\t"+cfg->get_modeltype() + "\nRed: Susceptibles - Green: Removed - Blue: Infected");
   plot_.setFont("./font.ttf");
   plot_.setXLabel("Time");
   plot_.setYLabel("Populations");


   // Creating curves
   sf::plot::Curve &s_curve = plot_.createCurve("Susceptibles", sf::Color::Red);
   s_curve.setThickness(2);
   s_curve.setFill(false);
   s_curve.setLabel("Susceptibles");

   sf::plot::Curve &r_curve= plot_.createCurve("Recovered", sf::Color::Green);
   r_curve.setThickness(2);
   r_curve.setFill(false);
   r_curve.setLabel("Recovered");
   
   sf::plot::Curve &i_curve = plot_.createCurve("Infected", sf::Color::Blue);
   i_curve.setThickness(2);
   i_curve.setFill(false);
   i_curve.setLabel("Infected");

   for(int x=0; x<duration; x++){
      s_curve.addValue(results[x].get_susc());
      r_curve.addValue(results[x].get_rec());
      i_curve.addValue(results[x].get_inf());
   }
  
   plot_.prepare();
   while (window.isOpen()){                                                                                                                                                                                                                                                                                                                                                  
      sf::Event event;
      while (window.pollEvent(event)){
         if(event.type == sf::Event::Closed)
               window.close();
      }  
      window.clear(sf::Color::White); 
      window.draw(plot_);
      window.display();
   }
}

void sirprint::printdata(vector<sirdata> results, const int &duration){
   cout << cfg ->get_output_type()<<endl;
   if(cfg->get_output_type() == 'S') print_tostdout(results, duration);
   else if(cfg->get_output_type() == 'F') print_tofile(results, duration);
   else if(cfg->get_output_type() == 'P') plot(results, duration);
   else throw "Errore: output errato";  
}
}