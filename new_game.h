#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <iostream>
#include "data_structure.h"


void menu_difficulty();
void set_difficulty();
void load_new_playerQ (string q[]);
int confirm_info (Person p, string q[]);
void check_gender (Person &p, string q[]);
void check_age (Person &p, string q[]);
void set_player();
void set_lover ();
void welcome_message();
void _new_game();
#endif
