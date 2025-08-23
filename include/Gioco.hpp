#pragma once
#include "const.hpp"
#include "stampa.hpp"
#include "player.hpp"

class Gioco{
private:
    bool Grandezza_schermo_rispettata=true;
    char key=' ';
    Stampa stampa;
    Player player1;
    Player player2;

public:
    void Inizializza();
    void Esegui();
    void Stop();
    void InizializzaPlayerVsPlayer();
    void LogicaPlayerVSPlayer();
    void InizializzaPlayerVSComputer();
    void LogicaPlayerVsComputer();
};