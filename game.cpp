#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>


#include "data_structure.h"
#include "globalv.h"
#include "typing_game.h"
#include "general.h"
#include "display.h"
#include "love_event.h"
#include "new_game.h"
#include "game.h"
#include "backup.h"

using namespace std;




void option_menu(){
      cout << "1. Buy mask" << endl;
      cout << "2. Go to work" << endl;
      cout << "3. Love event" << endl;
      cout << "4. Pause Option" << endl;
      cout << "Choose options from 1-4 ~>";
}

void menu_display(){
      int choice;
      do{
          display();
          option_menu();
          choice = valid_choice(4);
      }
      while (choice == -1);

      switch (choice){
            case 1:{
                  if (game_status.money >= 50)
                      buy_mask();
                  else{
                      cout << "You won't have enough money to buy mask" << endl;
                      clearscr();
                      menu_display();
                  }
            }
            break;
            case 2:{
                  if (game_status.mask >= 1)
                      game_typing();
                  else{
                      cout<<"You have no mask to go out for work"<<endl;
                      clearscr ();
                      menu_display();
                  }
            }
            break;
            case 3:{
                  love_event(game_status.event);
            }
            break;
            case 4:{
                  _pause();
            }
      }

}

void game_typing(){
      int earned;
      game_status.mask -= 1;
      game_status.love -= 5;
      display();
      earned = typing2();
      game_status.money += earned;
      game_status.week += 1;
      menu_display();
}

void rsp_menu(){
  cout << "1.Rock" << endl;
  cout << "2.Scissors" << endl;
  cout << "3.Paper" << endl;
  cout << "Choose options from 1-3 ~>";
}

void buy_mask(){
  int user_choice, computer_choice, key;
  bool flag = false;
  game_status.love -= 5;

  do{
        display();
        cout<<"You are now at a pharamcy.\nYou have to play rock scissors paper with the pharmacist.\nIf you win, you get 2 masks.\nIf you lose, you get 1 mask\n"<<endl;
        cout << endl;
        rsp_menu();
        user_choice = valid_choice(3);
  }
  while(user_choice == -1);


  computer_choice=random_generator(3,1);
  while(flag!=true){
        if(computer_choice==user_choice){
          cout<<"It's a tie, try again!"<<endl;
          clearscr();
          rsp_menu();
          do{
                display();
                rsp_menu();
                user_choice = valid_choice(3);
          }
          while(user_choice == -1);
          computer_choice = random_generator(3,1);
        }
    else if((computer_choice == 1 && user_choice == 2) || (computer_choice == 2 && user_choice == 3)||(computer_choice == 3 && user_choice == 1)){
          game_status.mask += 1;
          game_status.money -= 50;
          display();
          cout << "The pharmacist won, you only recieve 1 mask" << endl;
          flag = true;
    }
    else if((user_choice == 1 && computer_choice == 2) || (user_choice == 2 && computer_choice == 3)||(user_choice == 3 && computer_choice == 1)){
          game_status.mask += 2;
          game_status.money -= 50;
          display();
          cout << "You won! you recieve 2 masks" << endl;
          flag = true;
    }
  }
  game_status.week += 1;
  clearscr ();
  menu_display();

}

void love_event(int x){
  if(x == 0){
    love_1();
  }
  else if (x == 1){
    love_2();
  }
  else if (x == 2){
    love_3();
  }
}



void menu(){
  calculation();
  menu_display();
}
