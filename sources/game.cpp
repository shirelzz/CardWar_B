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

using std::vector;
using std::string;

Game::Game(Player pla1, Player pla2 ): player1(pla1), player2(pla2) {
    createDeck();
    shuffleDeck(this->deck);
    dealCards(this->deck);
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
    for (int i = 1; i < 13; i++)
    {
        deck.push_back(Card(i, "Clubs"));
        deck.push_back(Card(i, "Diamonds"));
        deck.push_back(Card(i, "Hearts"));
        deck.push_back(Card(i, "Spades"));
    }   
    
}

void Game::shuffleDeck(vector<Card> cards){

    int n = cards.size();

    for (int i = n-1 ; i>=0; i--){
        int rnd_idx = rand() % (i+1);
        swap(cards[i], cards[rnd_idx]);

    }

}


void Game::dealCards(vector<Card> cards){
    int mid = cards.size() / 2;
        this->player1.dealCards_pl(cards, 0 , mid);
        this->player2.dealCards_pl(cards, mid , cards.size());
}


