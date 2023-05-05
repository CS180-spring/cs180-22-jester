myprog.exe : main.o schema.o
    g++ main.o schema.o -o myprog.exe

main.o : main_temp.cpp schema.h
    g++ -Wall -c main.cpp 

schema.o : schema.cpp schema.h
    g++ -Wall -c schema.cpp 

schema.o : table.cpp table.h
    g++ -Wall -c table.cpp 

schema.o : DataView.cpp DataView.h
    g++ -Wall -c DataView.cpp 



clean :
    rm *.o myprog.exe