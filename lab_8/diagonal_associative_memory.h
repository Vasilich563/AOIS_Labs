 //Author: Vodohleb04
#pragma once

#ifndef _DIAGONAL_ASSOCIATIVE_MEMORY_
#define _DIAGONAL_ASSOCIATIVE_MEMORY_

#include <vector>
#include <fstream>
#include <stdexcept>
#include <math.h>
#define BASIC_MATRIX_SIZE 16

class DiagonalAM;

std::ostream& operator<<(std::ostream& out, const DiagonalAM& diagonal_am);

class DiagonalAM
{
private:

    int countDigitStringIndex(int word_index, int digit_position);

    void emplaceRandomWords(int memory_size);

    uint constZeroDigit(uint first_word_digit, uint second_word_digit);

    uint constOneDigit(uint first_word_digit, uint second_word_digit);

    uint repeatSecondDigit(uint first_word_digit, uint second_word_digit);

    uint negateSecondDigit(uint first_word_digit, uint second_word_digit);

    static uint current_g(uint previous_g, uint previous_l, uint this_word_digit, uint other_word_digit);

    static uint current_l(uint previous_l, uint previous_g, uint this_word_digit, uint other_word_digit);

    bool firstIsGreater(int first_word_index, int second_word_index);

    bool firstIsLower(int first_word_index, int second_word_index);

    bool areEquale(int first_word_index, int second_word_index);

    int accordanceNumber(std::vector<uint> word_to_compare, int memory_word_index);

    bool vPartsAreEquale(std::vector<uint> word_to_compare, int memory_word_index);

    int vPartSize();

    int aPartSize();

    int bPartSize();

    int sPartSize();

    uint getADigit(int memory_word_index, int ab_shift);

    uint getBDigit(int memory_word_index, int ab_shift);

    uint countSDigit(uint a_digit, uint b_digit, uint transfer_digit);

    uint countTransferDigit(uint a_digit, uint b_digit, uint transfer_digit);

    void addOperation(int memory_word_index);

    std::vector<std::vector<uint>> memory_words;

    friend std::ostream& operator<<(std::ostream& out, const DiagonalAM& diagonal_am);

public:

    DiagonalAM(int size = int(BASIC_MATRIX_SIZE));

    DiagonalAM(const DiagonalAM& other);

    DiagonalAM& operator=(const DiagonalAM& other);

    std::vector<uint> getMatrixString(int string_index);

    std::vector<uint> getWord(int word_index);

    void insertWord(std::vector<uint> word_to_insert, int word_index);

    void constantZeroLF(int first_arg_index, int second_arg_index, int result_index);

    void constantOneLF(int first_arg_index, int second_arg_index, int result_index);

    void repeatSecondArgumentLF(int first_arg_index, int second_arg_index, int result_index);

    void negateSecondArgumentLF(int first_arg_index, int second_arg_index, int result_index);

    std::vector<uint> accordanceSearch(std::vector<uint> word_to_search);

    int makeAddition(std::vector<uint> word_to_search);

    size_t size();

    size_t size() const;
};



#endif //!_DIAGONAL_ASSOCIATIVE_MEMORY_