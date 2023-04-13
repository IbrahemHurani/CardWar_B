#include <string>
#include <stdexcept>
#include<iostream>
#include<random>
#include<algorithm>
#include "game.hpp"
using namespace std;
Game::Game(Player& pl1,Player& pl2):player1(pl1),player2(pl2){
    
    this->player1.setIsPlaying(true);//the player start the game 
    this->player2.setIsPlaying(true);
    this->draw=0;
    this->logs=" ";
    this->cards=this->CreatCards();
    this->Divide_Card();
    


}
void Game::playTurn(){
    if(this->player1.getName()==this->player2.getName()){
        throw("same Player");
    }
    if(this->player1.stacksize()==0||this->player2.stacksize()==0){
        throw("stack is zero");
    }
    if(this->player1.stacksize()>0 &&this->player1.IsPlaying()==true&&this->player2.stacksize()>0&&this->player2.IsPlaying()==true){
        this->round++;
        Card cardP1=this->player1.getDeckCard().back();
        this->player1.DeleteDeckCard();
        Card cardP2=this->player2.getDeckCard().back();
        this->player2.DeleteDeckCard();
        if(cardP1.getValue()==2&&cardP2.getValue()==14){//the Player2 have ace and Player1 have value card=2 player1 win add two card
            this->player1.setCardWon(1);
            this->player1.addCardwin(cardP1);
            this->player1.addCardwin(cardP2);
            this->Info(1,cardP1,cardP2);

            
        }
        if(cardP1.getValue()==14&&cardP2.getValue()==2){//the Player1 have ace and Player2 have value card=2 Player2 win
            this->player2.setCardWon(1);
            this->player2.addCardwin(cardP1);
            this->player2.addCardwin(cardP2);
            this->Info(2,cardP1,cardP2);
        }
        if(cardP1.getValue()>cardP2.getValue()){
            this->player1.setCardWon(1);
            this->player1.addCardwin(cardP1);
            this->player1.addCardwin(cardP2);
            this->Info(1,cardP1,cardP2);


        }
        if(cardP1.getValue()<cardP2.getValue()){
            this->player2.setCardWon(1);
            this->player2.addCardwin(cardP1);
            this->player2.addCardwin(cardP2);
            this->Info(2,cardP1,cardP2);


        } 
    
        else if(cardP1.getValue()==cardP2.getValue()){
            this->draw++;
            this->lastRound=" Name of Player1: "+this->player1.getName()+" have card: "+to_string(cardP1.getValue())+" of "+cardP1.getType()+" play with: "+this->player2.getName()+" have card: "+to_string(cardP2.getValue())+" of "+cardP2.getType()+" Draw agin!!\n";
            this->logs+=this->lastRound;
            vector<Card> temp;
            temp.push_back(cardP1);
            temp.push_back(cardP2);
            bool flag=false;
            while(!flag){
                Card c1open=this->player1.getDeckCard().back();
                this->player1.DeleteDeckCard();
                Card c1close=this->player1.getDeckCard().back();
                this->player1.DeleteDeckCard();

                Card c2open=this->player2.getDeckCard().back();
                this->player2.DeleteDeckCard();
                Card c2close=this->player2.getDeckCard().back();
                this->player2.DeleteDeckCard();

                if(this->player1.stacksize()>=2||this->player2.stacksize()>=2){
                    if(c1open.getValue()>c2open.getValue()){
                        this->player1.addCardwin(c1open);
                        this->player1.addCardwin(c1close);
                        this->player1.addCardwin(c2open);
                        this->player1.addCardwin(c2close);
                        for(Card c:temp){
                            this->player1.addCardwin(c);
                        }
                        this->Info(1,c1open,c2open);
                        flag=true;
                        break;
                    }
                    else if(c1open.getValue()<c2open.getValue()){
                        for(Card c:temp){
                            this->player1.addCardwin(c);
                        }
                        this->player2.addCardwin(c1open);
                        this->player2.addCardwin(c1close);
                        this->player2.addCardwin(c2open);
                        this->player2.addCardwin(c2close);
                        this->Info(2,c1open,c2open);

                        flag=true;
                        break;
                    }
                    else{
                        this->draw++;
                        this->lastRound=" Name of Player1: "+this->player1.getName()+" have card: "+to_string(cardP1.getValue())+" of "+cardP1.getType()+" play with: "+this->player2.getName()+" have card: "+to_string(cardP2.getValue())+" of "+cardP2.getType()+" Draw agin!!\n";
                        this->logs+=this->lastRound;
                        temp.push_back(c1open);
                        temp.push_back(c1close);
                        temp.push_back(c2open);
                        temp.push_back(c2close);



                        

                    }
                
                }
                else{
                    if(this->player1.stacksize()==0){
                        this->player1.addCardwin(cardP1);
                        this->player2.addCardwin(cardP2);
                        flag=true;
                        break;
                    }
                    else {
                        this->player1.addCardwin(cardP1);
                        this->player2.addCardwin(cardP2);
                        cardP1=this->player1.getDeckCard().back();
                        this->player1.DeleteDeckCard();
                        cardP2=this->player2.getDeckCard().back();
                        this->player2.DeleteDeckCard();

                        flag=true;
                        break;

                    }
                }

                
            }
            





           
            




            }


        

    }


}
void Game::Info(int check,Card &card1,Card &card2){
    if(check==1){
        this->lastRound=" Name of Player1: "+this->player1.getName()+" have card: "+to_string(card1.getValue())+" of "+card1.getType()+" play with: "+this->player2.getName()+" have card: "+to_string(card2.getValue())+" of "+card2.getType()+" The winner is: "+this->player1.getName()+"\n";
        this->logs+=this->lastRound;
    }else if(check==2){
        this->lastRound=" Name of Player1: "+this->player1.getName()+" have card: "+to_string(card1.getValue())+" of "+card1.getType()+" play with: "+this->player2.getName()+" have card: "+to_string(card2.getValue())+" of "+card2.getType()+" The winner is: "+this->player2.getName()+"\n";
        this->logs+=this->lastRound;
    }

}
void Game::printLastTurn(){
    cout<<this->lastRound<<endl;
}
void Game::playAll(){
    while(this->player1.stacksize()!=0|| this->player2.stacksize()!=0){
        this->playTurn();
    }
    

}
void Game::printLog(){
    cout<<this->logs<<endl;

}
void Game::printStats(){
    cout<<this->player1.getName()<<" the winRate:"<<this->player1.getWinRate()<<"%"<<" have card:"<<this->player1.cardesTaken()<<"\n"<<endl;
    cout<<this->player2.getName()<<" the winRate: "<<this->player2.getWinRate()<<"%"<<" have card:"<<this->player2.cardesTaken()<<"\n"<<endl;
    cout<<"Number of Draw: "<<this->draw<<endl;




   
}
void Game::printWiner(){
    if(this->player1.cardesTaken()>this->player2.cardesTaken()){
        cout<< this->player1.getName()+" the winner"<<endl;
         this->winner=player1.getName();
    }
    else if(this->player1.cardesTaken()<this->player2.cardesTaken()){
        cout<< this->player2.getName()+" the winner"<<endl;
        this->winner=player2.getName();
    }
    else{
        cout<<"No winner in this game ->Draw game"<<endl;

    }

    
}
vector<Card> Game::CreatCards(){
    string types[]={"spades","diamonds","hearts","clubs"};
    vector<Card> temp;
    for(int i=2;i<=14;i++){
        for(int j=0;j<4;j++){
            temp.push_back(Card(types[j],i));
        }
    }
    random_device r;
    mt19937 f(r());
    shuffle(temp.begin(),temp.end(),f);
    return temp;
}
void Game::Divide_Card(){
    for(size_t i=0;i<52;i++){
        if(i%2==0){
            this->player1.addCradinDeck(this->cards.at(i));
        }
        else{
            this->player2.addCradinDeck(this->cards.at(i));
        }
    }

}
