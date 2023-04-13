#ifndef PLAYER_HPP
#define PLAYER_HPP
#include<string>
#include <stdexcept>
#include<vector>
#include "card.hpp"

using namespace std;
namespace ariel{}

    class Player
    {
        private:
            string player_name;
            bool is_playing;
            int card_win;
            vector<Card> cardP;
            vector<Card> CardWin;
            int winRate;
        public:
            Player(string P_name);
            string getName();
            void addCardwin(Card card);
            void setName(string new_name);
            int stacksize();
            int cardesTaken();
            bool IsPlaying();
            void setIsPlaying(bool Player_status);
            void setCardWon(int Cwin);
            vector<Card> getDeckCard();
            void DeleteDeckCard();
            void addCradinDeck(Card card);
            int getCardWin();
            int getWinRate();

            
    
    };
#endif