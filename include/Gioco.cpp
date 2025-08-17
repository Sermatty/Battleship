#include "const.hpp"
#include "gioco.hpp"
#include "stampa.hpp"
#include "giocatori.hpp"


#include <iostream>
#include <curses.h>
#include <signal.h>
#include <string>

void Gioco::Inizializza(){
    initscr();
    cbreak();
    noecho();   
    keypad(stdscr, TRUE);  

    BordoSchermo bordoschermo = BordoSchermo(LINES,COLS);
    bordoschermo.CalcolaBordo();

    if(LINES>=constant::R&&COLS>=constant::C) return;

    mvprintw(0,0,"La finestra deve essere di almeno %d*%d",constant::C,constant::R);
    mvprintw(1,0,"Attualmente la vostra finestra e' di: %d*%d",COLS,LINES);
    mvprintw(2,0,"Premere qualsiasi tasto per continuare...");

    refresh();
    getch();
    endwin();

    Grandezza_schermo_rispettata=false;
}

void Gioco::Esegui(){
    if(!Grandezza_schermo_rispettata) return;
    Stampa stampa;

    while(key!='q'){

        stampa.Inizio();
        refresh();
        key=getch();

        switch(key){
            case '1':
                break;
            case '2':
                break;
            case 'q':
                break;
        }
    }

}