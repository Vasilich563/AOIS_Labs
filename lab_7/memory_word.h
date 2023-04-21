//Author: Vodohleb04
#pragma once

#ifndef _MEMORY_WORD_
#define _MEMORY_WORD_
//#define WORD_LENGTH 16
#define WORD_LENGTH 8

#include <vector>
#include <fstream>
#include <iostream>


class MemoryWord;

std::ostream& operator<<(std::ostream& out, const MemoryWord& memory_word);

class MemoryWord
{
private:

    std::vector<int> word_data;

    friend std::ostream& operator<<(std::ostream& out, const MemoryWord& memory_word);

public:

    MemoryWord();
    
    MemoryWord(const MemoryWord& other);

    MemoryWord& operator=(const MemoryWord& other);

    bool operator<(const MemoryWord& other);

    bool operator>(const MemoryWord& other);

    bool operator==(const MemoryWord& other);

    bool operator!=(const MemoryWord& other);

    std::vector<int>& getWordData();

};



#endif //!_MEMORY_WORD_
