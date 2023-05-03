#include "game.hpp"
#include "card.hpp"
#include "player.hpp"
namespace ariel{}

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <random>

using namespace std;
using std::vector;
using std::string;

Game::Game(Player pl1, Player pl2 ):
            player1(pl1), player2(pl2)
{
    // if(pl1.equals(pl2)){
    //     throw std::runtime_error("Player cannot play against himself");
    // }
    if(pl1.getMode()){
        throw std::runtime_error("Player 1 is already playing");
    }
    if(pl2.getMode()){
        throw std::runtime_error("Player 2 is already playing");
    }
 
    
    pl1.changeMode();
    pl2.changeMode();

    createDeck();
    // shuffleDeck();
    dealCards();
}

// Game::~Game(){}

void Game::printWiner(){}

void Game::printLog(){}

void Game::printStats(){}

void Game::playTurn(){

    if (player1.equals(player2))
    {
        throw std::runtime_error("Player can't play against himself");
    }
}

void Game::printLastTurn(){}

void Game::playAll(){}

vector<Card> Game::getDeck(){
    return this->deck;
}

void Game::createDeck(){
    
    for (int i = 1; i <= 13; i++)
    {
        deck.push_back(Card(i, "Clubs"));
        deck.push_back(Card(i, "Diamonds"));
        deck.push_back(Card(i, "Hearts"));
        deck.push_back(Card(i, "Spades"));
    }   
    
}

void Game::shuffleDeck(){

    int n = this->deck.size();

    for (int i = n-1 ; i>=0; i--){
        int rnd_idx = rand() % (i+1);
        Game::swap(i, rnd_idx);

    }
}


void Game:: dealCards(){
    if (this->deck.size() < 52) {
        throw std::runtime_error("Not enough cards in the deck");
    }

    // size_t i = 0;
    // while (i < 52)
    // {
    //     this->player1.cards.push_back(this->deck[i]);
    //     this->player2.cards.push_back(this->deck[i+1]);
    //     i += 2;
    // }

    this->player1.cards.clear();
    this->player2.cards.clear();

    for (size_t i = 0; i < 26; i++) {
        this->player1.cards.push_back(this->deck[i * 2]);
        this->player2.cards.push_back(this->deck[i * 2 + 1]);
    }
    
}


void Game:: swap(int idx, int rnd){
    Card temp = this->deck[static_cast<std::vector<Card>::size_type>(idx)];
    this->deck[static_cast<std::vector<Card>::size_type>(idx)] = this->deck[static_cast<std::vector<Card>::size_type>(rnd)];
    this->deck[static_cast<std::vector<Card>::size_type>(rnd)] = temp;
}