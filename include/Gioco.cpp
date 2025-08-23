#include "const.hpp"
#include "gioco.hpp"
#include "stampa.hpp"
#include "player.hpp"

#include <iostream>
#include <curses.h>
#include <signal.h>
#include <string>

void Gioco::Inizializza(){
    initscr();
    cbreak();
    noecho();   
    keypad(stdscr, TRUE);  

    stampa.CalcolaBordo();

    if(LINES>=constant::R&&COLS>=constant::C) return;

    stampa.ErroreDimensioniSchermo();
    refresh();
    getch();
    endwin();

    Grandezza_schermo_rispettata=false;
}

void Gioco::Esegui(){
    if(!Grandezza_schermo_rispettata) return;

    while(key!='q'){
        stampa.Inizio();
        refresh();
        key=getch();

        switch(key){
            case '1':
                break;
            case '2':
                InizializzaPlayerVsPlayer();
                stampa.StampaBordo();
                stampa.StampaTabellonePlayer(20, 10, player1.ottieniTabellone());
                stampa.StampaTabellonePlayer(20, 30, player2.ottieniTabellone());
                refresh();

                while(!player1.OttieniSeColpito()&&!player2.OttieniSeColpito()){
                    
                    LogicaPlayerVSPlayer();

                    //test
                    // char (&tabellone)[tavolo::R][tavolo::C]=player1.ottieniTabellone();
                    // for(int i=0;i<tavolo::R;i++){
                    //     for(int j=0;j<tavolo::C;j++){
                    //         std::cout<<tabellone[i][j]<<" ";
                    //     }
                    //     std::cout<<std::endl;
                    // }
                    // fine test

                }
                break;
            case 'q':
                break;
        }
    }

}

void Gioco::InizializzaPlayerVsPlayer(){
    int x1,y1;
    int x2,y2;

    stampa.ChiederePosizioneNave();
    refresh();
    getch();

    do{
        clear();
        mvprintw(0,0,"GIOCATORE 1:");
        mvprintw(1,0,"x: ");
        refresh();
        
        echo();
        x1=static_cast<int>(getch())-'0';
        noecho();

        mvprintw(2,0,"y: ");
        refresh();

        echo();
        y1=static_cast<int>(getch())-'0';
        noecho();
    }while(x1<1 || x1>tavolo::C || y1<1 || y1>tavolo::R);

    player1.InizializzaPos(x1,y1);
    player1.InizializzaTabellone();

    do{
        clear();
        mvprintw(0,0,"GIOCATORE 2:");
        mvprintw(1,0,"x: ");
        refresh();

        echo();
        x2=static_cast<int>(getch())-'0';
        noecho();

        mvprintw(2,0,"y: ");
        refresh();

        echo();
        y2=static_cast<int>(getch())-'0';
        noecho();
    }while(x2<1 || x2>tavolo::C || y2<1 || y2>tavolo::R);

    player2.InizializzaPos(x2,y2);
    player2.InizializzaTabellone();


}

void Gioco::LogicaPlayerVSPlayer(){
    int x1,y1;
    int x2,y2;
    do{
        stampa.ChiederePosizioneDaAttaccare(15,10,schermata::POSX);
        refresh();

        echo();
        x1=static_cast<int>(getch())-'0';
        noecho();

        stampa.ChiederePosizioneDaAttaccare(16,10,schermata::POSY);
        refresh();

        echo();
        y1=static_cast<int>(getch())-'0';
        noecho();
    }while(x1<1 || x1>tavolo::C || y1<1 || y1>tavolo::R);

    player2.ControllaSeColpito(x1,y1);
    player2.AggiornaTabellonePlayer(x1,y1);
    stampa.StampaTabellonePlayer(20, 30, player2.ottieniTabellone());
    refresh();

    if(player2.OttieniSeColpito()) return;


    do{
        stampa.ChiederePosizioneDaAttaccare(15,30,schermata::POSX);
        refresh();

        echo();
        x2=static_cast<int>(getch())-'0';
        noecho();

        stampa.ChiederePosizioneDaAttaccare(16,30,schermata::POSY);
        refresh();

        echo();
        y2=static_cast<int>(getch())-'0';
        noecho();
    }while(x2<1 || x2>tavolo::C || y2<1 || y2>tavolo::R);

    player1.ControllaSeColpito(x2,y2);
    player1.AggiornaTabellonePlayer(x2,y2);
    stampa.StampaTabellonePlayer(20, 10, player1.ottieniTabellone());
    refresh();
    

    if(player1.OttieniSeColpito()) return;
}