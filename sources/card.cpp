#include "card.hpp"
#include "game.hpp"
#include "player.hpp"
namespace ariel{}

#include <vector>
#include <iostream>



    Card::Card(int number, std::string shp) : num(number), shape(shp){}

    // void Card::createCard(int number, std::string shp){

    //     if (number <=13 && number>=1 && 
    //         (shp == "Clubs" || shp == "Diamonds" || shp == "Hearts" || shp == "Spades"))
    //     {
    //         new Card(number, shp);
    //     }
        
    // }

    // Card::Card(){}

    // Card::~Card(){}