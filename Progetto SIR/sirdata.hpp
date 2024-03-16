#ifndef sirdata_HPP
#define sirdata_HPP

class sirdata {

    private:
    int pop; 
    int susc;   //suscettibili 
    int inf;   //infetti
    int rim;   //rimossi 
    void set_pop(int population); // può cambiarlo solo la classe 
    public:
    sirdata(const int suscettibili, const int infetti, const int rimossi);
    int get_susc();
    void set_susc(const int suscettibili);
    int get_inf();
    void set_inf(const int infetti);
    int get_rim();
    void set_rim(const int rimossi);
    int get_pop();
    bool check_pop();
    
};

#endif
