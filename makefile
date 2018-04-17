CC=gcc
STD=c11
FLAGS=-Wall -Wextra -pedantic -O0
OUTPUT=median

all: mt_random timer
	$(CC) *.c *.o $(FLAGS) -std=$(STD) -o $(OUTPUT) -lstdc++

mt_random: mt_random.cpp
	$(CC) -c mt_random.cpp -c -Wall -Wextra -pedantic -static -lstdc++ -std=c++17 -o mt_random.o -O2

timer: timer.cpp
	$(CC) -c timer.cpp -c -Wall -Wextra -pedantic -static -lstdc++ -std=c++17 -o timer.o -O2

clean:
	rm *.o
