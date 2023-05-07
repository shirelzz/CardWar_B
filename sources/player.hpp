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
        std::vector<Card> cards;  // player's stack
        std::vector<Card> cards_taken; // player's winning cards
        bool isPlaying;

    public:

        Player(std::string name);

        void changeMode(); // change isPlaying field

        bool getMode(); // returns isPlaying field

        bool equals(Player &player); // checks if this player equals to another player

        int stacksize();  // returns the size of cards size

        int cardesTaken(); // returns the cards_taken size

        Card putCard();  // takes out a card from cards

        void takeCard(Card &card_taken);  // adds card to cards_taken

        std::vector<Card> getStack();  // returns this cards

        void addToStack(Card &card); // adds to this cards

        std::string getName(); // returns this player's name

        void resetWins(); // clears the cards taken list


};
#endif