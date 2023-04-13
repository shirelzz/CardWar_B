#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
namespace ariel{}

#include <vector>
#include <iostream>


Player::Player(std::string name): name(name) {}
// Player::Player(const Player& other) {}

// Player::~Player(){}

void Player::changeMode(){
   bool temp =  this->getMode();
   this->isPlaying = !temp;
} //change isPlaying field

bool Player::getMode(){
    return this->isPlaying;
    }

int Player::stacksize(){return this->cards.size();}

int Player::cardesTaken(){return this->cards_taken.size();}

Card Player::putCard(){
    Card card = cards[0];
    this->cards.erase(cards.begin());
    return card;
}

void Player::takeCard(Card card_taken){
    cards_taken.push_back(card_taken);
}

