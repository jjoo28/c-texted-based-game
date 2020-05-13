#include "general.h"
#include "globalv.h"
#include "display.h"
#include "data_structure.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <chrono>
#include <ios>

using namespace std;
//string typing_game: textfile name, consist of the source passage used to generate tasks
//int word_count: total number of words in the source passage
//int output_count: number of words to be typed in a task
//int task: number of tasks
//string passage: string array to hold the source passage
const string typing_game("typing_game.txt");
const int word_count = 255;
const int output_count = 10;
const int task = 3;
string passage[word_count];

//function game_rule(): display game rules
void game_rule(){
      cout << "You are now in work. Complete the typing task to earn money." << endl;
      cout << "Rules: Type the word between \" ... \". Formatting is important. Wrong formatting will be counted as mistake. Time count will start right after you press Enter." << endl;
      cout <<"============================================================================" << endl;
      cout << "Rewards: " << endl;
      cout << "Time used below 30s -> $50"<< endl;
      cout << "Mistakes below 3 -> $50"<< endl;
      cout << "============================================================================" << endl;
      clearscr();
}

//function load_passage(): load game tasks
void load_passage (string p[]){
      ifstream fin(typing_game);
      if (!fin.is_open()){
          exit(1);
      }

      int i = 0;
      while(!fin.eof()){
            fin >> p[i++];
      }

      fin.close();
}

//function generate_passage(): randomly generate tasks
int generate_passage (string p[]){
      int start = random_generator(word_count, output_count);
      cout << "...";
      if(start <= word_count - output_count){
          for (int i = start; i < output_count + start; i++){
                cout << p[i] << " ";
                if(i+1 == word_count)
                    break;
          }
      }
      cout << "..." << endl;
      return start;
}

//function format_output(): format the tasks for easy checking
void format_output(string ow[task][output_count], string p[], int o[]){
      int j, k;
      for(int i = 0; i < task; i++){
            for(j = o[i], k = 0; j < output_count + o[i] && k < output_count; j++, k++){
                  ow[i][k] = p[j];
            }
      }
}


int typing2(){
      load_passage(passage);
      display();
      game_rule();

      //string input[]: string array for input for each task
      //int output[]: the starting position of each tasks in the source passage
      string input[task];
      int output [task];

      auto start = chrono::high_resolution_clock::now();    //starting time
      for (int i = 0; i < task; i++){
            cout << "Excerpt " << i + 1 << endl;
            output[i] = generate_passage (passage);
            cout << "Your input ~>";
            getline(cin, input[i]);
            cout << endl;
      }
      auto stop = chrono::high_resolution_clock::now();     //stoping time
      auto duration = chrono::duration_cast<chrono::seconds>(stop - start);  //duration time

      //string output_word[]: formatted tasks to turn a line into words
      string output_word[task][output_count];
      format_output(output_word, passage, output);

      //int wrong: number of wrong input
      //int entered: number of entered words
      int wrong = 0, entered = 0;
      for (int i = 0; i < task; i++){
            istringstream line(input[i]);
            string word;
            int j = 0;

            if(output[i] > word_count - output_count) //the task is empty
                entered += 10;
            else{
                while(line >> word){
                    entered++;
                    string correct_word = output_word[i][j++];
                    if(word != correct_word)
                        wrong++;
                }
          }

      }

      //int empty: number of empty words
      //int earn: total money earning
      int empty = task * output_count - entered;
      int earn = 0;
      if (duration.count() < 30)
          earn += 50;

      if (empty + wrong < 3)
          earn += 50;

      //Display result
      cout << "Result" << endl;
      cout << "============================================================================" << endl;
      cout.width(16); cout << left << "Time used: " << duration.count() << "s" << endl;
      cout.width(16); cout << left << "Correct words: " << entered - wrong << endl;
      cout.width(16); cout << left << "Wrong words: " << wrong << endl;
      cout.width(16); cout << left << "Empty words: " << empty << endl;
      cout.width(16); cout << left << "Total mistakes: " << empty + wrong << endl;
      cout << "============================================================================" << endl;
      cout << "You earned $" << earn << " in total." << endl;
      clearscr();




      return earn;
}
