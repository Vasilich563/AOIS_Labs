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
    return MemoryWord();
    // TODO
}

std::vector<int> findLowerIndexes(std::vector<MemoryWord> word_matrix, MemoryWord word)
{
    return vector<int>();
    // TODO
}

MemoryWord findNearFromAbove(std::vector<MemoryWord> word_matrix, MemoryWord word)
{
    return MemoryWord();
    // TODO
}

std::vector<int> findGreaterIndexes(std::vector<MemoryWord> word_matrix, MemoryWord word)
{
    return vector<int>();
    // TODO
}
