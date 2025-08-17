#pragma once
#include "const.hpp"

class Player {
protected:
    int x;
    int y;
    bool found;

public:

    void Inizializza_pos(int,int);
    void Stampa_var();

    Player(int _x, int _y, bool _found); 
};


class Board : public Player{
private:
    std::string players_id_board;

public:
    void refresh_board(char [][constant::C]);
    Board(int,int,bool,std::string);

};
