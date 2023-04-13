#include "game.hpp"
#include "card.hpp"
#include "player.hpp"
namespace ariel{}

#include <vector>
#include <iostream>


Game::Game(Player pla1, Player pla2 ): player1(pla1), player2(pla2){}

// Game::~Game(){}

void Game::printWiner(){}

void Game::printLog(){}

void Game::printStats(){}

void Game::playTurn(){

}

void Game::printLastTurn(){}

void Game::playAll(){}

void Game::shuffleDeck(){
    
}

void Game::dealCards(std::vector<Card> deck_of_cards){
    int half = deck_of_cards.size() / 2;
    for (int i = 0; i < half; i++)
    {
        this->player1.takeCard(deck_of_cards[i]);
        this->player2.takeCard(deck_of_cards[i+1]);

    }
    
}


