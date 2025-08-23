#pragma once
#include "const.hpp"

class Player {
protected:
    int X;
    int Y;
    char Tabellone[tavolo::R][tavolo::C];
    bool Colpito=false;

public:
    void InizializzaPos(int,int);
    void InizializzaTabellone();
    int OttieniPosX();
    int OttieniPosY();
    bool OttieniSeColpito();
    char (&ottieniTabellone())[tavolo::R][tavolo::C];
    void ControllaSeColpito(int,int);
    void AggiornaTabellonePlayer(int,int);
    void Stampa_var();
    Player(); 
};

