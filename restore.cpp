#include "data_structure.h"
#include "globalv.h"
#include "general.h"
#include "restore.h"
#include "load.h"
#include "start.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

/////////////////////////////////////////////////////////////////////

bool check_empty (string bl[]){
    for (int i = 0; i < backup_max; i++){
          if (bl[i] != "empty")
              return false;
    }
    return true;
}

/////////////////////////////////////////////////////////////////////

void restore_menu (Backup dl[]){
      cout << "Choose a record to continue." << endl;
      cout << "============================================================================" << endl;
      cout << "   ";
      cout.width(15); cout << left << "Date";
      cout.width(15); cout << left << "|Time";
      cout.width(15); cout << left << "|Name";
      cout.width(7); cout << left  << "|Week";
      cout.width(15); cout << left  << "|Lover's Name" << endl;
      for (int i = 0; i < backup_max; i ++){
            cout << i+1 << ". ";
            if (dl[i].p.id == -1)
                cout << "empty" << endl;
            else{
                cout.width(15); cout << left << dl[i].date;
                cout.width(15); cout << left << "|" + dl[i].time;
                cout.width(15); cout << left << "|" + dl[i].p.name;
                cout << "|"; cout.width(6); cout << left << dl[i].s.week;
                cout.width(15); cout << left << "|" + dl[i].l.name << endl;
            }
      }
      cout << "============================================================================" << endl;
      cout << "Please enter your choice ~>";
}

int confirm_restore (Backup dl[], int c){
    system ("clear");
    string input;
    for(;;){
          cout << "Details of Record " << c << endl;
          cout << "============================================================================" << endl;
          cout << "Player information" << endl;
          cout.width(15); cout << left << "Name: " << dl[c-1].p.name << endl;
          cout.width(15); cout << left << "Age: " << dl[c-1].p.age << endl;
          cout.width(15); cout << left << "Gender: ";
          switch (dl[c-1].p.gender) {
                case ('M'):   cout << "Male" << endl;
                break;
                case ('F'):   cout << "Female" << endl;
                break;
                case ('U'):   cout << "Unknown" << endl;
                break;
          }
          cout << endl;
          cout << "Game progress" << endl;
          cout.width(15); cout << left << "Love points: " << dl[c-1].s.love << endl;
          cout.width(15); cout << left << "Health points: " << dl[c-1].s.health << endl;
          cout.width(15); cout << left << "No. of masks: " << dl[c-1].s.mask << endl;
          cout.width(15); cout << left << "Money: $" << dl[c-1].s.money << endl;
          cout.width(15); cout << left << "Week: " << dl[c-1].s.week << endl;
          cout << endl;
          cout << "Lover information" << endl;
          cout.width(15); cout << left << "Name: " << dl[c-1].l.name << endl;
          cout.width(15); cout << left << "Age: " << dl[c-1].l.age << endl;
          cout.width(15); cout << left << "Gender: ";
          switch (dl[c-1].l.gender) {
                case ('M'):   cout << "Male" << endl;
                break;
                case ('F'):   cout << "Female" << endl;
                break;
                case ('U'):   cout << "Unknown" << endl;
                break;
          }
          cout << "============================================================================" << endl;
          cout << "Continue with Record " << c << "? (Y/N) ~>";

          cin >> input;
          char confirm = input[0];
          confirm = toupper(confirm);
          switch (confirm){
                case 'Y' :
                    system("clear");
                    return c-1;
                break;
                case 'N' :{
                    system("clear");
                    return -1;
                }
                break;
                default:{
                    cout << "Oops! Please input again." << endl;
                    clearscr();
                }
          }
    }
    return -1;
}

void restore(Backup d){
      game_player.id      = d.p.id;
      game_player.name    = d.p.name;
      game_player.age     = d.p.age;
      game_player.gender  = d.p.gender;
      game_lover.id       = d.l.id;
      game_lover.name     = d.l.name;
      game_lover.age      = d.l.age;
      game_lover.gender   = d.l.gender;
      game_status.love    = d.s.love;
      game_status.health  = d.s.health;
      game_status.mask    = d.s.mask;
      game_status.money   = d.s.money;
      game_status.week    = d.s.week;
      game_status.event   = d.s.event;
}

/////////////////////////////////////////////////////////////////////
void _restore(){
      record = -1;
      if (check_empty(backup_list)){
          cout << "No record found." << endl;
          clearscr();
          start();
      }
      else{
          int choice, confirm;
          do{
                do{
                    restore_menu(display_list);
                    choice = valid_choice(backup_max);
                    if(display_list[choice - 1].p.id == -1){
                        cout << "Record is empty. Please choose another record." << endl;
                        clearscr();
                    }
                }
                while (choice == -1 || display_list[choice - 1].p.id == -1);
                confirm = confirm_restore(display_list, choice);
          }
          while(confirm == -1);

          restore(display_list[confirm]);
          record = confirm;
      }
}
