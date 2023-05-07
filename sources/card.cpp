#include "card.hpp"
#include "game.hpp"
#include "player.hpp"
#include <vector>
#include <iostream>

namespace ariel{}

using namespace std;


Card::Card(int val, std::string shp) : value(val), shape(shp){
    this->value = val;
    this->shape = shp;
}

void Card::printCard(){
    cout << this->value << endl;
    cout << this->shape << endl;

}

int Card::getValue(){
    return this->value;
}

std::string Card::getShape(){
    return this->shape;
}

// Game rules: 1 wins every card but 2
bool Card::wins(Card &other){

    if (other.getValue() == 1 && this->getValue() == 2){
        return true;
    }
    else if (other.getValue() == 2 && this->getValue() == 1){
        return false;
    }
    else if (other.getValue() != 2 && this->getValue() == 1){
        return true;
    }
    else if (other.getValue() == 1 && this->getValue() != 2){
        return false;
    }
    else if (other.getValue() > this->getValue()){
        return false;
    }
    else if (other.getValue() < this->getValue()){
        return true;
    }
    return false;
}