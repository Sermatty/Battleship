#pragma once
#include "const.hpp"

class Gioco{
private:
    bool Grandezza_schermo_rispettata=true;
    char key=' ';
    char Tabellone[constant::R][constant::C];

public:
    void Inizializza();
    void Esegui();
    void Stop();
};