all: test.o server.o server.h
	g++ server.o test.o -o a.out

server.o: server.cc server.h
	g++ -c server.cc

test.o: test.cc server.h
	g++ test.cc -c -o test.o

clean:
	rm *.o a.out

