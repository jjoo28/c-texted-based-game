#ifndef GLOBALV_H
#define GLOBALV_H
#ifdef DEFINE_VARIABLES
#define EXTERN
#else
#define EXTERN extern
#endif

#include "data_structure.h"

const string preset = "preset.txt";
const string player_record = "player_record.txt";
const string backup_record = "backup_record.txt";
const int backup_max = 3;
const string lover_record = "lover_record.txt";
const int lover_max = 5;

EXTERN Status game_status, easy, diff,calc;
EXTERN Person game_lover, game_player;
EXTERN Person lover_profile[lover_max];
EXTERN string backup_list[backup_max];
EXTERN Backup display_list[backup_max];
EXTERN int lover_id[lover_max];

EXTERN int player_profile_size;
EXTERN int num_player;
EXTERN int record;

#endif
