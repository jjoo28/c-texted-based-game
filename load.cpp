#include "data_structure.h"
#include "globalv.h"

#include <fstream>
#include <string>

void load_difficulty (){
    ifstream fin(preset);
    if(!fin.is_open())
        exit(1);

    while (!fin.eof()){
        char x;
        fin >> x;
        if (x == 'e')
            fin >> easy.love >> easy.health >> easy.mask >> easy.money >> easy.week >> easy.event;
        else
            fin >> diff.love >> diff.health >> diff.mask >> diff.money >> diff.week >> diff.event;
    }
    fin.close();
}

void load_lover (){
    ifstream fin(lover_record);
    if (!fin.is_open()){
        exit(1);
      }

    for(int i = 0; i < lover_max; i++)
        fin >> lover_profile[i].id >> lover_profile[i].name >> lover_profile[i].age >> lover_profile[i].gender;

    fin.close();

    for (int i = 0; i < lover_max; i++){
        lover_id[i] = lover_profile[i].id;
    }
}

void load_backup (){
      ifstream fin(backup_record);
      if (!fin.is_open())
          exit(1);

      int idx;
      while(!fin.eof()){
          fin >> idx;
          fin >> backup_list[idx];
      }

      fin.close();
}

int binary_search (int p[], int left, int right, int id){
      if (left > right){
          return -1;
      }

      int middle = left + ((right - left) / 2);
      if (p[middle] == id){
            return middle;
      }
      else if (id < p[middle]) {
            return binary_search(p, left, middle - 1, id);
      }
      return binary_search(p, middle + 1, right, id);
}

void grow_player_profile (Person * &pp, int &pp_size){
      Person * pp_new = new Person[pp_size + 3];
      for (int i = 0; i < pp_size; i++)
          pp_new[i] = pp[i];

      delete [] pp;

      pp = pp_new;
      pp_size += 3;

}

void load_player_profile (Person * &pp, int &pp_size, int &np){
      ifstream fin(player_record);
      if(!fin.is_open())
          exit(1);

      fin >> np;

      int i = 0;
      while(!fin.eof()){
            fin >> pp[i].id >> pp[i].name >> pp[i].age >> pp[i].gender;
            i++;
            if (i > pp_size - 1)
                grow_player_profile (pp, pp_size);
      }

      fin.close();
}

void backup_status (string fname, Backup &d){
    fname = fname + ".txt";
    ifstream fin(fname);
    if (fin.is_open())
      fin >> d.date >> d.time >> d.p.id >> d.l.id >> d.s.love >> d.s.health >> d.s.mask >> d.s.money >> d.s.week >> d.s.event;
    fin.close();
}

string backup_date (string date){
    return date.substr(0,4) + "/" + date.substr(4,2) + "/" + date.substr(6,2);
}

string backup_time (string time){
    return time.substr(0,2) + ":" + time.substr(2,2) + ":" + time.substr(4,2);
}

void load_display_list(){
      player_profile_size = 3;
      Person * player_profile = new Person[player_profile_size];
      num_player = 0;
      load_player_profile (player_profile, player_profile_size, num_player);

      int * player_id = new int [num_player];
      for(int i = 0; i < num_player; i++){
          player_id[i] = player_profile[i].id;
      }

      //Backup display_list[backup_max];
      for (int i = 0; i < backup_max; i++){

          if (backup_list[i] != "empty"){
              backup_status(backup_list[i], display_list[i]);
          }
          else
              display_list[i].p.id = -1;

          int id = display_list[i].p.id;
          int lid = display_list[i].l.id;
          if (id != -1){
              display_list[i].date = backup_date(display_list[i].date);
              display_list[i].time = backup_time(display_list[i].time);
              display_list[i].p.name = player_profile[binary_search(player_id, 0, num_player - 1, id)].name;
              display_list[i].p.age = player_profile[binary_search(player_id, 0, num_player - 1, id)].age;
              display_list[i].p.gender = player_profile[binary_search(player_id, 0, num_player - 1, id)].gender;
              display_list[i].l.name = lover_profile[binary_search(lover_id, 0, lover_max - 1, lid)].name;
              display_list[i].l.age = lover_profile[binary_search(lover_id, 0, lover_max - 1, lid)].age;
              display_list[i].l.gender = lover_profile[binary_search(lover_id, 0, lover_max - 1, lid)].gender;
          }
      }
      delete[] player_profile;
      delete[] player_id;
}

void _load(){
    load_difficulty();
    load_lover();
    load_backup();
    load_display_list();
}
