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


int DiagonalAM::countDigitStringIndex(int word_index, int digit_position)
{
    if(digit_position + word_index >= memory_words.size())
        return (word_index + digit_position) - memory_words.size();
    else
        return word_index + digit_position;
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

uint DiagonalAM::constZeroDigit(uint first_word_digit, uint second_word_digit)
{
    return 0;
}

uint DiagonalAM::constOneDigit(uint first_word_digit, uint second_word_digit)
{
    return 1;
}

uint DiagonalAM::repeatSecondDigit(uint first_word_digit, uint second_word_digit)
{
    return second_word_digit;
}

uint DiagonalAM::negateSecondDigit(uint first_word_digit, uint second_word_digit)
{
    return (!second_word_digit);
}

uint DiagonalAM::current_g(uint previous_g, uint previous_l,
                                   uint this_word_i_digit, uint other_word_i_digit)
{
    return (previous_g | ((!this_word_i_digit) & other_word_i_digit & (!previous_l)));
}

uint DiagonalAM::current_l(uint previous_l, uint previous_g,
                                   uint this_word_i_digit, uint other_word_i_digit)
{
    return (previous_l | (this_word_i_digit & (!other_word_i_digit) & (!previous_g)));
}

bool DiagonalAM::firstIsGreater(int first_word_index, int second_word_index)
{
    uint g = 0;
    uint l = 0;
    for(int i = 0; i < memory_words.size(); i++)
    {
        int first_word_string_index = countDigitStringIndex(first_word_index, i);
        int second_word_string_index = countDigitStringIndex(second_word_index, i);

        uint first_word_digit = memory_words[first_word_string_index][first_word_index];
        uint second_word_digit = memory_words[second_word_string_index][second_word_index];

        g = DiagonalAM::current_g(g, l, first_word_digit, second_word_digit);
        l = DiagonalAM::current_l(l, g, first_word_digit, second_word_digit);
    }
    return (g == 0 && l == 1);
}

bool DiagonalAM::firstIsLower(int first_word_index, int second_word_index)
{
    uint g = 0;
    uint l = 0;
    for(int i = 0; i < memory_words.size(); i++)
    {
        int first_word_string_index = countDigitStringIndex(first_word_index, i);
        int second_word_string_index = countDigitStringIndex(second_word_index, i);

        uint first_word_digit = memory_words[first_word_string_index][first_word_index];
        uint second_word_digit = memory_words[second_word_string_index][second_word_index];

        g = DiagonalAM::current_g(g, l, first_word_digit, second_word_digit);
        l = DiagonalAM::current_l(l, g, first_word_digit, second_word_digit);
    }
    return (g == 1 && l == 0);
}

bool DiagonalAM::areEquale(int first_word_index, int second_word_index)
{
    uint g = 0;
    uint l = 0;
    for(int i = 0; i < memory_words.size(); i++)
    {
        int first_word_string_index = countDigitStringIndex(first_word_index, i);
        int second_word_string_index = countDigitStringIndex(second_word_index, i);

        uint first_word_digit = memory_words[first_word_string_index][first_word_index];
        uint second_word_digit = memory_words[second_word_string_index][second_word_index];

        g = DiagonalAM::current_g(g, l, first_word_digit, second_word_digit);
        l = DiagonalAM::current_l(l, g, first_word_digit, second_word_digit);
    }
    return (g == 0 && l == 0);
}

int DiagonalAM::accordanceNumber(vector<uint> word_to_compare, int memory_word_index)
{
    int accordance_number = 0;
    for(int i = 0; i < word_to_compare.size(); i++)
    {
        int memory_word_string_index = countDigitStringIndex(memory_word_index, i);
        if(word_to_compare[i] == memory_words[memory_word_string_index][memory_word_index])
        {
            ++accordance_number;
        }
    }
    return accordance_number;
}


#include<iostream>
bool DiagonalAM::vPartsAreEquale(std::vector<uint> word_to_compare, int memory_word_index)
{
    for(int i = 0; i < vPartSize(); i ++)
    {
        int memory_word_string_index = countDigitStringIndex(memory_word_index, i);
        cout << i << "\t" << ((word_to_compare[i] == memory_words[memory_word_string_index][memory_word_index])?"True":"False") << std::endl;
        if(word_to_compare[i] != memory_words[memory_word_string_index][memory_word_index])
        {
            return false;
        }
    }
    return true;
}

int DiagonalAM::vPartSize()
{
    return (memory_words.size() / 4) - 1;
}

int DiagonalAM::aPartSize()
{
    return memory_words.size() / 4;
}

int DiagonalAM::bPartSize()
{
    return memory_words.size() / 4;
}

int DiagonalAM::sPartSize()
{
    return (memory_words.size() / 4) + 1;
}

uint DiagonalAM::getADigit(int memory_word_index, int ab_shift)
{
    int a_position = vPartSize() + ab_shift;
    return memory_words[countDigitStringIndex(memory_word_index, a_position)][memory_word_index];
}

uint DiagonalAM::getBDigit(int memory_word_index, int ab_shift)
{
    int b_position = vPartSize() + aPartSize() + ab_shift;
    return memory_words[countDigitStringIndex(memory_word_index, b_position)][memory_word_index];
}

uint DiagonalAM::countSDigit(uint a_digit, uint b_digit, uint transfer_digit)
{
    return ((a_digit | b_digit | transfer_digit) & (a_digit | (!b_digit) | (!transfer_digit)) &
            ((!a_digit) | b_digit | (!transfer_digit)) & ((!a_digit) | (!b_digit) | transfer_digit));
}

uint DiagonalAM::countTransferDigit(uint a_digit, uint b_digit, uint transfer_digit)
{
    return (a_digit | b_digit) & (a_digit | transfer_digit) & (b_digit | transfer_digit);
}

void DiagonalAM::addOperation(int memory_word_index)
{
    uint transfer_digit = 0;
    int s_basic_start_pos = vPartSize() + aPartSize() + bPartSize();
    int s_shift = sPartSize() - 1;
    int current_s_string_index;
    for(int ab_shift = aPartSize() - 1; ab_shift >= 0 ; ab_shift--)
    {
        uint a_digit = getADigit(memory_word_index, ab_shift);
        uint b_digit = getBDigit(memory_word_index, ab_shift);
        current_s_string_index = countDigitStringIndex(memory_word_index, s_basic_start_pos + s_shift);
        cout << "s_string: " << current_s_string_index << endl;

        cout << "a: " << a_digit << "\tb: " << b_digit << "\tt: " << transfer_digit << "\ts: " << countSDigit(a_digit, b_digit, transfer_digit) << "\t";
        memory_words[current_s_string_index][memory_word_index] = countSDigit(a_digit, b_digit, transfer_digit);
        transfer_digit = countTransferDigit(a_digit, b_digit, transfer_digit);
        cout << "new t: " << transfer_digit << endl;
        --s_shift;
    }
    current_s_string_index = countDigitStringIndex(memory_word_index, s_basic_start_pos + s_shift);
    memory_words[current_s_string_index][memory_word_index] = transfer_digit;
}


DiagonalAM::DiagonalAM(int size)
{
    if(size <= 0)
    {
        throw invalid_argument("size must be greater then 0");
    }
    
    // TODO check if size is degree of 2, that >= 2^3
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

vector<uint> DiagonalAM::getMatrixString(int string_index)
{
    if(string_index < 0 || string_index >= memory_words.size())
    {
        throw out_of_range("string_index out of range");
    }
    vector<uint> memory_string(memory_words.size());
    for(int j = 0; j < memory_string.size(); j++)
    {
        memory_string[j] = memory_words[string_index][j];
    }
    return memory_string;
}

vector<uint> DiagonalAM::getWord(int word_index)
{
    if(word_index < 0 || word_index >= memory_words.size())
    {
        throw out_of_range("word_index out of range");
    }
    vector<uint> word(memory_words.size());
    for(int i = 0; i < word.size(); i++)
    {
        int string_index = countDigitStringIndex(word_index, i);
        word[i] = memory_words[string_index][word_index];
    }
    return word;    
}

void DiagonalAM::insertWord(vector<uint> word_to_insert, int word_index)
{
    if(word_index < 0 || word_index >= memory_words.size())
        throw out_of_range("word_index out of range");
    if(word_to_insert.size() != memory_words.size())
        throw length_error("Uncorrect word size");
    for(int i = 0; i < word_to_insert.size(); i++)
    {
        int string_index = countDigitStringIndex(word_index, i);
        memory_words[string_index][word_index] = word_to_insert[i];
    }
}

void DiagonalAM::constantZeroLF(int first_arg_index, int second_arg_index, int result_index)
{
    if(second_arg_index < 0 || second_arg_index >= memory_words.size())
        throw out_of_range("word index out of range");
    if(result_index < 0 || result_index >= memory_words.size())
        throw out_of_range("word index out of range");
    vector<uint> buffer_register = getWord(first_arg_index);
    for(int i = 0; i < buffer_register.size(); i++)
    {
        int second_arg_string_index = countDigitStringIndex(second_arg_index, i);
        int result_string_index = countDigitStringIndex(result_index, i);
    
        memory_words[result_string_index][result_index] = constZeroDigit(
            buffer_register[i], memory_words[second_arg_string_index][second_arg_index]);
    }
}

void DiagonalAM::constantOneLF(int first_arg_index, int second_arg_index, int result_index)
{
    if(second_arg_index < 0 || second_arg_index >= memory_words.size())
        throw out_of_range("word index out of range");
    if(result_index < 0 || result_index >= memory_words.size())
        throw out_of_range("word index out of range");
    vector<uint> buffer_register = getWord(first_arg_index);
    for(int i = 0; i < buffer_register.size(); i++)
    {
        int second_arg_string_index = countDigitStringIndex(second_arg_index, i);
        int result_string_index = countDigitStringIndex(result_index, i);

        memory_words[result_string_index][result_index] = constOneDigit(
            buffer_register[i], memory_words[second_arg_string_index][second_arg_index]);
    }
}

void DiagonalAM::repeatSecondArgumentLF(int first_arg_index, int second_arg_index, int result_index)
{
    if(second_arg_index < 0 || second_arg_index >= memory_words.size())
        throw out_of_range("word index out of range");
    if(result_index < 0 || result_index >= memory_words.size())
        throw out_of_range("word index out of range");
    vector<uint> buffer_register = getWord(first_arg_index);
    for(int i = 0; i < buffer_register.size(); i++)
    {
        int second_arg_string_index = countDigitStringIndex(second_arg_index, i);
        int result_string_index = countDigitStringIndex(result_index, i);
        
        memory_words[result_string_index][result_index] = repeatSecondDigit(
            buffer_register[i], memory_words[second_arg_string_index][second_arg_index]);
    }
}

void DiagonalAM::negateSecondArgumentLF(int first_arg_index, int second_arg_index, int result_index)
{
    if(second_arg_index < 0 || second_arg_index >= memory_words.size())
        throw out_of_range("word index out of range");
    if(result_index < 0 || result_index >= memory_words.size())
        throw out_of_range("word index out of range");
    vector<uint> buffer_register = getWord(first_arg_index);
    for(int i = 0; i < buffer_register.size(); i++)
    {
        int second_arg_string_index = countDigitStringIndex(second_arg_index, i);
        int result_string_index = countDigitStringIndex(result_index, i);
        memory_words[result_string_index][result_index] = negateSecondDigit(
            buffer_register[i], memory_words[second_arg_string_index][second_arg_index]);
    }
}

vector<uint> DiagonalAM::accordanceSearch(vector<uint> word_to_search)
{
    if(memory_words.empty())
        throw length_error("Can't do this operation for empty word matrix");
    if(word_to_search.size() != memory_words.size())
        throw length_error("Uncorrect word size");   
    int max_accordance_word_index = 0;
    int max_accordance_number = accordanceNumber(word_to_search, max_accordance_word_index);
    for(int i = 0; i < memory_words.size(); i++)
    {
        int current_accordance_number = accordanceNumber(word_to_search, i);
        if(current_accordance_number > max_accordance_number){
            max_accordance_word_index = i;
            max_accordance_number = accordanceNumber(word_to_search, max_accordance_word_index);
        }
        else if(max_accordance_number == current_accordance_number && firstIsGreater(i, max_accordance_word_index)){
            max_accordance_word_index = i;
            max_accordance_number = accordanceNumber(word_to_search, max_accordance_word_index);
        }
    }
    return getWord(max_accordance_word_index);
}

int DiagonalAM::makeAddition(std::vector<uint> word_to_search)
{
    int processed_words_amount = 0;
    if(word_to_search.size() != memory_words.size())
        throw length_error("Uncorrect word size");
    for(int i = 0; i < memory_words.size(); i++)
    {
        if(vPartsAreEquale(word_to_search, i))
        {
            std::cout << i << "\n";
            addOperation(i);
            processed_words_amount++;
        }
    }
    return processed_words_amount;
}

size_t DiagonalAM::size()
{
    return memory_words.size();
}

size_t DiagonalAM::size() const
{
    return memory_words.size();
}
