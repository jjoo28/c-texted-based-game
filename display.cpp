#define DEFINE_VARIABLES
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

#include "data_structure.h"
#include "globalv.h"
#include "display.h"
#include "start.h"
#include "general.h"
#include "backup.h"


using namespace std;


//declare functions
void calculation();
void display();
void display_calculation();
void check_status();
void ending(bool flag);

void calculation(){
      calc.love   = game_status.love;
      calc.health = game_status.health;
      calc.mask   = game_status.mask;
      calc.money  = game_status.money;
}

void status_menu(){
      system("clear");
      cout << "Your status" << endl;
      cout << "======================================================================================" << endl;
      cout.width(10); cout << left << "LOVE: ";     cout.width(3); cout << left <<  game_status.love << "     ";
      cout.width(10); cout << left << "HEALTH: ";   cout.width(3); cout << left << game_status.health << endl;
      cout.width(10); cout << left << "MASK: ";     cout.width(3); cout << left << game_status.mask << "     ";
      cout.width(10); cout << left << "MONEY($): "; cout.width(3); cout << left << game_status.money << endl;
      cout.width(10); cout << left << "WEEK: ";     cout.width(3); cout << left << game_status.week << endl;
      cout << "======================================================================================" << endl;
      cout<<'\n';
}

void zero_set(){
  if(game_status.love<=0){
    game_status.love=0;
  }
  if(game_status.health<=0){
    game_status.health=0;
  }
  if(game_status.mask<=0){
    game_status.mask=0;
  }
  if(game_status.money<=0){
    game_status.money=0;
  }
}

void display(){
      zero_set();
      status_menu();
      display_calculation();
      check_status();
      calculation();
}

void display_calculation(){
  bool flag=false;
  if((calc.love - game_status.love)!=0){
    if(calc.love-game_status.love>=0){
      cout<<"LOVE - "<<calc.love-game_status.love<<endl;
      flag=true;
    }
    else{
        cout<<"LOVE + "<<(calc.love-game_status.love)*-1<<endl;
        flag=true;
    }
  }
  if((calc.health - game_status.health)!=0){
    if(calc.health-game_status.health>=0){
      cout<<"HEALTH -"<<calc.health-game_status.health<<endl;
      flag=true;
    }
    else{
      cout<<"HEALTH +"<<(calc.health-game_status.health)*-1<<endl;
      flag=true;
    }

  }
  if(calc.mask- game_status.mask!=0){
    if(calc.mask-game_status.mask>=0){
      cout<<"MASK -"<<calc.mask-game_status.mask<<endl;
    }
    else{
        cout<<"MASK +"<<(calc.mask-game_status.mask)*-1<<endl;
    }
    flag=true;
  }
  if(calc.money-game_status.money!=0){
    if(calc.money-game_status.money>=0){
      cout<<"MONEY -$"<<calc.money-game_status.money<<endl;
    }
    else
      cout<<"MONEY +$"<<(calc.money-game_status.money)*-1<<endl;
    flag=true;
  }
  if(flag==true){
    cout<<"======================================================================================"<<endl;
    flag=false;
  }
  cout<<endl;
}

void check_status(){
  bool flag=false;
  if(game_status.health<=15){
    if(game_status.health<=0){
      cout<<"Your health point is 0"<<endl;
    }
    else{
      cout<<"Your health point is "<<game_status.health<<endl;
    }
    cout<<"You lose the game."<<endl;
    flag=true;
  }

  else if(game_status.love<=15){
    if(game_status.love<=0){
      cout<<"Your love point is 0"<<endl;
    }
    else{
        cout<<"Your love point is "<<game_status.love<<endl;
    }
    cout<<"Your lover ask you to break up. You lose the game."<<endl;
    flag=true;
  }

  else if(game_status.health>=100){
    game_status.health=100;
    cout<<"Your health point is full."<<endl;
  }
  else if (game_status.love>=100){
    game_status.love=100;
    cout<<"Your love point is full."<<endl;
  }

  ending(flag);
}

void ending(bool flag){
  if(flag==false && game_status.event==3){
    cout << "You reached to the ending!" << endl;
    cout << endl;
    cout << "Final score" << endl;
    cout << "============================================================================" << endl;
    cout.width(20); cout << left << "Love point : " << game_status.love << endl;
    cout.width(20); cout << left << "Health point : " << game_status.health << endl;
    cout.width(20); cout << left << "Number of mask(s) : " << game_status.mask << endl;
    cout.width(20); cout << left << "Money : " << game_status.money << endl;
    clearscr();
    int status;
    delete_file(backup_list[record], status);
    delete_winner();
    save_backup(backup_list);
    start();
  }
  else if(flag==true){
    clearscr();
    start();
  }
}
