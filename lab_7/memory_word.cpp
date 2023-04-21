//Author: Vodohleb04
#include "memory_word.h"

using namespace std;

std::ostream& operator<<(std::ostream& out, const MemoryWord& memory_word)
{
    for(auto digit : memory_word.word_data)
    {
        out << digit << " ";
    } 
    return out;
}


MemoryWord::MemoryWord()
{
    for(int j = 0; j < WORD_LENGTH; j++)
    {
        word_data.push_back(rand() % 2);
    }
}

MemoryWord::MemoryWord(const MemoryWord& other)
{
    this->word_data = other.word_data;
}

MemoryWord& MemoryWord::operator=(const MemoryWord& other)
{
    this->word_data = other.word_data;
    return *this;
}

vector<int>& MemoryWord::getWordData()
{
    return word_data;
}

bool MemoryWord::operator==(const MemoryWord& other)
{
    for(int i = 0; i < word_data.size(); i++)
    {
        if(word_data[i] != other.word_data.at(i))
        {
            return false;
        }
    }
    return true;
}

bool MemoryWord::operator!=(const MemoryWord& other)
{
    for(int i = 0; i < word_data.size(); i++)
    {
        if(word_data[i] == other.word_data.at(i))
        {
            return false;
        }
    }
    return true;
}

bool MemoryWord::operator<(const MemoryWord& other)
{
    for(int i =0; i < word_data.size(); i++)
    {
        if(word_data[i] < other.word_data.at(i))
        {
            return true;
        }
        else if(word_data[i] > other.word_data.at(i))
        {
            return false;
        }
    }
    return false;
}

bool MemoryWord::operator>(const MemoryWord& other)
{
    for(int i =0; i < word_data.size(); i++)
    {
        if(word_data[i] > other.word_data.at(i))
        {
            return true;
        }
        else if(word_data[i] < other.word_data.at(i))
        {
            return false;
        }
    }
    return false;
}

int MemoryWord::accordanceNumber(const MemoryWord& other)
{
    int accordance_number = 0;
    for(int i = 0; i < word_data.size(); i++)
    {
        if(word_data[i] == other.word_data.at(i))
        {
            accordance_number += 1;
        }
    }
    return accordance_number;
}
