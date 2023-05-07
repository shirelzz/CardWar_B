#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "card.hpp"
#include "player.hpp"
#include<iostream>

namespace ariel{}

class Game{

    private:
        
        Player &player1;
        Player &player2;

        std::vector<Card> deck;
        std::string log;
        std::string lastTurn;
        int draws;
        int turnsPlayed;

        void createDeck(); // creates a deck of cards for the game

        void shuffleDeck(); // shuffles the deck

        void dealCards(); // deal cards to the players


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