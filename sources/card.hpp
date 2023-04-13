#ifndef CARD_HPP
#define CARD_HPP
#include<string>
using namespace std;
    class Card{
        private:
            string Type;
            int Value;
        public:
            Card(string type ,int value);
            string getType();
            int getValue();

    };
#endif