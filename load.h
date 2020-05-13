#ifndef LOAD_H
#define LOAD_H

#include "data_structure.h"

void load_difficulty();
void load_lover();
void load_backup();
int binary_search (int p[], int left, int right, int id);
void grow_player_profile (Person * &pp, int &pp_size);
void load_player_profile (Person * &pp, int &pp_size, int &np);
void backup_status (string fname, Backup &d);
string backup_date (string date);
string backup_time (string time);
void load_display_list();

void _load();

#endif
