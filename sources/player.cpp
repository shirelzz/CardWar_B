#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include <vector>
#include <iostream>

namespace ariel{}
using namespace std;



Player::Player(std::string name):
        name(name) , cards(), cards_thrown(), cards_taken()
{
    this->isPlaying = false;
}

// Player::Player(const Player& other) {}

// Player::~Player(){}

void Player::changeMode(){
   bool temp =  this->getMode();
   this->isPlaying = !temp;
} //change isPlaying field

bool Player::getMode(){
    return this->isPlaying;
    }

int Player::stacksize(){
    return static_cast<int>(this->cards.size());
}

int Player::cardesTaken(){return this->cards_taken.size();}

Card Player::putCard(){

    Card card = cards[0];
    this->cards.erase(cards.begin());
    return card;
}

void Player::takeCard(Card card_taken){

    cards_taken.push_back(card_taken);
}

bool Player::equals(Player player){

    if (this->name == player.name )
    {
        return true;
    }
    return false;
    
}

std::vector<Card> Player::getStack(){
    return this->cards;
}



