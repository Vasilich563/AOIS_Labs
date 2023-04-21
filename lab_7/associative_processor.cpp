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

ostream& operator<<(ostream& out, vector<MemoryWord> word_matrix)
{
    for(auto matrix_string : word_matrix)
    {
        out << matrix_string << "\n";
    }
    return out;
}

MemoryWord findNearFromBelow(std::vector<MemoryWord> word_matrix, MemoryWord word)
{
    vector<int> lower_indexes = findLowerIndexes(word_matrix, word);
    if(lower_indexes.empty())
    {
        throw domain_error("No lower words found");
    }
    MemoryWord max_lower_word = word_matrix[lower_indexes[0]];
    for(int i = 1; i < lower_indexes.size(); i++)
    {
        if(max_lower_word < word_matrix[lower_indexes[i]])
        {
            max_lower_word = word_matrix[lower_indexes[i]];
        }
    }
    return max_lower_word;
}

std::vector<int> findLowerIndexes(std::vector<MemoryWord> word_matrix, MemoryWord word)
{
    vector<int> lower_indexes;
    for(int i =0 ; i < word_matrix.size(); i ++)
    {
        if(word_matrix[i] < word)
        {
            lower_indexes.push_back(i);
        }
    }
    return lower_indexes;
}

MemoryWord findNearFromAbove(std::vector<MemoryWord> word_matrix, MemoryWord word)
{
    vector<int> greater_indexes = findGreaterIndexes(word_matrix, word);
    if(greater_indexes.empty())
    {
        throw domain_error("No greater words found");
    }
    MemoryWord min_greater_word = word_matrix[greater_indexes[0]];
    for(int i = 1; i < greater_indexes.size(); i++)
    {
        if(min_greater_word > word_matrix[greater_indexes[i]])
        {
            min_greater_word = word_matrix[greater_indexes[i]];
        }
    }
    return min_greater_word;
}

std::vector<int> findGreaterIndexes(std::vector<MemoryWord> word_matrix, MemoryWord word)
{
    vector<int> greater_indexes;
    for(int i =0 ; i < word_matrix.size(); i ++)
    {
        if(word_matrix[i] > word)
        {
            greater_indexes.push_back(i);
        }
    }
    return greater_indexes;
}
