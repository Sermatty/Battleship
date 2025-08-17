#include "gioco.hpp"
#include "const.hpp"
#include "stampa.hpp"

#include <curses.h>

Stampa::Stampa(int lines,int cols): Lines(lines), Cols(cols) {}

Stampa::Stampa() {}

void Stampa::Inizio(){
    clear();
    StampaSchermoCaricamento(schermata::INIZIO);
}

void Stampa::HaiVinto(){
    clear();
    StampaSchermoCaricamento(schermata::HAIVINTO);
}

void Stampa::HaiPerso(){
    clear();
    StampaSchermoCaricamento(schermata::HAIPERSO);
}

void Stampa::Pausa(){
    clear();
    StampaSchermoCaricamento(schermata::PAUSA);
}

void Stampa::StampaSchermoCaricamento(const char *schermata[]){
    for(int i=0;schermata[i]!=NULL;i++){
        mvprintw(i,0,schermata[i]);
        mvchgat(i, 0, -1, A_NORMAL, 1, NULL);
    }
}

void Stampa::StampaTabelloneGioco(char Schermo[][constant::C]){
    clear();
    for(int i=Bordo_r-1;i<Bordo_r+constant::R+1;i++){
        for(int j=Bordo_c-1;j<Bordo_c+constant::C+1;j++){
            if(i==Bordo_r-1 && j>=Bordo_c && j<=Bordo_c+constant::C && LINES!=constant::R || i==Bordo_r+constant::R && j>=Bordo_c && j<=Bordo_c+constant::C && LINES!=constant::R) {
                mvaddch(i,j,'#');
            }
            else if(j==Bordo_c-1 && i>=Bordo_r && i<=Bordo_r+constant::R && COLS!=constant::C || j==Bordo_c+constant::C && i>=Bordo_r && i<=Bordo_r+constant::R && COLS!=constant::C) {
                mvaddch(i,j,'#');
            }
            else if(i>=Bordo_r && i<Bordo_r+constant::R && j>=Bordo_c && j<Bordo_c+constant::C) {
                mvaddch(i,j,Schermo[i-Bordo_r][j-Bordo_c]);
            }
            
        }
    }
}

BordoSchermo::BordoSchermo(int lines, int cols): Stampa(lines, cols) {}

void BordoSchermo::CalcolaBordo(){
    Bordo_c=(Cols-constant::C)/2;
    Bordo_r=(Lines-constant::R)/2;
}