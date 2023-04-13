#include <string>
#include <stdexcept>
#include<cmath>
#include "player.hpp"
using namespace std;
Player::Player(string name_player){
	this->player_name=name_player;
	this->card_win=0;
	this->cardP={};
	this->winRate=0;

}
string Player::getName(){
    return this->player_name;

}
void Player::setName(string new_name){
	this->player_name=new_name;

}
void Player::setCardWon(int Cwin){
	this->card_win+=Cwin;
	

}

int Player::cardesTaken(){
	return this->CardWin.size();
}
int Player::stacksize(){
	return this->cardP.size();

}
bool Player::IsPlaying(){
	return this->is_playing;

}
void Player::setIsPlaying(bool Player_status){
	this->is_playing=Player_status;


}
void Player::addCardwin(Card card){
	this->CardWin.push_back(card);
}
vector<Card> Player::getDeckCard(){
	return this->cardP;
}
void Player::addCradinDeck(Card card){
	this->cardP.push_back(card);
}
void Player::DeleteDeckCard(){
	this->cardP.pop_back();
}
int Player::getWinRate(){
	this->winRate=round(((float(this->cardesTaken())/52)*100));
	return this->winRate;
}


