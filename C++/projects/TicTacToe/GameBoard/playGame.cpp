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
    bool correctIndex;
    
    board.updateBoard();
    int nRounds = board.getMaxRounds();
    while (board.roundsCounter < nRounds){
        board.takeTurns(pl1);
        board.takeTurns(pl2);
        
        cout << "\n========\n";
        cout << "game ends!\n";
    }
}

