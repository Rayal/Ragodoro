CC=g++
LIBS = glib-2.0 gtk+-2.0 libnotify
CFLAGS=-I. `pkg-config --cflags --libs $(LIBS)`
DEPS = hellomake.h

hellomake: hellomake.o hellofunc.o
	$(CC) $(CFLAGS) -o hellomake.bin hellomake.o hellofunc.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c -o main.o main.cpp

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^
main: main.o MyNotifier.o
	$(CC) -o main.bin main.o MyNotifier.o $(CFLAGS)

clean:
	rm *.o *.bin