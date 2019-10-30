#include "GameBoard.hpp"

GameBoard::GameBoard(int size): BOARD_SIZE(size){
    // dynamically init the board with '-' in each empty space
    for (int i = 0; i < BOARD_SIZE; i++){
        board[i] = new char [BOARD_SIZE];
        for (int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = '-';
        }
    }
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
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void GameBoard::placeMarker(Player &player, int row, int column){
    // update the board space for each player turn
    
    cout << "player[1] turn" << endl;
    board[row][column] = player.getPlayerMarker();
    this->updateBoard();

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