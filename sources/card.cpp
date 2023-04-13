#include "card.hpp"
#include "game.hpp"
#include "player.hpp"
namespace ariel{}

#include <vector>
#include <iostream>



    Card::Card(int number, std::string shp) : num(number), shape(shp){}

    void Card::createCard(int number, std::string shp){

        if (number <=13 && number>=1 && (shp == "clubs" || shp == "diamonds" || shp == "hearts" || shp == "spades"))
        {
            new Card(number, shp);
        }
        
    }

    // Card::Card(){}

    // Card::~Card(){}