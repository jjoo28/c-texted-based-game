#include "data_structure.h"
#include "globalv.h"
#include "general.h"
#include "game.h"
#include "start.h"
#include "load.h"
#include "backup.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <stdio.h>

using namespace std;

Node * head = NULL;
Backup log;
int confirm;


/////////////////////////////////player profile handling////////////////////////
//add_player_profile(): add a new player to the players' profile
//input: game_player
//output: player_profile[] with game_player inserted
void add_player_profile (Person pp[], int &np, Person gp){
      pp[np].id = gp.id;
      pp[np].name = gp.name;
      pp[np].age = gp.age;
      pp[np].gender = gp.gender;

      ++np;
}

//sort_player_profile(): sort the player according to their player id
//input: player_profile[]
//output: sorted player_profile[]
void sort_player_profile (Person pp[], int np){
    int i, j, idx;
    int min;
    for( i = 0; i < np - 1; i++){
          min = pp[i].id;
          idx = i;

          for(j = i + 1; j < np; j++){
                if (pp[j].id < min){
                      min = pp[j].id;
                      idx = j;
                }
          }

          if (idx != i){
                Person temp;
                temp = pp[i];
                pp[i] = pp[idx];
                pp[idx] = temp;
          }
    }
}

//save_player_profile(): write the players' profile to the textfile player_record.txt
//input: player_profile[]
//output: player_record.txt
void save_player_profile (Person pp[], int np){
    ofstream fout(player_record);
    if(!fout.is_open())
        exit(1);

    fout << np << endl;

    for (int i = 0; i < np; i++){
        fout << pp[i].id << " ";
        fout << pp[i].name << " ";
        fout << pp[i].age << " ";
        fout << pp[i].gender << endl;
    }

    fout.close();
}

/////////////////////////////////////backup///////////////////////////////////
//backup_menu(): display the available backup in a table with the backup date, time, name, week and lover's name
//input: display_list[]
//output: backup table
void backup_menu (Backup dl[]){
      cout << "Choose a slot to save." << endl;
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

//confirm_backup(): confirm the chosen slot to save the game progress
//input: 1|2|3
//output: the index to save the record to backup_list[]
int confirm_backup (Backup dl[], int c){
    string input;
    for(;;){
          system("clear");
          backup_menu(dl);
          cout << c << endl;
          if (dl[c-1].p.id != -1)
                cout << "Replace Record " << c << "? (Y/N) ~>";
          else
                cout << "Save in Slot " << c << "? (Y/N) ~>";

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
          }
    }
    return -1;
}

//delete_file(): delete the log file that is being re-written
//input: the chosen file name
//output: status indicating that the file is being deleted
void delete_file (string bl, int &stat){
    string name = bl + ".txt";
    char fname[23];

    for (int i = 0; i < 23; i++){
        fname[i] = name[i];
    }

    stat = remove(fname);
}

//save_backup(): write the backuplist[] to the textfile backup_record.txt
//input: backup_list[]
//output: backup_record.txt
void save_backup (string bl[]){
    ofstream fout(backup_record);
    if (!fout.is_open())
        exit(1);

    for(int i = 0; i < backup_max; i++){
          fout << i << " " << bl[i] << endl;
    }

    fout.close();
}

/////////////////////////////////////log////////////////////////////////////

//get_date_time(): obtain the current time and date based on the current system
//input: system time and date
//output: date and time in string and format of yyyymmdd hhmmss
void get_date_time (string &d, string &t){
      time_t now = time(0);

      tm *ltm = localtime(&now);

      string year, month, day, hour, minute, second;
      year = to_string(1900 + ltm->tm_year);
      month = to_string(1 + ltm->tm_mon);
      if(month.length() == 1)
          month = "0" + month;
      day = to_string(ltm->tm_mday);
      if(day.length() == 1)
          day = "0" + day;
      hour = to_string(ltm->tm_hour);
      if(hour.length() == 1)
          hour = "0" + hour;
      minute = to_string(ltm->tm_min);
      if(minute.length() == 1)
          minute = "0" + minute;
      second = to_string(ltm->tm_sec);
      if(second.length() == 1)
          second = "0" + second;

      d = year + month + day;
      t = hour + minute + second;
}


//set_log(): log the current game progress with time and date and game status
//input: date, time, game_status, game_player, game_lover
//output: log
void set_log (Backup &log, Status gs, Person gp, Person gl){
      get_date_time(log.date, log.time);
      log.p.id     = gp.id;
      log.l.id     = gl.id;
      log.s.love   = gs.love;
      log.s.health = gs.health;
      log.s.mask   = gs.mask;
      log.s.money  = gs.money;
      log.s.week   = gs.week;
      log.s.event  = gs.event;
}

//insert_log(): insert the log
//input: log
//output: linked list with new log data
void insert_log (Node * &head, Backup log){
      Node * p = new Node;
      p->record = log;
      p->next = head;
      head = p;
}


//save_log(): write the log data to the textfile named with the latest log date, time and player id
//input: head->log
//output: date_time_playerid.txt
string save_log(Node * head){
      string ofile = to_string(head->record.p.id) + head->record.date + head->record.time + ".txt";
      ofstream fout(ofile);
      if(!fout.is_open())
          exit(1);

      Node * current = head;
    	while (current != NULL)
    	{
    		fout << current->record.date << " ";
        fout << current->record.time << " ";
        fout << current->record.p.id << " ";
        fout << current->record.l.id << " ";
        fout << current->record.s.love << " ";
        fout << current->record.s.health << " ";
        fout << current->record.s.mask << " ";
        fout << current->record.s.money << " ";
        fout << current->record.s.week << " ";
        fout << current->record.s.event << endl;

    		current = current->next;
    	}

      fout.close();

      return ofile.substr(0,19);
}

//_backup(): the whole process of the bakup procedure
//input: player_profile, display_list, backup_list, head, log
//output: textfiles backup_record.txt, player_record.txt, date_time_playerid.txt
void _backup(){

    Person * player_profile = new Person[player_profile_size];
    load_player_profile (player_profile, player_profile_size, num_player);

    int * player_id = new int [num_player];
    for(int i = 0; i < num_player; i++){
        player_id[i] = player_profile[i].id;
    }


    if (binary_search (player_id, 0, num_player - 1, game_player.id) == -1){
        add_player_profile (player_profile, num_player, game_player);
        sort_player_profile (player_profile, num_player);
    }
    if (num_player > player_profile_size)
        grow_player_profile(player_profile, player_profile_size);

    save_player_profile(player_profile, num_player);

    int choice;

    do{
        do{
            backup_menu(display_list);
            choice = valid_choice(backup_max);
        }
        while (choice == -1);
        confirm = confirm_backup(display_list, choice);
    }
    while (confirm == -1);

    int status;
    delete_file(backup_list[confirm], status);
    if (status == 0)
        cout << "Record is replaced." << endl;

    string new_record;
    new_record = save_log(head);
    backup_list[confirm] = new_record;
    record = confirm;
    save_backup(backup_list);
    load_display_list();

    delete [] player_id;
    delete [] player_profile;
    cout << "Record saved." << endl;
    clearscr();

}

//delete_winner(): delete the saved record if the player wins
//input: record
//output: backup_list[record] = empty;
void delete_winner(){
      backup_list[record] = "empty";
}

//pause_menu(): Pausing menu
//input: nil
//output: pause menu
void pause_menu(){
      cout << "Pause..." << endl;
      cout << "============================================================================" << endl;
      cout << "1. Continue" << endl;
      cout << "2. Save" << endl;
      cout << "3. Quit without saving" << endl;
      cout << "============================================================================" << endl;
      cout << "Please enter your choice ~>";
}

//_pause(): perform logging and allow continue, backup or quit
void _pause(){
      //log the current status
      set_log (log, game_status, game_player, game_lover);
      insert_log(head, log);
      system("clear");
      int choice;
      do{
          pause_menu();
          choice = valid_choice(3);
      }
      while(choice == -1);

      switch (choice){
            case 1 : menu_display();
            break;
            case 2 : {system("clear");_backup(); menu_display();}
            break;
            case 3 : {system("clear"); start(); menu_display();}

      }
}
