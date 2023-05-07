
myprog.exe : main_tmp.o schema.o table.o DataView.o database.o
	g++ main_tmp.o schema.o table.o DataView.o database.o -o myprog.exe

main_tmp.o : main_tmp.cpp schema.h table.h DataView.h database.h
	g++ -Wall -c main_tmp.cpp

schema.o : schema.cpp schema.h
	g++ -Wall -c schema.cpp

table.o : table.cpp table.h
	g++ -Wall -c table.cpp

DataView.o : DataView.cpp DataView.h
	g++ -Wall -c DataView.cpp

database.o : database.cpp Database.h
	g++ -Wall -c database.cpp

clean :
	rm *.o myprog.exe
