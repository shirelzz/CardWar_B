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

Game::Game(Player &pl1, Player &pl2 ):
            player1(pl1), player2(pl2)
{
    
    if(pl1.getMode()){
        throw std::runtime_error("Player 1 is already playing");
    }
    if(pl2.getMode()){
        throw std::runtime_error("Player 2 is already playing");
    }
 
    
    pl1.changeMode();
    pl2.changeMode();

    deck = std::vector<Card>();
    log = "";
    lastTurn = "";

    createDeck();
    shuffleDeck();
    dealCards();
}


void Game::printWiner(){
    if (player1.cardesTaken() > player2.cardesTaken() )
    {
        cout << "The winner is: "<< player1.getName() << endl;
    }
    else if (player1.cardesTaken() < player2.cardesTaken() )
    {
        cout << "The winner is: " << player2.getName() << endl;
    }
    else{
        cout << "The game ended in tie." << endl;
    }
    
}

void Game::printLog(){
    cout << "------LOG------ \n" << log << endl;
    cout << "----END LOG---- \n" << endl;
}

void Game::printStats(){
    std::string stats = player1.getName() + ": Cards won: " + std::to_string(player1.cardesTaken()) + ". Stack size: " + std::to_string(player1.stacksize()) + "\n" +
                        player2.getName() + ": Cards won: " + std::to_string(player2.cardesTaken()) + ". Stack size: " + std::to_string(player2.stacksize());
    cout << "------STATS------ \n" << stats << endl;
    printWiner();
    cout << "----END STATS---- \n" << endl;
}

void Game::playTurn(){

    if (player1.equals(player2))
    {
        throw std::runtime_error("Player can't play against himself");
    }

    if (player1.stacksize() == 0 || player2.stacksize() == 0)
    {
        throw std::runtime_error("Empty stack");

    }

    Card pl1_card = player1.putCard();
    Card pl2_card = player2.putCard();

    lastTurn = player1.getName() + " played " + std::to_string(pl1_card.getValue()) + " of " + pl1_card.getShape() + ". " +
                player2.getName() + " played " + std::to_string(pl2_card.getValue()) + " of " + pl2_card.getShape() + ". ";

    if (pl1_card.wins(pl2_card))
    {
        player1.takeCard(pl2_card);
        player1.takeCard(pl1_card);
        lastTurn += player1.getName() + " wins. \n";
        log += lastTurn;
    }
    else if (pl2_card.wins(pl1_card))
    {
        player2.takeCard(pl1_card);
        player2.takeCard(pl2_card);
        lastTurn += player2.getName() + " wins. \n";
        log += lastTurn;

    }
    else{

        if (player1.stacksize() == 0 && player2.stacksize() == 0) // The cards now thrown were the last
        {
            // Each player takes ("wins") his card back
            player1.takeCard(pl1_card);
            player2.takeCard(pl2_card);

            lastTurn += "Last turn ended in tie. ";
            log += lastTurn;

            return;
        }

        // Create a new stack for the cards thrown in this specific war
        std::vector<Card> cardsThrown;
        // Add the first 2 cards that were thrown
        cardsThrown.push_back(pl1_card);
        cardsThrown.push_back(pl2_card);        

        int iter = 0;
        bool won = false;
        while (!won && player1.stacksize() > 0 && player2.stacksize() > 0)
        {
            if (player1.stacksize() == 1 && player2.stacksize() == 1)
            {
                Card lastCard1 = player1.putCard();
                Card lastCard2 = player2.putCard();
                player1.takeCard(lastCard1);
                player2.takeCard(lastCard2);

                if (iter == 0)
                {
                    player1.takeCard(pl1_card);
                    player2.takeCard(pl2_card);
                }

                lastTurn += "1 card left for each player. Last turn. ";
                log += lastTurn;
                break;
            }
            
            Card pl1_card_hid = player1.putCard();
            Card pl2_card_hid = player2.putCard();
            Card pl1_card_shw = player1.putCard();
            Card pl2_card_shw = player2.putCard();

            cardsThrown.push_back(pl1_card_shw);
            cardsThrown.push_back(pl2_card_shw);
            cardsThrown.push_back(pl1_card_hid);
            cardsThrown.push_back(pl2_card_hid);

            lastTurn += "Draw. \n" +  player1.getName() + " played " + std::to_string(pl1_card_shw.getValue()) + " of " + pl1_card_shw.getShape() + ". " +
                                    player2.getName() + " played " + std::to_string(pl2_card_shw.getValue()) + " of " + pl2_card_shw.getShape() + ". ";

            if (pl1_card_shw.wins(pl2_card_shw)) // Player1 won
            {
                won = true;
                lastTurn += player1.getName() + " wins. \n";
                log += lastTurn;

                // Player1 takes all cards thrown
                size_t count = cardsThrown.size();
                for (size_t i = 0; i < count; i++)
                {
                    player1.takeCard(cardsThrown[0]);
                    cardsThrown.erase(cardsThrown.begin());
                }
            }
            else if (pl2_card_shw.wins(pl1_card_shw)) // Player2 won
            {
                won = true;
                lastTurn +=  player2.getName() + " wins. \n";
                log += lastTurn;

                // Player2 takes all cards thrown
                size_t count = cardsThrown.size(); 
                for (size_t i = 0; i < count; i++)
                {
                    player2.takeCard(cardsThrown[0]);
                    cardsThrown.erase(cardsThrown.begin());
                }
            }
            iter++;
        } 
        if (cardsThrown.size() > 0 && (player1.cardesTaken() == player2.cardesTaken()) && iter > 0) // If the game ended in a tie during the war
                                                                                                   // (stacks are empty because we got out of the loop).
        {
            // Each player takes ("wins") his cards back
            size_t count = cardsThrown.size(); 
            for (size_t i = 0; i < count; i++)
            {
                if (i%2 == 0)
                {
                    player1.takeCard(cardsThrown[0]);
                }
                else{
                    player2.takeCard(cardsThrown[0]);
                }
                cardsThrown.erase(cardsThrown.begin());
            }
            lastTurn = " Each player takes his cards back (from cards thrown)";
            log += lastTurn;
        }       
    }
}

void Game::printLastTurn(){
    cout << lastTurn << endl;
}

void Game::playAll(){

    if (player1.stacksize() == 0 || player2.stacksize() == 0)
    {
        throw std::runtime_error("Empty stack");
    }

    while (true)
    {
        try
        {
            playTurn();
        }
        catch(const std::runtime_error &e)
        {
            std::cerr << e.what() << '\n';
            break;
        }
        
    }
    
}

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

    if (this->deck.size() < 52) {
        throw std::runtime_error("Not enough cards in the deck");
    }

    std::random_device rnd;
    std::mt19937 g(rnd());
    std::shuffle(deck.begin(), deck.end(), g);
}


void Game:: dealCards(){

    if (this->deck.size() < 52) {
        throw std::runtime_error("Not enough cards in the deck");
    }

    for (size_t i = 0; i < deck.size(); i++) {
        
        if (i % 2 == 0) {
            player1.addToStack(deck[i]);
        } else {
            player2.addToStack(deck[i]);
        }
    }
    
}
