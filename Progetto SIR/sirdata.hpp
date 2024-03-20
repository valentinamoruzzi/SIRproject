#ifndef sirdata_HPP
#define sirdata_HPP

class sirdata {

    private:
    int pop; 
    int susc;   //susceptibles 
    int inf;   //infected
    int rec;   //recovered 
    void set_pop(int population); // può cambiarlo solo la classe 
    public:
    sirdata( int susceptibles, int infected, int recovered);
    int get_susc();
    void set_susc( int susceptibles);
    int get_inf();
    void set_inf( int infected);
    int get_rec();
    void set_rec( int recovered);
    int get_pop();
    bool check_pop();
    void toString();
    
};

#endif
