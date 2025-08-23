#include "const.hpp"
#include "player.hpp"

#include <curses.h>

Player::Player() {}

void Player::InizializzaPos(int x, int y){
    X=x;
    Y=y;
}

void Player::InizializzaTabellone(){
    for(int i=0;i<tavolo::R;i++){
        for(int j=0;j<tavolo::C;j++){
            Tabellone[i][j]=casella::inesplorata;
        }
    }
}

char (&Player::ottieniTabellone())[tavolo::R][tavolo::C] {return Tabellone;}

int Player::OttieniPosX() {return X;}

int Player::OttieniPosY() {return Y;}

bool Player::OttieniSeColpito() {return Colpito;}

void Player::ControllaSeColpito(int x, int y){
    if(x==X&&y==Y) Colpito=true;
}

void Player::AggiornaTabellonePlayer(int x, int y){
    if(OttieniSeColpito()){
        Tabellone[y-1][x-1]=casella::colpita;
    }else{
        Tabellone[y-1][x-1]=casella::vuota;
    }
}



