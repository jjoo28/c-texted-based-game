#ifndef BACKUP_H
#define BACKUP_H

#include "data_structure.h"

void add_player_profile (Person pp[], int &np, Person gp);
void sort_player_profile (Person pp[], int np);
void save_player_profile (Person pp[], int np);
void backup_menu (Backup dl[]);
int confirm_backup (Backup dl[], int c);
void delete_file (string bl, int &stat);
void save_backup (string bl[]);
void get_date_time (string &d, string &t);
void set_log (Backup &log, Status gs, Person gp, Person gl);
void insert_log (Node * &head, Backup log);
string save_log(Node * head);
void _backup();
void delete_winner();
void pause_menu();
void _pause();


#endif
