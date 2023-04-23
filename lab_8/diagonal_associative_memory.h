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

void emplaceRandomWords(int memory_size);

std::vector<std::vector<unsigned int>> memory_words;

friend std::ostream& operator<<(std::ostream& out, const DiagonalAM& diagonal_am);

public:

DiagonalAM(int size = int(BASIC_MATRIX_SIZE));

DiagonalAM(const DiagonalAM& other);

DiagonalAM& operator=(const DiagonalAM& other);

std::vector<unsigned int> getMatrixString(int string_index);

std::vector<unsigned int> getWord(int word_index);

size_t size();

size_t size() const;
};



#endif //!_DIAGONAL_ASSOCIATIVE_MEMORY_