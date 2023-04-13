#ifndef GAME_HPP
#define GAME_HPP

#include<string>
#include<vector>
#include "player.hpp"
#include "card.hpp"
using namespace std;
namespace ariel{}
    class Game{
        public:
        Player& player1;
        Player& player2;
        string winner;
        vector<Card> cards;
        string lastRound;
        string logs;
        int round;
        int draw;
        Game();
        Game(Player& pl1,Player& pl2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printLog();
        void printStats();
        void printWiner();
        vector<Card> CreatCards();
        void Divide_Card();
        void Info(int check,Card &card1,Card &card2);


    };
#endif