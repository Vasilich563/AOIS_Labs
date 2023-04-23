g++ -c -I. main.cpp
g++ -c -I. diagonal_associative_memory.cpp
g++ diagonal_associative_memory.o main.o -o main.exe
./main.exe
