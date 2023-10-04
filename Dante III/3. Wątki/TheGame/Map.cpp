#include "Map.h"
#include <cursesw.h>

#define py 2
#define px 3
#define mw 51

Map::Map() {
    initializeMap();
    printMap();
    printAdditionalInfo();
    refresh();

    getch();
}

Map::~Map(){
    endwin();
}

void Map::initializeMap(){
    setlocale(LC_ALL, "");
    initscr();
    clear();
    cbreak();
    noecho();
    cbreak();
    nonl();
    leaveok(stdscr, TRUE);
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    curs_set(0);
}


void Map::printMap()
{
    mvprintw(py+0,px,"███████████████████████████████████████████████████");
    mvprintw(py+1,px,"█c  █       █   #####       █         █ccccccc█   █");
    mvprintw(py+2,px,"█ █ ███ ███ ███████████ ███ █ ███████ ███ █████ t █");
    mvprintw(py+3,px,"█ █   █ █ █           █ █ █   █     █     █   █   █");
    mvprintw(py+4,px,"█ ███ █ █ ███###█████ █ █ █████ █████████████ ███ █");
    mvprintw(py+5,px,"█ █T█   █           █ █ █ ##  █      c█       █ █ █");
    mvprintw(py+6,px,"█ █ █████ ███ ███████ █ █ █ ███ ███ ███ ███ █ █ █ █");
    mvprintw(py+7,px,"█ █         █ █       █ █ █     █   █   █ █ █   █ █");
    mvprintw(py+8,px,"█ █ ███████ ███ ███████ █████ ███ ███ ███ █ ███ █ █");
    mvprintw(py+9,px,"█ █T█     █   █   █     █   █   █         █ █ █ █ █");
    mvprintw(py+10,px,"█ ███ ███ ███ ███ ███ ███ █ ███ ███████████ █ █ █ █");
    mvprintw(py+11,px,"█ █   █       █ █  c█  A  █ █   █ █  D    █ █   █ █");
    mvprintw(py+12,px,"█ █ ██████#██ █ ███ ███ ███ ███ █ █ █████ █ █ ███ █");
    mvprintw(py+13,px,"█ █    #█   █ █   █   █   █   █   █ █     █ █ █   █");
    mvprintw(py+14,px,"█ █ █ ##█ ███ ███ ███ ███████ ███ █ ███ ███ █ █ ███");
    mvprintw(py+15,px,"█ █ █## █    #  █   █ █  ###  █   █   █     █ █ █ █");
    mvprintw(py+16,px,"█ █ █#  ███████ █ █ █ █ ██#████ █████ ███████ █ █ █");
    mvprintw(py+17,px,"█ █ █#      █   █ █ █   █     █   █ █       ##█   █");
    mvprintw(py+18,px,"█ █████████ █ ███ ███████ ███████ █ █████ █ ##███ █");
    mvprintw(py+19,px,"█ █#      █ █     █     █       █   █   █ █ ##  █ █");
    mvprintw(py+20,px,"█ █ █████ █ ███████ █ ███ █████ ███ █ █ ███#█████ █");
    mvprintw(py+21,px,"█###█     █         █  ###█## █     █ █   █###### █");
    mvprintw(py+22,px,"█c███ █████████████████████#█ ███████ ███ █#    # █");
    mvprintw(py+23,px,"█ccc█                 ######█##         █    ##   █");
    mvprintw(py+24,px,"███████████████████████████████████████████████████");
}

void Map::printAdditionalInfo(){
    mvprintw(py+1,px+mw+4,"Server's PID: ");
    mvprintw(py+2,px+mw+4,"Campsite X/Y: ");
    mvprintw(py+3,px+mw+4,"Round number: ");
    mvprintw(py+5,px+mw+4,"Round number: ");
}