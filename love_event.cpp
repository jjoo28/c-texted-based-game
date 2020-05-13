#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "data_structure.h"
#include "globalv.h"
#include "general.h"
#include "display.h"
#include "game.h"
//#include "new_game.h"


using namespace std;
void love_1();
void love_1_2(int mask);
void love_1_3();
void love_2();
void love_2_2();
void love_2_3();
void love_3();
void love_3_2(char choice, char choice2);
void love_3_3(char present);
void valid_choice(char &choice);


void valid_choice(char &choice){
  while (choice !='1'&& choice !='2'){
    cout<<"Please input a valid option.\nEnter your choice (1/2) ~> "<<endl;
    cin>>choice;
  }
}

//love event -1
void love_1(){
  display();
  char choice;
  int mask;

  cout<<game_lover.name<<" calls you out for a date\n"<<endl;
  cout<<"What will you do?\n1.'Lets go out!'\n2.'Nah let's stay at home'\n"<<endl;
  cout<<"Enter your choice (1/2) ~> "<<endl;

  cin>>choice;
  valid_choice(choice);

  if(choice=='1'){
    if(game_status.mask-1>=0){
      game_status.love+=10;
      game_status.mask-=1;
      mask=1;
      display();
      love_1_2(mask);
    }
    else{
      game_status.love+=10;
      game_status.health-=10;
      display();
      mask=0;
      love_1_2(mask);
    }
  }

  else if (choice=='2'){
    game_status.love-=5;
    game_status.health+=10;
    game_status.week+=1;
    game_status.event+=1;
    menu_display();
  }
}

void love_1_2(int mask){
  char choice;
  cout<<"On your way to meet your lover, you met a strange person coughing on street"<<endl;
  cout<<"What will you do?\n1.Walk away from the person. \n2.I don't care\n"<<endl;
  cout<<"Enter your choice (1/2) ~> "<<endl;
  cin>>choice;
  valid_choice(choice);

  if(choice=='1'){
    love_1_3();
  }
  else if(choice=='2'){
    if(mask==1){
      game_status.health-=15;
      display();
      love_1_3();
    }
    else{
      game_status.health-=35;
      display();
      love_1_3();
    }

  }

}

void love_1_3(){
  game_status.love+=10;
  display();
  cout<<"You arrived at the place to meet "<<game_lover.name<<endl;
  cout<<"You were able to meet "<<game_lover.name<<", and have a nice date"<<endl;
  cout<<"Congratualtion!"<<endl;
  cout<<endl;
  game_status.event+=1;
  game_status.week+=1;
  clearscr ();
  menu_display();
}

//love event -2
void love_2_3(){
  char choice;
  display();
  cout<<game_lover.name<<" is suddenly depressed.\n'I don't know whether this crisis will end before my birthday :(' "<<endl;
  cout<<"How will you comfort her?"<<endl;
  cout<<"1. Don't worry, I will make you the best birthday ever. It's really going to be fun"<<endl;
  cout<<"2. Well... too bad....\n"<<endl;
  cout<<"Enter your choice (1/2) ~> "<<endl;

  cin>>choice;
  valid_choice(choice);

  if(choice=='1'){
    game_status.love+=5;
    game_status.event+=1;
    game_status.week+=1;
    display();
    cout<<game_lover.name<<" says 'oh that's so sweet...! Thanks"<<endl;
    clearscr ();
    menu_display();
  }
  else if (choice=='2'){
    game_status.love-=80;
    game_status.event+=1;
    game_status.week+=1;
    display();
    cout<<game_lover.name<<" says 'Wow... You've changed... I think we should break up"<<endl;
    clearscr ();

  }

}

void love_2_2(){
  display();
  char choice;

  cout<<game_lover.name<<" asks 'Do you love me? How much do you love me?'\n "<<endl;
  cout<<"How will you answer "<<game_lover.name<<"'s question?'"<<endl;
  cout<<"1. I love you so much, more than this entire universe"<<endl;
  cout<<"2. Of course, I love you. Don't doubt on my love\n"<<endl;
  cout<<"Enter your choice (1/2) ~> "<<endl;
  cin>>choice;
  valid_choice(choice);

  if(choice=='1'){
    game_status.love-=5;
    display();
    cout<<game_lover.name<<" says 'Hahahaha your answer is very cringy! But its not bad :)'"<<endl;
    clearscr ();
    love_2_3();

  }
  else if(choice =='2'){
    game_status.love-=15;
    display();
    cout<<game_lover.name<<" says 'hmm that makes me even more suspicious...'"<<endl;
    clearscr ();
    love_2_3();
  }

}

void love_2(){
  display();
  char choice;
  cout<<"BREAKING NEWS:The virus crisis is getting worse, thousands of people get infected everyday"<<endl;
  cout<<game_lover.name<<" calls you out to a crowded area\n"<<endl;
  cout<<"What will you do?\n 1. Go out to meet her\n 2. Have a facecall instead\n"<<endl;
  cout<<"Enter your choice (1/2) ~> "<<endl;

  cin>>choice;
  valid_choice(choice);


  if (choice=='1'){
    if((game_status.mask-1)>=0){
      game_status.mask-=1;
    }
    display();
    cout<<"You went out to see your lover.... risking your life"<<endl;
    clearscr();
    game_status.love+=5;
    game_status.health-=85;
    display();
  }

  else if (choice=='2'){
    game_status.health+=5;
    display();
    cout<<game_lover.name<<" agrees to have a facecall instead"<<endl;
    clearscr ();
    love_2_2();
  }
}


//love event -3
void love_3_3(char present){
  int y;
  display();
  char choicce;
  cout<<"You came to "<<game_lover.name<<"'s house"<<endl;
  cout<<"Will you give the present to "<<game_lover.name<<" ? "<<endl;
  cout<<"1.YES"<<endl;
  cout<<"2.Definitely YES\n"<<endl;
  cout<<"Enter your choice (1/2) ~> "<<endl;
  cin>>choicce;
  valid_choice(choicce);

  if(choicce =='1' || choicce=='2'){
    if(present=='1'){
      game_status.love+=30;
      display();
      game_status.week+=1;
      game_status.event+=1;
      cout<<game_lover.name<<" says 'wow it's really nice present! Thank you'"<<endl;
      clearscr ();

      display();
    }
    else{
      game_status.love-=30;
      display();
      game_status.week+=1;
      game_status.event+=1;
      y=random_generator(10,1);
      cout<<game_lover.name<<"says 'How can't you know that I'm alergic to flowers? We met for "<<y<<" years.''"<<endl;
      clearscr ();
      game_status.week+=1;
      display();

    }
  }
}

void love_3_2(char choice, char choice2){
  display();
  if (choice=='1'){
    cout<<"Your present(s) will arrive before "<<game_lover.name<<"'s birthday."<<endl;
    clearscr ();
    love_3_3(choice);
  }

  else if(choice=='2'){
    if(game_status.mask-1>=0){
      game_status.health-=5;
      game_status.mask-=1;
      display();
    }
    else{
      game_status.health-=35;
      display();
    }
    cout<<"you risk yourself to go out and buy a present...."<<endl;
    display();
    love_3_3(choice);
  }
}
void love_3(){
  display();
  char choice,choice2;
  cout<<"It's already "<<game_lover.name<<"'s B-day. You need to buy a present.\n What will you buy?"<<endl;

  cout<<"1. a necklace "<<endl;
  cout<<"2. bouquet"<<endl;
  cout<<"3. BOTH\n"<<endl;
  cout<<"Enter your choice (1/2/3) ~> "<<endl;
  cin>>choice;

  while(choice!='1' && choice!='2'&& choice!='3'){
    cout<<"Please input a valid option." <<endl;
    cout<<"Enter your choice (1/2/3) ~> "<<endl;
    cin>>choice;
  }

  if (choice=='1'|| choice=='2' || choice=='3'){
    display();
    cout<<"Will you either go out and buy the present or order the present(s) on online?\n"<<endl;
    cout<<"1. go out and buy the present"<<endl;
    cout<<"2. order present(s) on online\n"<<endl;
    cout<<"Enter your choice (1/2) ~> "<<endl;
    cin>>choice2;

    valid_choice(choice2);
  }
    love_3_2(choice,choice2);


}
