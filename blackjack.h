#ifndef CIRCLE_H
#define CIRCLE_H
#include<vector>
#include<iostream>
#include<stdio.h>
#include <bits/stdc++.h> 
using namespace std;
enum Rank{
        ACE=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK=10,QUEEN=10,KING=10
    };
    enum Type{
        CLUBS,DIAMONDS,HEARTS,SPADES
    };
    class Card
{
    /* data */
    Rank rank;
    Type type;
public:
    Card(Rank ,Type);
    ~Card();
    int getValue();
    void displayCard();
};
void swap1 (Card& ,Card& );
class Hand
{
protected:
    vector<Card> holding;
    int AVe;
public:
    Hand(/* args */) ;
    ~Hand();
    void add(Card );
    void  clear();
    int getAce();
    int getTotal();
    Card getcard(int i);
};
class Deck:public Hand
    {   
    public:
        Deck(/* args */);
        ~Deck();
    void popuplate();
    void shuffle() ;
    void deal(Hand& );
}; 
class AbstractPlayer:public Hand
{
private:
    /* data */
public:
void  display();
    AbstractPlayer(/* args */) ;
    ~AbstractPlayer();
    bool isBusted();
  virtual bool isDrawing() = 0;
};
class ComputerPlayer:public AbstractPlayer
{
private:
    /* data */
public:
    ComputerPlayer(/* args */);
    ~ComputerPlayer();
        bool isDrawing();
     
};
class HumanPlayer:public AbstractPlayer
{
private:
    /* data */
public:
    HumanPlayer(/* args */);
    ~HumanPlayer() ;
    bool isDrawing();
     void announce(char a);
};
class BlackJackGame
{
private:
Deck m_deck;
ComputerPlayer m_casino;
public:
    BlackJackGame(/* args */);
    ~BlackJackGame();

    void play();
};


#endif