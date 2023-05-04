#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "card.hpp"
#include "player.hpp"
#include<iostream>

namespace ariel{}

class Game{

    private:
        
        // friend class Player;         

        Player &player1;
        Player &player2;

        std::vector<Card> deck;
        std::string log;
        std::string lastTurn;

        void shuffleDeck();

        void createDeck();

        void dealCards();


    public:

        Game(Player &pl1, Player &pl2 );

        void printWiner(); 

        void printLog();

        void printStats();

        void playTurn();

        void printLastTurn();

        void playAll();

        std::vector<Card> getDeck();


};
#endif