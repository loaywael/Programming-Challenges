#include <iostream>
#include <string>
using namespace std;


class Player{

    private:
        const string PLAYER_NAME;
        const char PLAYER_MARKER;
        // bool playerTurn;
        bool playerResult;
        

    public:
        Player(string name, char marker);
        string getPlayerName();
        char getPlayerMarker();

};