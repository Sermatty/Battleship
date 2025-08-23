#include "const.hpp"
#include "stampa.hpp"

#include <curses.h>

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

void Stampa::ErroreDimensioniSchermo(){
    clear();
    mvprintw(0,0,"La finestra deve essere di almeno %d*%d",constant::C,constant::R);
    mvprintw(1,0,"Attualmente la vostra finestra e' di: %d*%d",COLS,LINES);
    mvprintw(2,0,"Premere qualsiasi tasto per continuare...");
}

void Stampa::ChiederePosizioneNave(){
    clear();
    mvprintw(0,0,"Inserire Posizione Nave: (x e y con riferimento piano cartesiano) ");
    mvprintw(1,0,"1 <= x <= %d",tavolo::C);
    mvprintw(2,0,"1 <= y <= %d",tavolo::R);
    mvprintw(3,0,"Premere qualsiasi tasto per continuare...");    
}

void Stampa::StampaSchermoCaricamento(const char *schermata[]){
    for(int i=0;schermata[i]!=NULL;i++){
        mvprintw(i,0,schermata[i]);
        mvchgat(i, 0, -1, A_NORMAL, 1, NULL);
    }
}

void Stampa::StampaTabellonePlayer(int y, int x,char (&Schermo)[][tavolo::C]){
    int Y=y+Bordo_r+1;
    int X=x+Bordo_c+1;
    for(int i=Y;i<Y+tavolo::R;i++){
        for(int j=X;j<X+tavolo::C*2;j++){
            if((j-X)%2==0){
                mvaddch(i,j,Schermo[i-Y][(j-X)/2]);
            }

        }
    }
}

void Stampa::StampaBordo(){
    clear();
    for(int i=Bordo_c;i<Bordo_c+constant::C+1;i++){
        mvaddch(Bordo_r,i,'#');
        mvaddch(Bordo_r+constant::R+1,i,'#');
    }

    for(int i=Bordo_r;i<Bordo_r+constant::R+1;i++){
        mvaddch(i,Bordo_c,'#');
        mvaddch(i,Bordo_c+constant::C+1,'#');
    }
}

void Stampa::CalcolaBordo(){
    Bordo_c=(COLS-constant::C)/2-1;
    Bordo_r=(LINES-constant::R)/2-1;
}

void Stampa::ChiederePosizioneDaAttaccare(int y,int x, const char* stringa){
    int Y=y+Bordo_r+1;
    int X=x+Bordo_c+1;
    mvprintw(Y,X,stringa);
}