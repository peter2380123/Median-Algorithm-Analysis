CC=gcc
STD=c11
FLAGS=-Wall -Wextra -pedantic -O0 -g
OUTPUT=median

all: mt_random
	$(CC) *.c mt_random.o $(FLAGS) -std=$(STD) -o $(OUTPUT) -lstdc++

mt_random: mt_random.cpp
	$(CC) -c mt_random.cpp -Wall -Wextra -pedantic -static -lstdc++ -std=c++17 -o mt_random.o -g

clean:
	rm *.o
