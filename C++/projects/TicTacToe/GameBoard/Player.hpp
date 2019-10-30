#include<iostream>
#include<string>
using namespace std;


class Player{

    private:
        const string PLAYER_NAME;
        const char PLAYER_MARKER;
        // bool playerTurn;
        bool playerResult;
        

    public:
        Player(string name, char marker);
        // void setPlayerName(string name);
        string getPlayerName();
        // void setPlayerMarker(char marker);
        char getPlayerMarker();
        // void setPlayerTurn(bool turn);
        // bool getPlayerTurn();
        void setPlayerResult(bool result);
        bool getPlayerResult();

};