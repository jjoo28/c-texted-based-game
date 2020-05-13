#ifndef RESTORE_H
#define RESTORE_H

#include "data_structure.h"

bool check_empty (string bl[]);

void restore_menu (Backup dl[]);
int confirm_restore (Backup dl[], int c);
void restore(Backup d);
void _restore();

#endif
