myprog.exe : main_tmp.o schema.o table.o DataView.o database.o
	g++ -std=c++0x main_tmp.o schema.o table.o DataView.o database.o -o myprog.exe

main_tmp.o : main_tmp.cpp schema.h table.h DataView.h database.h
	g++ -std=c++0x -Wall -c main_tmp.cpp

schema.o : schema.cpp schema.h
	g++ -std=c++0x -Wall -c schema.cpp

table.o : table.cpp table.h
	g++ -std=c++0x -Wall -c table.cpp

DataView.o : DataView.cpp DataView.h
	g++ -std=c++0x -Wall -c DataView.cpp

database.o : database.cpp database.h
	g++ -std=c++0x -Wall -c database.cpp

clean :
	rm *.o myprog.exe