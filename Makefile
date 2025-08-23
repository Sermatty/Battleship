
TARGET = battaglia.exe
SRCDIR = src
INDIR = include
LIBDIR = lib/windows

SOURCES = $(SRCDIR)/main.cpp  $(INDIR)/Const.cpp $(INDIR)/Gioco.cpp $(INDIR)/Player.cpp $(INDIR)/Stampa.cpp


all:
	g++ $(SOURCES) -Iexternal -L$(LIBDIR) -lpdcurses -finput-charset=UTF-8 -fexec-charset=UTF-8 -o $(TARGET)


clean:
	del $(TARGET)
