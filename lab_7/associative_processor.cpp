//Author: Vodohleb04
#include "associative_processor.h"

using namespace std;

vector<MemoryWord> makeRandomMatrix(int strings_amount)
{
    srand(time(NULL));
    if(strings_amount < 1)
    {
        throw invalid_argument("Amount of strings of matrix must be greater then 0");
    }
    vector<MemoryWord> matrix(strings_amount);
    return matrix;
}

ostream& operator<<(ostream& out, vector<MemoryWord> memory_words)
{
    for(auto matrix_string : memory_words)
    {
        out << matrix_string << "\n";
    }
    return out;
}

MemoryWord findNearFromBelow(std::vector<MemoryWord> memory_words, MemoryWord word_to_search)
{
    if(memory_words.empty())
    {
        throw length_error("Can't do this operation for empty word matrix");
    }
    vector<int> lower_indexes = findLowerIndexes(memory_words, word_to_search);
    if(lower_indexes.empty())
    {
        throw domain_error("No lower words found");
    }
    MemoryWord max_lower_word = memory_words[lower_indexes[0]];
    for(int i = 1; i < lower_indexes.size(); i++)
    {
        if(max_lower_word < memory_words[lower_indexes[i]])
        {
            max_lower_word = memory_words[lower_indexes[i]];
        }
    }
    return max_lower_word;
}

std::vector<int> findLowerIndexes(std::vector<MemoryWord> memory_words, MemoryWord word_to_search)
{
    if(memory_words.empty())
    {
        throw length_error("Can't do this operation for empty word matrix");
    }
    vector<int> lower_indexes;
    for(int i =0 ; i < memory_words.size(); i ++)
    {
        if(memory_words[i] < word_to_search)
        {
            lower_indexes.push_back(i);
        }
    }
    return lower_indexes;
}

MemoryWord findNearFromAbove(std::vector<MemoryWord> memory_words, MemoryWord word_to_search)
{
    if(memory_words.empty())
    {
        throw length_error("Can't do this operation for empty word matrix");
    }
    vector<int> greater_indexes = findGreaterIndexes(memory_words, word_to_search);
    if(greater_indexes.empty())
    {
        throw domain_error("No greater words found");
    }
    MemoryWord min_greater_word = memory_words[greater_indexes[0]];
    for(int i = 1; i < greater_indexes.size(); i++)
    {
        if(min_greater_word > memory_words[greater_indexes[i]])
        {
            min_greater_word = memory_words[greater_indexes[i]];
        }
    }
    return min_greater_word;
}

std::vector<int> findGreaterIndexes(std::vector<MemoryWord> memory_words, MemoryWord word_to_search)
{
    if(memory_words.empty())
    {
        throw length_error("Can't do this operation for empty word matrix");
    }
    vector<int> greater_indexes;
    for(int i = 0 ; i < memory_words.size(); i ++)
    {
        if(memory_words[i] > word_to_search)
        {
            greater_indexes.push_back(i);
        }
    }
    return greater_indexes;
}

MemoryWord findAccordence(std::vector<MemoryWord> memory_words, MemoryWord word_to_search)
{
    if(memory_words.empty())
    {
        throw length_error("Can't do this operation for empty word matrix");
    }
    int max_accordance_index = 0;
    for(int i = 0; i < memory_words.size(); i++)
    {
        if(word_to_search.accordanceNumber(memory_words[i]) > word_to_search.accordanceNumber(memory_words[max_accordance_index]))
        {
            max_accordance_index = i;
        }
    }
    return memory_words[max_accordance_index];
}
