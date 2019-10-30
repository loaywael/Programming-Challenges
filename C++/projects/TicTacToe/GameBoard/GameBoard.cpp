#include "GameBoard.hpp"

GameBoard::GameBoard(int size): 
BOARD_SIZE(size), MAX_ROUNDS((BOARD_SIZE * BOARD_SIZE) / 2){
    // dynamically init the board with '-' in each empty space
    roundsCounter = 0;
    rowIndex = 0, colIndex = 0;
    for (int i = 0; i < BOARD_SIZE; i++){
        board[i] = new char [BOARD_SIZE];
        for (int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = '-';
        }
    }
}

int GameBoard::getMaxRounds(){
    return MAX_ROUNDS;
}

GameBoard::~GameBoard(){
    // release the memory allocated for the board array
    for (int i = 0; i < BOARD_SIZE; i++){
        delete[] board[i];
    }
    delete board;
}

void GameBoard::updateBoard(){
    // print the board after each update
    cout << "\n********\n";
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n********\n";
}

bool GameBoard::_placeMarker(Player &player, int row, int column){
    // update the board space for each player turn
    if (row >= BOARD_SIZE || column >= BOARD_SIZE){
        cout << "incorrect location: exceeded board limits!!!\n";
        return false;
    }
    if (this->board[row][column] != '-'){
        cout << "\nincorrect location: already have marker!\n";
        return false;
    }
    board[row][column] = player.getPlayerMarker();
    this->updateBoard();
    roundsCounter++;
    return true;
}

void GameBoard::takeTurns(Player &player){
    bool correctIndex = false;
    do {
            cout << "\nplayer " << player.getPlayerName() << " turn!" << endl;
            cout << "set marker location!\n";
            cout << "row index >>> ";
            cin >> rowIndex;
            cout << "column index >>> ";
            cin >> colIndex;
            cout << endl;
            correctIndex = this->_placeMarker(player, rowIndex, colIndex);
        }while (!correctIndex);

}

int GameBoard::checkResult(Player &player){
    /*  checks for each player that may have any 
        row, column, or diagonal filled with marks
        decide a winner or return game over
    */
    for (int i = 0; i < BOARD_SIZE; i++){
        int rowCnt = 0;
        for (int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] == player.getPlayerMarker()){
                rowCnt++;
            }
        }    
        if (rowCnt == BOARD_SIZE){
            player.setPlayerResult(true);
            return 1;
        }
    }
    
    return 0;
}