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
    int rowIndex = 0, colIndex = 0;
    int nRounds = (boardSize*boardSize)/2;
    board.updateBoard();

    for (int i = 0; i < nRounds; i++){
        // player one turn
        do {
            cout << "player " << pl1.getPlayerName() << " turn!" << endl;
            cout << "set marker location!\n";
            cout << "row index >>> ";
            cin >> rowIndex;
            cout << "column index >>> ";
            cin >> colIndex;
            correctIndex = board.placeMarker(pl1, rowIndex, colIndex);
        }while (!correctIndex);
        // board.updateBoard();

        do{
            // player two turn
            cout << "player " << pl2.getPlayerName() << " turn!" << endl;
            cout << "set marker location!\n";
            cout << "row index >>> ";
            cin >> rowIndex;
            cout << "column index >>> ";
            cin >> colIndex;
            correctIndex = board.placeMarker(pl2, rowIndex, colIndex);
        }while (!correctIndex);
        // board.updateBoard();
    }

    
}

