# group_246
COMP2113_GROUP PROJECT
1.Information of two members
- Chang Hoi Kiu 3035578276
- Jung Eun JOO 3035552246


2. Description
- It is now the time of the coronavirus pandemic. You are now in your house and you are now in  an ambiguous relationship with a boy/girl (the love). You should deepen your love relationship  but also survive from the pandemic.

- You need to choose between your love and health and make your choices wisely.

- To survive from coronavirus the player should go out to buy a mask or to work to earn money. This is done through rock paper scissor game and text writing game.


3. Game rule
- The player starts with specific love and health points according to chosen difficulties.
- When the player health status is lower than 15 → the player lose the game When the player love status lower than 15 → the player lose the game
- If the player finished all the love events → player becomes the winner of the game
- The love point and the health point changes by the choices that the player's make
- player's can buy a mask to earn mask or can go to work to earn money. The amount of mask/money depends on the player's performance (the player’s mini game performance ex.rock paper scissors, text writing game)

4. Compilation and execution instructions
- download all the files in the branch including makefile, txt.file and other source files (.h/.cpp)
- unzip the files and execute in linux ubuntu
- enter words written between parenthesis->  (make love_live)
- the files being complied and executed.

5. List of features and functions
1) start()
- a function that indicates the beginning of the game.
- located in start.cpp and through start.h is used in different cpp files ex) game.cpp
- code requirement 5)Program codes in multiple files

2) load data from textfiles
- lover's profile, player's profile, backup_list, presets, log files and game source text are read from the corresponding text files and stored in structs and dynamic arrays.
- located in load.cpp
- code requirement 2) data structures for storing game status, 3) dynamic memory management, 4) file input/output

3) restore data from textfiles
- store data from the required backup choice to the current game status if chosen continue a saved progress.
- located in restore.cpp
- code requirement 1) data structures for storing game status.

4) initializing a new game
- starting a new game by asking the player to choose the difficulty, input their information and randomly generating a lover and an player id to them.
- located in new_game.cpp
- code requirement: 1) generating of random game sets or event, 2) data structures for storing game status

5) showing the game status
- present the player's current status while playing the game
- included in display.cpp
- code requirement 5) program codes in multiple files

6) showing the game menu
- making choices to play the game

7)buy mask
- random rock-paper-scissor game
- used random_generator() located in the general.cpp
- code requirement 1) generation of random game sets or events

8) typing game
- To give out random extract sample for the players to type the following words
- used random_generator()
- code requirement 1) generation of random game sets or events

9) love events
- have certain path to develop love relationship with the lover. Some situations are randomly generated.
- code requirement 1) generation of random game sets or events

10) pausing the game
- A feature to pause the progress. The game progress is logged by a linked list everytime the game is paused. Player can either continue the game, save the game or quit the game.
- located in backup.cpp
- code requirement 3) dynamic memory management

11) backup data to textfiles
- write the player information, player game status and the latest backup list to text files.
- located in backup.cpp
- code requirement 3) dynamic memory management, 4)file input/output

12) Struct person, Struct status, Struct backup
- created person to save lover's profile and player's record,
- created status to save game_status
- created backup to save player's game_status, player's profile, lover's profile, and own log-file.
- located in data_structures.h
- code requirement 2)Data structures for storing game status

13) dynamic arrays handling
- Person * player_profile is an dynamic array storing the records of all players that has been playing the game. grow_player_profile(), load_player_profile(), add_player_profile(), sort_player_profile() and sav_player_profile() includes the management of dynamic memory.
- functions are located in load.cpp and backup.cpp respectively
- code requirement 3)Dynamic memory management

14) commonly used functions gathered in one file
- cpp containing random generator, and pausing & clear screen functions and input validation function
- through general.h those functions are usind in game.cpp, start.cpp, type_game.cpp, new_game.cpp, love_event.cpp ...etc
- code requirement 5) program codes in multiple files

15) functions tracking and updating the game status
- game stautus is update and tracked with every event of the player to indicate winning or losing
- included in display.cpp

16) Game program
- compiled with restore.cpp, love_event.cpp, game.cpp, start.cpp, new_game.cpp, load.cpp, backup.cpp, typing_game.cpp, display.cpp, general.cpp
- code requirement 5) program codes in multiple files


Appendix : love storyline
Love option
__________________________________________________________________________
1st event

Situation1: the love calls ask for a date, go out?

 Have mask
 - say yes: love point +10 → [Use 1 mask] → situation2
 - say no: love pont -5 → week += 1

 Don't have mask
 - say yes: love point +10 → health point -10 → situaltion2
 - say no: love point -5 → week += 1

Situation 2: while you go you meet a random person (infected/not infected) on street

 Option 1: Stay away from the person → go to situation 3

 Option 2: Just walk → the person spits  
 - Have mask → health points -15 → go to situation 3
 - No mask → health points -35 → go to situation 3

Situation 3: we meet the lover have a nice date → love point +10 → end of 1st event
__________________________________________________________________________
2nd event

Situation1: the love calls and ask you to meet in a crowded area.

 Have mask
 - say yes: health point -85 → [Use 1 mask]
 - say no: do a skype meeting, health point +5 → situation 2

 Don’t have mask
 - say yes: health point -85
 - say no: do a skype meeting  health point +5 → situation 2

Situation 2: the lover ask a cringy question
- Answer option 1 → love point -10
- Answer option 2 → love point -15

Situation 3: say something to make lover happy
- Answer option 1 → love point +5 → end of 2nd event
- Answer option 2 → love point +5 → end of 2nd event
__________________________________________________________________________
3rd event

Situation 1: lover’s birthday, need to buy a present

 Have a mask
 - delivery → situation 2
 - go out and buy the present →[Use 1 mask] → health point -5

 No mask
 - delivery → situation 2
 - go out and buy the present → health point -35

Situation 2: Which present will the player give the lover
- Present 1: love point +30 → end of 3rd event
- Present 2: love point -30 → end of 3rd event
