#pragma once

#include <iostream>

namespace constant{
    const int C=50;
    const int R=30;
}

namespace tavolo{
    const int C=5;
    const int R=5;
}

namespace casella{
    const char fuoritabellone=' ';
    const char inesplorata='-';
    const char vuota='o';
    const char colpita='X';

}

namespace schermata{
    extern const char *INIZIO[];
    extern const char *HAIVINTO[];
    extern const char *HAIPERSO[];
    extern const char *PAUSA[];
    extern const char *POSX;
    extern const char *POSY;
    
}

