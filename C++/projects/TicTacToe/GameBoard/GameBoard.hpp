#include "Player.hpp"
using namespace std;

class GameBoard{

    private:
        const int MAX_ROUNDS;   // 
        const int BOARD_SIZE;
        int rowIndex, colIndex;
        char **board;

    public:
        GameBoard(int size);
        ~GameBoard();
        int roundsCounter;
        int getMaxRounds();
        bool _placeMarker(Player &player, int row, int column);
        void takeTurns(Player &player);
        void updateBoard();
        bool checkRows(Player &player);
};
