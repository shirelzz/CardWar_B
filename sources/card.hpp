#ifndef CARD_HPP
#define CARD_HPP

namespace ariel{}
#include <iostream>

class Card{

    private:

    int value;
    std::string shape;

    public:

        Card(int val, std::string shp);

        int getValue();

        std::string getShape();

        bool wins(Card &other); // returns true if this card wins the other card

        void printCard();  // For self check


};
#endif