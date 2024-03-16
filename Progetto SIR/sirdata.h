#ifndef sirdata_H
#define sirdata_H

class sirdata {

    private:
    const float beta;   //indice contagiosità 
    const float gamma = 0;  //indice mortalità
    const int num = susc + inf + rim; 
    int susc;   //suscettibili 
    int inf;   //infetti
    int rim;   //rimossi 
    void suscettibile(int susc) ;
    void infetto(int inf) ;
    void rimosso(int rim);

    public:
    sirdata(int suscettibili, int infetti, int rimossi);
    void set_parameters(int be, int ga);
    int get_susc();
    void set_susc(int suscettibili);
    int get_inf();
    void set_inf(int infetti);
    int get_rim();
    void set_rim(int rimossi);
    float get_beta() ;
    void set_beta(int be );
    float get_gamma() ;
    void set_gamma(int ga) ;

};

#endif
