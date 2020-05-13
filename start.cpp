#include "data_structure.h"
#include "globalv.h"
#include "general.h"
#include "new_game.h"
#include "display.h"
#include "game.h"
#include "restore.h"
#include "load.h"
#include "backup.h"




#include <iostream>
#include <string>

using namespace std;

void start_menu(){
      cout << "============================================================================" << endl;
      cout << "♥    _                                             _      _                $" << endl;
      cout << "♥   | |                                           | |    (_)               $" << endl;
      cout << "♥   | |      ___ __   __ ___       ___   _ __     | |     _ __   __ ___    $" << endl;
      cout << "♥   | |     / _ \\\\ \\ / // _ \\     / _ \\ | '__|    | |    | |\\ \\ / // _ \\   $" << endl;
      cout << "♥   | |____| (_) |\\ V /|  __/    | (_) || |       | |____| | \\ V /|  __/   $" << endl;
      cout << "♥   \\_____/ \\___/  \\_/  \\___|     \\___/ |_|       \\_____/|_|  \\_/  \\___|   $" << endl;
      cout << "♥                                                                          $" << endl;
      cout << "============================================================================" << endl;
      cout << endl;
      cout << "1. New Game" << endl;
      cout << "2. Continue" << endl;
      cout << "3. Quit" << endl;
      cout << "Please enter your choice ~>";

}

void start(){
      int choice;
      do{
            start_menu();
            choice = valid_choice(3);
      }
      while (choice == -1);

      switch (choice) {
            case 1: {
                system("clear");
                _new_game();
                menu();
            }
            break;
            case 2: {
                system("clear");
                _restore();
                menu();
            }
            break;
            case 3: {
                cout << "Bye Bye!" << endl;
                exit(1);
            }
      }
}

int main(){
    system("clear");
    _load();
    start();
    return 0;
}
