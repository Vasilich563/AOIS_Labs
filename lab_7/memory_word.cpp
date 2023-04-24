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

unsigned int MemoryWord::current_g(unsigned int previous_g, unsigned int previous_l, unsigned int this_word_i_digit, unsigned int other_word_i_digit)
{
    return (previous_g | ((!this_word_i_digit) & other_word_i_digit & (!previous_l)));
}

unsigned int MemoryWord::current_l(unsigned int previous_l, unsigned int previous_g, unsigned int this_word_i_digit, unsigned int other_word_i_digit)
{
    return (previous_l | (this_word_i_digit & (!other_word_i_digit) & (!previous_g)));
}

bool MemoryWord::operator==(const MemoryWord& other)
{
    unsigned int g = 0;
    unsigned int l = 0;
    for(int i = 0; i < word_data.size(); i++)
    {
        g = MemoryWord::current_g(g, l, this->word_data[i], other.word_data[i]);
        l = MemoryWord::current_l(l, g, this->word_data[i], other.word_data[i]);
    }
    return (g == 0 && l == 0);
}

bool MemoryWord::operator!=(const MemoryWord& other)
{
    unsigned int g = 0;
    unsigned int l = 0;
    for(int i = 0; i < word_data.size(); i++)
    {
        g = MemoryWord::current_g(g, l, (unsigned int)(this->word_data[i]), (unsigned int)(other.word_data[i]));
        l = MemoryWord::current_l(l, g, (unsigned int)(this->word_data[i]), (unsigned int)(other.word_data[i]));
    }
    return (g != 0 && l != 0);
}

bool MemoryWord::operator<(const MemoryWord& other)
{
    unsigned int g = 0;
    unsigned int l = 0;
    for(int i = 0; i < word_data.size(); i++)
    {
        g = MemoryWord::current_g(g, l, (unsigned int)(this->word_data[i]), (unsigned int)(other.word_data[i]));
        l = MemoryWord::current_l(l, g, (unsigned int)(this->word_data[i]), (unsigned int)(other.word_data[i]));
    }
    return (g == 1 && l == 0);
}

bool MemoryWord::operator>(const MemoryWord& other)
{
    unsigned int g = 0;
    unsigned int l = 0;
    for(int i = 0; i < word_data.size(); i++)
    {
        g = MemoryWord::current_g(g, l, (unsigned int)(this->word_data[i]), (unsigned int)(other.word_data[i]));
        l = MemoryWord::current_l(l, g, (unsigned int)(this->word_data[i]), (unsigned int)(other.word_data[i]));
    }
    return (g == 0 && l == 1);
}

int MemoryWord::accordanceNumber(const MemoryWord& other)
{
    int accordance_number = 0;
    for(int i = 0; i < word_data.size(); i++)
    {
        if(word_data[i] == other.word_data.at(i))
        {
            ++accordance_number;
        }
    }
    return accordance_number;
}
