 //Author: Vodohleb04
#pragma once

#ifndef _DIAGONAL_ASSOCIATIVE_MEMORY_
#define _DIAGONAL_ASSOCIATIVE_MEMORY_

#include <vector>
#include <fstream>
#include <stdexcept>
#define BASIC_MATRIX_SIZE 16

class DiagonalAM;

std::ostream& operator<<(std::ostream& out, const DiagonalAM& diagonal_am);

class DiagonalAM
{
private:

    int countDigitIndex(int word_index, int digit_position);

    void emplaceRandomWords(int memory_size);

    unsigned int constZeroDigit(unsigned int first_word_digit, unsigned int second_word_digit);

    unsigned int constOneDigit(unsigned int first_word_digit, unsigned int second_word_digit);

    unsigned int repeatSecondDigit(unsigned int first_word_digit, unsigned int second_word_digit);

    unsigned int negateSecondDigit(unsigned int first_word_digit, unsigned int second_word_digit);

    static unsigned int current_g(unsigned int previous_g, unsigned int previous_l,
                                  unsigned int this_word_digit, unsigned int other_word_digit);

    static unsigned int current_l(unsigned int previous_l, unsigned int previous_g,
                                  unsigned int this_word_digit, unsigned int other_word_digit);

    bool firstIsGreater(int first_word_index, int second_word_index);

    bool firstIsLower(int first_word_index, int second_word_index);

    bool areEquale(int first_word_index, int second_word_index);

    int accordanceNumber(std::vector<unsigned int> word_to_compare, int memory_word_index);

    std::vector<std::vector<unsigned int>> memory_words;

    friend std::ostream& operator<<(std::ostream& out, const DiagonalAM& diagonal_am);

public:

    DiagonalAM(int size = int(BASIC_MATRIX_SIZE));

    DiagonalAM(const DiagonalAM& other);

    DiagonalAM& operator=(const DiagonalAM& other);

    std::vector<unsigned int> getMatrixString(int string_index);

    std::vector<unsigned int> getWord(int word_index);

    void insertWord(std::vector<unsigned int> word_to_insert, int word_index);

    void constantZeroLF(int first_arg_index, int second_arg_index, int result_index);

    void constantOneLF(int first_arg_index, int second_arg_index, int result_index);

    void repeatSecondArgumentLF(int first_arg_index, int second_arg_index, int result_index);

    void negateSecondArgumentLF(int first_arg_index, int second_arg_index, int result_index);

    std::vector<unsigned int> accordanceSearch(std::vector<unsigned int> word_to_search);

    size_t size();

    size_t size() const;
};



#endif //!_DIAGONAL_ASSOCIATIVE_MEMORY_