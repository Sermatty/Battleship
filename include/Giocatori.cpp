#include "giocatori.hpp"

#include <iostream>
#include <curses.h>
#include <signal.h>
#include <string>


Player::Player(int _x, int _y, bool _found) : x(_x), y(_y), found(_found){}



void Player::Stampa_var(){
        std::cout<<"x: "<<x<<'\n';
        std::cout<<"y: "<<y<<'\n';
        std::cout<<"e' stato trovato: "<<found<<'\n';

    }

void Player::Inizializza_pos(int _x, int _y){
    x=_x;
    y=_y;
}

void Board::refresh_board(char board[][constant::C]){
    board[10][10]='4';
}

Board::Board(int _x, int _y, bool _found, std::string _id): Player(_x,_y,_found), players_id_board(_id) {}