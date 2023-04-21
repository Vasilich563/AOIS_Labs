//Author: Vodohleb04
#pragma once

#ifndef _ASSOCIATIVE_PROCESSOR_
#define _ASSOCIATIVE_PROCESSOR_

#include <memory_word.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>


//Returns matrix, filled with random numbers(min: 0, max: 1)
std::vector<MemoryWord> makeRandomMatrix(int strings_amount);

std::ostream& operator<<(std::ostream& out, std::vector<MemoryWord> word_matrix);

MemoryWord findNearFromBelow(std::vector<MemoryWord> word_matrix, MemoryWord word);

std::vector<int> findLowerIndexes(std::vector<MemoryWord> word_matrix, MemoryWord word);

MemoryWord findNearFromAbove(std::vector<MemoryWord> word_matrix, MemoryWord word);

std::vector<int> findGreaterIndexes(std::vector<MemoryWord> word_matrix, MemoryWord word);

#endif //!_ASSOCIATIVE_PROCESSOR_