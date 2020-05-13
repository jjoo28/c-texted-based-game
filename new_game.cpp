#include"data_structure.h"
#include "globalv.h"
#include "general.h"
#include "new_game.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;


void menu_difficulty(){
    cout << "Select the difficulty." << endl;
    cout << "============================================================================" << endl;
    cout << "        | 1. Easy       | 2. Difficult" << endl;
    cout << "Health: |    70 points  |    50 points" << endl;
    cout << "Love:   |    50 points  |    50 points" << endl;
    cout << "Mask:   |    2          |    0" << endl;
    cout << "Money:  |    $100       |    $100" << endl;
    cout << "============================================================================" << endl;
    cout << "Enter your choice (1/2) ~> ";
}

void set_difficulty(){
    int choice;
    do{
        menu_difficulty();
        choice = valid_choice(2);
    }
    while (choice == -1);
    switch (choice) {
          case 1: {
              game_status = easy;
              cout << "You've chosen the easy level! Let's set up your information." << endl;
              clearscr();
          }
          break;
          case 2: {
              game_status = diff;
              cout << "You've chosen the difficult level! Let's set up your information." << endl;
              clearscr();
          }
          break;
    }
}

void load_new_playerQ (string q[]){
    q[0] = "Player Information";
    q[1] = "What is your name? ~>";
    q[2] = "How old are you? ~>";
    q[3] = "What is your gender?(M/F/U) ~>";
    q[4] = ", confirm your information? (Y/N) ~>";
}

int confirm_info (Person p, string q[]){
    string input;
    char cconfirm;
    for (;;){
        switch (p.gender){
              case 'M' :
                  cout << "Mr. ";
              break;
              case 'F' :
                  cout << "Miss. ";
              break;
              case 'U' :
                  cout << "Dear ";
              break;
          }
          cout << p.name << q[4];
          cin >> input;
          cconfirm = input[0];
          cconfirm = toupper(cconfirm);
            switch (cconfirm){
                case 'Y' :
                    return 1;
                break;
                case 'N' :
                    return 0;
                break;
                default: {
                    cout << "Oops! Please input again." << endl;
                    clearscr();
                    cout << q[0] << endl;
                    cout << "============================================================================" << endl;
                    cout << q[1] << p.name << endl;
                    cout << q[2] << p.age << endl;
                    cout << q[3] << p.gender << endl;
                    cout << endl;
                }
            }
        }
    return 0;
}

void check_gender (Person &p, string q[]){
    string input;
        cin >> input;
        p.gender = input[0];
        p.gender = toupper(p.gender);
        if (p.gender != 'M' && p.gender != 'F' && p.gender != 'U'){
            cout << "Please input again!" << endl;
            clearscr();
            cout << q[0] << endl;
            cout << "============================================================================" << endl;
            cout << q[1] << p.name << endl;
            cout << q[2] << p.age << endl;
            cout << q[3];
            check_gender(p,q);
        }
}

void check_age (Person &p, string q[]){
      string input;
      bool flag = false;
      while (flag == false){
          cin >> input;
          flag = true;
          for (int i = 0; i < input.length(); i++){
              if (!isdigit(input[i])){
                    cout << "Please input integer!" << endl;
                    clearscr();
                    cout << q[0] << endl;
                    cout << "============================================================================" << endl;
                    cout << q[1] << p.name << endl;
                    cout << q[2];
                    flag = false;
                    break;
              }
          }
      }
      p.age = stoi(input);
}

void set_player (){
    game_player.id = random_generator(10000, 10000);

    int confirm = 0;
    string new_playerQ[5];

    load_new_playerQ(new_playerQ);

    while (confirm == 0){
        cout << new_playerQ[0] << endl;
        cout << "============================================================================" << endl;
        cout << new_playerQ[1];
        getline(cin, game_player.name);
        cout << new_playerQ[2];
        check_age(game_player, new_playerQ);
        cout << new_playerQ[3];
        check_gender(game_player, new_playerQ);
        cout << endl;
        confirm = confirm_info(game_player, new_playerQ);
        if (confirm == 0){
            cout << "Let's input your information again!" << endl;
            clearscr();
        }
    }
    system("clear");
}

void set_lover (){
    int generated_lover = random_generator(lover_max, 0);
    game_lover.id = lover_profile[generated_lover].id;
    game_lover.name = lover_profile[generated_lover].name;
    game_lover.age = lover_profile[generated_lover].age;
    game_lover.gender = lover_profile[generated_lover].gender;
}

void welcome_message(){
    cout << "Welcome, " << game_player.name << "!" << endl;
    cout << "It is now the time of the coronavirus pandemic." << endl;
    cout << "You are now in your house and you are in an ambiguous relationship with " << game_lover.name << "." << endl;
    cout << "Try your best to deepen your love relationship with " << game_lover.name << " but also survive from the pandemic!" << endl;
    cout << "\nLover's Information" << endl;
    cout << "============================================================================" << endl;
    cout << "Name: " << game_lover.name << endl;
    cout << "Age: " << game_lover.age << endl;
    cout << "Gender: ";
    switch (game_lover.gender) {
          case ('M'):   cout << "Male" << endl;
          break;
          case ('F'):   cout << "Female" << endl;
          break;
          case ('U'):   cout << "Unknown" << endl;
          break;
    }
    cout << "============================================================================\n" << endl;
    clearscr();
}

void _new_game(){
    set_difficulty();
    set_player();
    set_lover();
    welcome_message();
}
