#include<iostream>
#include<string>
#include "Player.hpp"
using namespace std;

class GameBoard{

    private:
        // string playerTurn;
        const int BOARD_SIZE;
        char **board = new char *[BOARD_SIZE];

    public:
        GameBoard(int size);
        ~GameBoard();
        bool placeMarker(Player &player, int row, int column);
        void updateBoard();
        int checkResult(Player &player);
};