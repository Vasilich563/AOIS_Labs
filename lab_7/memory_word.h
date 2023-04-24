//Author: Vodohleb04
#pragma once

#ifndef _MEMORY_WORD_
#define _MEMORY_WORD_
#define WORD_LENGTH 16

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

    static uint current_g(uint previous_g, uint previous_l, uint this_word_digit, uint other_word_digit);

    static uint current_l(uint previous_l, uint previous_g, uint this_word_digit, uint other_word_digit);

public:

    MemoryWord();
    
    MemoryWord(const MemoryWord& other);

    MemoryWord& operator=(const MemoryWord& other);

    bool operator<(const MemoryWord& other);

    bool operator>(const MemoryWord& other);

    bool operator==(const MemoryWord& other);

    bool operator!=(const MemoryWord& other);

    int accordanceNumber(const MemoryWord& other);

    std::vector<int>& getWordData();

};



#endif //!_MEMORY_WORD_
