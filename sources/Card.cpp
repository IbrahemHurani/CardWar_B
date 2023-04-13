#include <stdexcept>
#include<string>
#include "card.hpp"
using namespace std;

Card::Card(string type,int value):Type(type),Value(value){
  

}
string Card::getType(){
    return this->Type;

}
int Card::getValue(){
    return this->Value;
}
