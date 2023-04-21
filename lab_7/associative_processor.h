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

std::ostream& operator<<(std::ostream& out, std::vector<MemoryWord> memory_words);

MemoryWord findNearFromBelow(std::vector<MemoryWord> memory_words, MemoryWord word_to_search);

std::vector<int> findLowerIndexes(std::vector<MemoryWord> memory_words, MemoryWord word_to_search);

MemoryWord findNearFromAbove(std::vector<MemoryWord> memory_words, MemoryWord word_to_search);

std::vector<int> findGreaterIndexes(std::vector<MemoryWord> memory_words, MemoryWord word_to_search);

MemoryWord findAccordence(std::vector<MemoryWord> memory_words, MemoryWord word_to_search);

#endif //!_ASSOCIATIVE_PROCESSOR_