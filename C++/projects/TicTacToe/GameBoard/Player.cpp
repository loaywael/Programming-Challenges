#include "Player.hpp"

Player::Player(string name, char marker):
PLAYER_NAME(name), PLAYER_MARKER(marker){
    // playerTurn = false;
    playerResult = false;
}

// void Player::setPlayerTurn(bool turn){
//     playerTurn = turn;
// }


void Player::setPlayerResult(bool result){
    playerResult = result;
}

string Player::getPlayerName(){
    return PLAYER_NAME;
}

char Player::getPlayerMarker(){
    return PLAYER_MARKER;
}

// bool Player::getPlayerTurn(){
//     return playerTurn;
// }

bool Player::getPlayerResult(){
    return playerResult;
}