#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include <vector>
#include <iostream>

namespace ariel{}
using namespace std;



Player::Player(std::string name): name(name)
{
    this->name = name;
    this->isPlaying = false;
}

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

int Player::cardesTaken(){
    return this->cards_taken.size();
}

Card& Player::putCard(){

    Card &card = cards[0];
    this->cards.erase(cards.begin());
    return card;
}

void Player::takeCard(Card &card_taken){

    cards_taken.push_back(card_taken);
}

bool Player::equals(Player &player){

    if (this->name == player.name )
    {
        return true;
    }
    return false;
    
}

std::vector<Card> Player::getStack(){
    return this->cards;
}

void Player::addToStack(Card &card){
    this->cards.push_back(card);
}

std::string Player::getName()
{
    return name;
}



