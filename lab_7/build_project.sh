g++ -c -I. main.cpp
g++ -c -I. associative_processor.cpp
g++ associative_processor.o main.o -o main.exe
./main.exe
