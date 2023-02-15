    #include<iostream>
    #include"blackjack.h"
    using namespace std;
    int main(){
    cout<<"\tWelcome to the Comp322  game!"<<endl<<endl;
BlackJackGame game;
bool playAgain=true;
char answer='y';
while(playAgain){
    game.play();
cout<<"Would you like another round? (y/n): ";
cin>>answer;
cout<<endl<<endl;
playAgain=(answer=='y'?true:false);
}
cout<<"Game over";
return 0;
}