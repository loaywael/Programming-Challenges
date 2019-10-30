#include "Player.hpp"

Player::Player(string name, char marker):
PLAYER_NAME(name), PLAYER_MARKER(marker){
    // playerTurn = false;
    playerResult = false;
}

string Player::getPlayerName(){
    return PLAYER_NAME;
}

char Player::getPlayerMarker(){
    return PLAYER_MARKER;
}
