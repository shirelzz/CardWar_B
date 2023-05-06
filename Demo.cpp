/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

#include <algorithm>
#include <random>

int main() {

  // Create two players with their names 
  Player p1("Alice");
  Player p2("Bob");
  Game game(p1,p2); 

  for (int i=0;i<5;i++) {
    game.playTurn();
  }
   
  game.printLastTurn(); // print the last turn stats. For example:
                                                    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                                    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
  cout << p1.stacksize() << endl; //prints the amount of cards left. should be 21 but can be less if a draw was played
  cout << p2.cardesTaken() << endl; // prints the amount of cards this player has won. 
  game.playAll(); //playes the game untill the end
  game.printWiner(); // prints the name of the winning player
  game.printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
  game.printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )


  //my demo
  cout << "-----------MY DEMO------------" << endl;
  cout << "\nNew game: Shirel & Avi" << endl;

  Player sh("Shirel");
  Player av("avi");
  Game ourGame(sh, av);

  cout << "Shirel's stack size at the beginning of the game: " << sh.stacksize() << endl;
  cout << "Avi's stack size at the beginning of the game: " << av.stacksize() << endl;
  cout << "Shirel's number of cards taken at the beginning of the game: " << sh.cardesTaken() << endl;
  cout << "Shirel's number of cards taken at the beginning of the game: " << av.cardesTaken() << endl;

  ourGame.playAll();
  ourGame.printLog();
  ourGame.printStats();

  cout << "Shirel's stack size at the end of the game: " << sh.stacksize() << endl;
  cout << "Avi's stack size at the end of the game: "<< av.stacksize() << endl;
  cout << "Shirel's number of cards taken at the end of the game: " << sh.cardesTaken() << endl;
  cout << "Avi's number of cards taken at the end of the game: "<< av.cardesTaken() << endl;

  cout << "\nNew game: Yacob & Hodaya" << endl;
  
  Player ya("Yacob");
  Player ho("Hodaya");

  cout << "Yacob's mode before the game: " << ya.getMode() << endl;
  cout << "Hodaya's mode before the game: " << ho.getMode() << endl;

  Game ourGame2(ya, ho);

  cout << "Yacob's mode at the beginning of the game: " << ya.getMode() << endl;
  cout << "Hodaya's mode at the beginning of the game: " << ho.getMode() << endl;

  ourGame2.playAll();
  ourGame2.printLog();
  ourGame2.printStats();

  cout << "Yacob's mode at the end of the game: " << ya.getMode() << endl;
  cout << "Hodaya's mode at the end of the game: "<< ho.getMode() << endl;

  cout << "\nNew game: Shirel & Hodaya" << endl;

  Game ourGame3(sh, ho);
  ourGame3.playAll();
  ourGame3.printLog();
  ourGame3.printStats();

  cout << "\nNew game: Avi & Avi" << endl;

  Game ourGame4(av, av);
  ourGame4.playAll();
  ourGame4.printLog();
  ourGame4.printStats();



}
