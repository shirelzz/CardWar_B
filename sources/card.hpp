#ifndef CARD_HPP
#define CARD_HPP

namespace ariel{}
#include <iostream>

class Card{

    private:

    int value;
    std::string shape;

    // Non-default Constructor


    public:

        Card(int val, std::string shp);

        void printCard();

        int getValue();

        std::string getShape();

        bool wins(Card &other);


        // void createCard(int number, std::string shp);

        // Default constructor
        // Card() = default;

        // // Copy constructor
        // Card(const Card& other) = default;

        // // Copy assignment operator
        // Card& operator=(const Card& other) = default;

        // // Move constructor
        // Card(Card&& other) noexcept = default;

        // // Move assignment operator
        // Card& operator=(Card&& other) noexcept = default;

        // Destructor. caused problems with tidy. will fix later
        // ~Card();



};
#endif