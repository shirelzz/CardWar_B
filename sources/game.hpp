#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "card.hpp"
#include "player.hpp"

namespace ariel{}
using namespace std;
#include<iostream>

class Game{

    private:

        Player player1;
        Player player2;

        void shuffleDeck();

        void dealCards(std::vector<Card> deck_of_cards);


    public:

        std::vector<Card> deck;


        // Non-default constructor
        Game(Player pla1, Player pla2 );

        // Default constructor
        // Game() = default;

        // Copy constructor
        // Game(const Game& other) = default;

        // Copy assignment operator
        // Game& operator=(const Game& other) = default;

        // Move constructor
        // Game(Game&& other) noexcept = default;

        // Move assignment operator
        // Game& operator=(Game&& other) noexcept = default;

        // Destructor
        //caused problems with tidy. will fix later
        // ~Game();

        void printWiner(); 

        void printLog();

        void printStats();

        void playTurn();

        void printLastTurn();

        void playAll();

};
#endif