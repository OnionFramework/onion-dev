CPP = g++
FLAGS = -I ../../onion
EXEC_FILE = main

all: FLAGS += -O2 -O3
all: main

debug: FLAGS += -g -Wall
debug: main

main:
	$(CPP) main.cpp -o $(EXEC_FILE) $(FLAGS)

