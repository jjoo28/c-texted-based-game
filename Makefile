
love_event.o: love_event.cpp data_structure.h general.h display.h game.h globalv.h
	g++ -c love_event.cpp

load.o: load.cpp data_structure.h display.h globalv.h
	g++ -c load.cpp

game.o:game.cpp data_structure.h typing_game.h general.h display.h new_game.h game.h backup.h globalv.h
	g++ -c game.cpp

typing_game.o:typing_game.cpp data_structure.h typing_game.h general.h display.h love_event.h new_game.h game.h backup.h globalv.h
	g++ -c typing_game.cpp

new_game.o: new_game.cpp data_structure.h general.h new_game.h display.h globalv.h
	g++ -c new_game.cpp

backup.o: backup.cpp data_structure.h general.h display.h backup.h game.h start.h load.h globalv.h
	g++ -c backup.cpp

display.o: display.cpp data_structure.h display.h start.h globalv.h
	g++ -c display.cpp

general.o: general.cpp general.h
	g++ -c general.cpp

start.o: start.cpp data_structure.h general.h new_game.h display.h game.h restore.h load.h backup.h globalv.h
	g++ -c start.cpp

restore.o: restore.cpp data_structure.h display.h general.h restore.h load.h start.h globalv.h
	g++ -c restore.cpp


love_live: love_event.o load.o game.o typing_game.o new_game.o display.o backup.o general.o start.o restore.o globalv.h
	g++ -pedantic-errors -std=c++11 love_event.o load.o game.o typing_game.o new_game.o display.o backup.o general.o start.o restore.o -o love_live
