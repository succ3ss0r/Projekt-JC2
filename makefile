CC=g++
CFLAGS=-Wall -g -std=c++11

OBJ =\
	Background.o \
	Enemy.o \
	Engine.o \
	Menu.o \
	Score.o \
	Shot.o \
	SpaceShip.o \
	Health.o \
	Lose.o \
	Highscore.o \
	GetNickname.o \
	main.o

all: main
	@echo Aby uruchomic gre wpisz ./game

clean: 
	rm -f *.o game

.cpp.o:
	$(CC) -c $(CFLAGS) $< -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system

main: $(OBJ)
	$(CC) $(OBJ) -o game -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system