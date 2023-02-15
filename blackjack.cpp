#include<iostream>
#include<stdio.h>
#include<vector>
#include <bits/stdc++.h> 
#include "blackjack.h"
using namespace std;


   Card::Card(Rank ran,Type typ):rank(ran),type(typ){ 
    }
    Card::~Card() {}
     int Card:: getValue(){
        return rank;
    }
    void Card:: displayCard(){
        char p;
        if(type==0){
            p='C';
        }
        else if(type==1){
            p='D';
        }
        else if(type==2)
        {
             p='H';
        }
        else if(type==3){
            p='S';
        }
        {
       std::cout<<rank<<p<<"  ";
    }
    }
    //implementation of hand methods

    Hand::Hand(/* args */) {}
    Hand::~Hand() {}
    void Hand::add(Card a){
        holding.push_back(a);
    }
    void Hand:: clear(){
        holding.clear();
    }
    int Hand:: getAce(){
        int number=0;
        for(int i=0;i<=holding.size();i++){
            if(holding[i].getValue()==1){
                number=number+1;
            }
            return number;
        }
    }
    int Hand::getTotal(){
        if(holding.empty()==true){
            return 0;
        }
        int sum=0;
        for(unsigned int i =0;i<holding.size();i++){
            sum=sum+holding[i].getValue();
        }
        AVe=getAce();
        for (;AVe>=1&&sum<11;)
        {
            AVe=AVe-1;sum=sum+10;
        }

        return sum;
    }
    Card Hand::getcard(int i){
        return holding[i];
    }

//public help methods;
void swap1 (Card& a,Card& b)
{
   Card temp=a;
   a=b;
   b=temp;
}



       Deck:: Deck(/* args */) {}
        Deck::~Deck() {}
    void Deck::popuplate(){
        if(holding.empty()==false){
        holding.clear();
        }
        for(unsigned int i=1;i<11;i++){
            Card newcard=Card(Rank(i),Type(CLUBS));
            add(newcard);
        }
        for(unsigned int i=1;i<4;i++){
            Card newcard=Card(Rank(10),Type(CLUBS));
            add(newcard);
        }
        for(unsigned int i=1;i<11;i++){
            Card newcard=Card(Rank(i),Type(DIAMONDS));
            add(newcard);
        }
        for(unsigned int i=1;i<4;i++){
            Card newcard=Card(Rank(10),Type(DIAMONDS));
            add(newcard);
        }
         for(unsigned int i=1;i<11;i++){
            Card newcard= Card(Rank(i),Type(HEARTS));
            add(newcard);
        }
        for(unsigned int i=1;i<4;i++){
            Card newcard=Card(Rank(10),Type(HEARTS));
            add(newcard);
        }
         for(unsigned int i=1;i<11;i++){
            Card newcard=Card(Rank(i),Type(SPADES));
            add(newcard);
        }
        for(unsigned int i=1;i<4;i++){
            Card newcard= Card(Rank(10),Type(SPADES));
            add(newcard);
        }
    }
    void Deck::shuffle() 
{ 
    // Initialize seed randomly 
    srand(time(0)); 
  
    for (int i=0; i<holding.size() ;i++) 
    { 
        // Random for remaining positions. 
        int r = (rand() % (52 )); 
        swap1(holding[i],holding[r]);
    } 
}
void Deck::deal(Hand& hand){
    int r = (rand() % (holding.size())); 
    Card temp=holding[r];
    hand.add(temp);
    holding.erase(holding.begin()+r);

}

//implementation of AbstractPLayer Methods
void  AbstractPlayer::display(){
     for (int i=0; i<holding.size() ;i++) {
         holding[i].displayCard();
     }
     cout<<"["<<getTotal()<<"]";
     cout<<endl;
}
    AbstractPlayer::AbstractPlayer(/* args */) {}
    AbstractPlayer::~AbstractPlayer() {}
    bool AbstractPlayer::isBusted(){
        if(getTotal()>21){
            return true;
        }else
        {
            return false;
        }
  }

//implementation of  computerPLayer methods
    ComputerPlayer::ComputerPlayer(/* args */) {}
    ComputerPlayer::~ComputerPlayer() {}
        bool ComputerPlayer::isDrawing(){
     int val=getTotal();
     if(val<=16){
         return true;
     }
     else
     {
         return false;
     }
}

//implementation of humanPLayer methods
   HumanPlayer:: HumanPlayer(/* args */) {}
     HumanPlayer:: ~HumanPlayer() {}
    bool    HumanPlayer:: isDrawing(){
    cout<<"Do you want to draw? (y/n):"<<endl;
    char p;
    cin>>p;
    if(p=='y'){
        return true;
    }
    else
    {
        return false;
    }
     }
     void    HumanPlayer:: announce(char a){
         switch (a)
         {
         case 'p':
         cout<<"The player loses."<<endl;
             break;
         case 'c':
         cout<<"The computer loses."<<endl;
             break;
         case 'o':
          cout<<"Push:No one wins";
         }
     }

      BlackJackGame::BlackJackGame(/* args */) {}
     BlackJackGame::~BlackJackGame() {}

    void  BlackJackGame::play(){
      char who;
        HumanPlayer player;
        m_deck.popuplate();
        m_deck.shuffle();
        m_deck.deal(player);
        m_deck.deal(player);
        m_deck.deal(m_casino);
        cout<<"Casino";
        m_casino.display();
        int casino= m_casino.getTotal();
        cout<<casino<<endl;
        cout<<"Player";
        player.display();
        int total=player.getTotal();
        cout<<total;
        bool Playerdraw=player.isDrawing();
        while(Playerdraw==true){
            m_deck.deal(player);
            player.display();
            if(player.isBusted()==true){
                who='p';
                break;
            }
            Playerdraw=player.isDrawing();
        }
        if(player.isBusted()==true){
            cout<<"Casino:";
                m_casino.display();
                cout<<"Player";
                player.display();
            player.announce(who);
        }else
        {
            bool Computerdraw=m_casino.isDrawing();
            while(Computerdraw==true){
                m_deck.deal(m_casino);
                Computerdraw=m_casino.isDrawing();
            }
            if(m_casino.isBusted()==true){
                who='c';
                cout<<"Casino:";
                m_casino.display();
                cout<<"Player";
                player.display();
                player.announce(who);
            }else{
                int x=m_casino.getTotal();
                int y=player.getTotal();
                if(x==y){
                    who='o';
                }
                else if(x>y)
                {
                    who='p';
                }else
                {
                    who='c';
                }
                cout<<"Casino:";
                m_casino.display();
                cout<<"Player";
                player.display();
                player.announce(who);
            }
         }
    }
