 //Author: Vodohleb04

 #include "diagonal_associative_memory.h"

 using namespace std;


ostream& operator<<(ostream& out, const DiagonalAM& diagonal_am)
{
    for(int i = 0; i < diagonal_am.memory_words.size(); i++)
    {
        for(int j = 0; j < diagonal_am.memory_words.size(); j++)
        {
            out << diagonal_am.memory_words[i][j] << " ";
        }
        out << endl;
    }
    return out;
}


void DiagonalAM::emplaceRandomWords(int memory_size)
{
    srand(time(NULL));
    for(int i = 0; i < memory_size; i++)
    {
        for(int j = 0; j < memory_size; j++)
        {
            memory_words[i].push_back(rand() % 2);
        }
    }
}

DiagonalAM::DiagonalAM(int size)
{
    if(size <= 0)
    {
        throw invalid_argument("size must be greater then 0");
    }
    memory_words.resize(size);
    emplaceRandomWords(size);
}

DiagonalAM::DiagonalAM(const DiagonalAM& other)
{
    this->memory_words = other.memory_words;
}

DiagonalAM& DiagonalAM::operator=(const DiagonalAM& other)
{
    this->memory_words = other.memory_words;
    return *this;
}

vector<unsigned int> DiagonalAM::getMatrixString(int string_index)
{
    if(string_index < 0 || string_index >= memory_words.size())
    {
        throw out_of_range("string_index out of range");
    }
    vector<unsigned int> memory_string(memory_words.size());
    for(int j = 0; j < memory_string.size(); j++)
    {
        memory_string[j] = memory_words[string_index][j];
    }
    return memory_string;
}

vector<unsigned int> DiagonalAM::getWord(int word_index)
{
    if(word_index < 0 || word_index >= memory_words.size())
    {
        throw out_of_range("word_index out of range");
    }
    vector<unsigned int> word(memory_words.size());
    for(int i = 0; i < word.size(); i++)
    {
        int string_index;
        if(i + word_index >= memory_words.size())
        {
            string_index = (i + word_index) - memory_words.size();
        }
        else
        {
            string_index = i + word_index;
        }
        word[i] = memory_words[string_index][word_index];
    }
    return word;    
}

size_t DiagonalAM::size()
{
    return memory_words.size();
}

size_t DiagonalAM::size() const
{
    return memory_words.size();
}
