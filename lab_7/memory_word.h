//Author: Vodohleb04
#pragma once

#ifndef _MEMORY_WORD_
#define _MEMORY_WORD_

#include <vector>
#include <fstream>


class MemoryWord;

inline std::ostream& operator<<(std::ostream& out, const MemoryWord&);

class MemoryWord
{
private:

    std::vector<int> word_data;

    friend inline std::ostream& operator<<(std::ostream& out, const MemoryWord&);

public:

    MemoryWord();
    
    MemoryWord(const MemoryWord& other);

    MemoryWord& operator=(const MemoryWord& other);

    bool operator<(const MemoryWord& other);

    bool operator>(const MemoryWord& other);

    bool operator==(const MemoryWord& other);

    bool operator!=(const MemoryWord& other);

    std::vector<int>& getWordData();

    std::vector<int>& getWordData() const;

};


#endif //!_MEMORY_WORD_
