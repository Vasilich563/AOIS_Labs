//Author: Vodohleb04
#pragma once

#ifndef _ASSOCIATIVE_PROCESSOR_
#define _ASSOCIATIVE_PROCESSOR_

#include <vector>
#include <fstream>
#include <stdexcept>


//Returns matrix, filled with random numbers(min: 0, max: 1)
std::vector<std::vector<int>> makeRandomMatrix(int strings_amount, int strings_length);

std::ostream& operator<<(std::ostream& out, std::vector<std::vector<int>> int_vector);

std::vector<int> findNearFromBelow(std::vector<std::vector<int>> int_matrix, std::vector<int> word);

std::vector<int> findLowerIndexes(std::vector<std::vector<int>> int_matrix, std::vector<int> word);

std::vector<int> findNearFromAbove(std::vector<std::vector<int>> int_matrix, std::vector<int> word);

std::vector<int> findGreaterIndexes(std::vector<std::vector<int>> int_matrix, std::vector<int> word);


#endif //!_ASSOCIATIVE_PROCESSOR_