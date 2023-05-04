#ifndef PLAYER_HPP
#define PLAYER_HPP

namespace ariel{}
#include <vector>
#include "card.hpp"
#include <iostream>

class Player{

    private:

        // friend class Game;        

        std::string name;
        std::vector<Card> cards;
        std::vector<Card> cards_thrown;
        std::vector<Card> cards_taken;
        bool isPlaying;

    public:

        
        Player(std::string name);

        void changeMode(); //change isPlaying field

        bool getMode();

        bool equals(Player &player);

        int stacksize();

        int cardesTaken();

        Card& putCard();

        void takeCard(Card &card_taken);

        std::vector<Card> getStack();

        void addToStack(Card &card);

        std::string getName();


};
#endif