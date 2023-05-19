all: test.o server.o server.h
	g++ --std=c++11 server.o test.o -o a.out

server.o: server.cc server.h
	g++ --std=c++11 -c server.cc

test.o: test.cc server.h
	g++ --std=c++11 test.cc -c -o test.o

client: 
	g++ --std=c++11 clientTest.cc -o client

clear:
	rm client

clean:
	rm *.o a.out

