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
    bool pl_1_state;
    bool pl_2_state;
    board.updateBoard();
    int nRounds = board.getMaxRounds();

    while (1){
        // all spaces filled without winner
        if (board.roundsCounter/2 >= nRounds){
            cout << "\n========\n";
            cout << "Game Over!" << endl;
            break;
        }
        // player one turn
        board.takeTurns(pl1);
         pl_1_state = board.checkRows(pl1);
         if (pl_1_state) {
            cout << pl1.getPlayerName() + " Won the game!" << endl;
            break;
        }
        // player two turn
        board.takeTurns(pl2);
        pl_2_state = board.checkRows(pl2);
        if (pl_2_state) {
            cout << pl2.getPlayerName() + " Won the game!" << endl;
            break;
        }
 
    }
}