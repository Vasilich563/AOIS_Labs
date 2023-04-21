g++ -c -I. main.cpp
g++ -c -I. associative_processor.cpp
g++ -c -I. memory_word.cpp
g++ associative_processor.o main.o memory_word.o -o main.exe
./main.exe
