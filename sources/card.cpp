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

    // void Card::createCard(int number, std::string shp){

    //     if (number <=13 && number>=1 && 
    //         (shp == "Clubs" || shp == "Diamonds" || shp == "Hearts" || shp == "Spades"))
    //     {
    //         new Card(number, shp);
    //     }
        
    // }

    // Card::Card(){}

    // Card::~Card(){}