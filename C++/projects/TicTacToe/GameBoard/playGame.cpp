#include "playGame.hpp"


int main(void){
    char marker;
    string name;
    int boardSize;

    
    cout << "first player name: ";
    cin >> name;
    Player pl1(name, 'x');
    cout << "second player name: ";
    cin >> name;
    Player pl2(name, 'o');
    cout << "Enter board size: ";
    cin >> boardSize;
    GameBoard board(boardSize);

    // ---------------------------------
    int nRounds = (boardSize*boardSize)/2;
    board.updateBoard();
    for (int i = 0; i < nRounds; i++){
        
    }

    
}

