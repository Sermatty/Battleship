#pragma once
#include "const.hpp"

class Stampa{
private:
    void StampaSchermoCaricamento(const char *schermata[]);
    int Bordo_c;
    int Bordo_r;

public:
    void CalcolaBordo();
    void StampaBordo();
    void StampaTabellonePlayer(int,int,char (&)[][tavolo::C]);
    void Inizio();
    void HaiVinto();
    void HaiPerso();
    void Pausa();
    void ErroreDimensioniSchermo();
    void ChiederePosizioneNave();
    void ChiederePosizioneDaAttaccare(int,int, const char*);
    Stampa();

};
