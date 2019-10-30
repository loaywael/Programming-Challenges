#include<iostream>
#include<string>
#include "Player.hpp"
using namespace std;

class GameBoard{

    private:
        // string playerTurn;
        const int MAX_ROUNDS;
        const int BOARD_SIZE;
        int rowIndex, colIndex;
        char **board = new char *[BOARD_SIZE];

    public:
        
        GameBoard(int size);
        ~GameBoard();
        int roundsCounter;
        int getMaxRounds();
        bool _placeMarker(Player &player, int row, int column);
        void takeTurns(Player &player);
        void updateBoard();
        int checkResult(Player &player);
};