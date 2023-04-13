#ifndef PLAYER_HPP
#define PLAYER_HPP

namespace ariel{}
// using namespace std;
#include <vector>
#include "card.hpp"
#include <iostream>

class Player{

    private:

        const std::string name;
        std::vector<Card> cards;
        std::vector<Card> cards_thrown;
        std::vector<Card> cards_taken;
        bool isPlaying = false;


    public:

        // Non-default constructor
        Player(std::string name);

        // // Default constructor
        // Player() = default;

        // // Copy constructor
        // Player(const Player& other) = default;

        // // Copy assignment operator
        // Player& operator=(const Player& other) = default;

        // // Move constructor
        // Player(Player&& other) noexcept = default;

        // // Move assignment operator
        // Player& operator=(Player&& other) noexcept = default;

        // // Destructor.Caused problems with tidy. will fix later
        // ~Player();


        void changeMode(); //change isPlaying field

        bool getMode();

        int stacksize();

        int cardesTaken();

        Card putCard();

        void takeCard(Card card_taken);


};
#endif