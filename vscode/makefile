CPP = g++
FLAGS = -pipe -std=gnu++1z -I. -I ../../onion -Wall -Wextra
EXEC_FILE = main

all: FLAGS += -O2 -O3
all: main

debug: FLAGS += -g
debug: main

main.o: main.cpp
	$(CPP) -c $(FLAGS) -o main.o main.cpp
main: main.o
	$(CPP) -Wl,-O1 -o $(EXEC_FILE) main.o

