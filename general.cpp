#include "general.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void clearscr (){
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
    system("clear");
}

int random_generator (int x, int y){
    srand(time(NULL));
    return rand() % x + y;
}

int valid_choice (int max){
      string input;
          cin >> input;
          for (int i = 0; i < input.length(); i++){
              if (!isdigit(input[i])){
                    cout << "Oops! Please input again." << endl;
                    clearscr();
                    return -1;
              }
          }
          if (stoi(input) < max - max + 1 || stoi(input) > max){
                cout << "Please input a valid option." << endl;
                clearscr();
                return -1;
          }
          else return stoi(input);
      return 0;
}
