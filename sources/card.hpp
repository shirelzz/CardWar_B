#ifndef CARD_HPP
#define CARD_HPP

namespace ariel{}
// using namespace std;
#include <iostream>

class Card{

    private:

    int num;
    std::string shape;

    // Non-default Constructor
    Card(int number, std::string shp);


    public:

        void createCard(int number, std::string shp);

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