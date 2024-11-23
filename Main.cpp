#include "Game.hpp"

int main(){

    Board b;
    b.generateBoard();
    b.printBoard();

    do{
        b.makeSwitch();
        b.printBoard();
    }while(b.checkifDone()==false);

    return 0;
}
