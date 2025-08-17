#pragma once
#include "const.hpp"

class Stampa{
private:
    void StampaSchermoCaricamento(const char *schermata[]);

protected:
    int Bordo_c;
    int Bordo_r;
    int Lines;
    int Cols;
    Stampa(int,int);

public:
    void StampaTabelloneGioco(char [][constant::C]);
    void Inizio();
    void HaiVinto();
    void HaiPerso();
    void Pausa();
    Stampa();

};

class BordoSchermo: public Stampa{
public:
    void CalcolaBordo();
    BordoSchermo(int,int);
};