//Author: Vodohleb04
#include <iostream>
#include "associative_processor.h"

int main()
{
    //std::vector<MemoryWord> matrix = makeRandomMatrix(10);
    std::vector<MemoryWord> matrix = makeRandomMatrix(6);
    std::fstream logout;
    logout.open("log.txt", std::fstream::out);
    logout << "Matrix:\n" << matrix << std::endl;
    MemoryWord testword;
    logout << "\ntest_word:\t"<< testword << std::endl << std::endl;
    try
    {
        MemoryWord near_from_above = findNearFromAbove(matrix, testword);
        logout << "near_from_above:\t" << near_from_above << std::endl << std::endl;
    }
    catch(std::domain_error &ex)
    {
        logout << "Exception: " << ex.what() << std::endl;
    }
    try
    {
        MemoryWord near_from_below = findNearFromBelow(matrix, testword);
        logout << "near_from_below:\t" << near_from_below << std::endl << std::endl;
    }
    catch(std::domain_error &ex)
    {
        logout << "Exception: " << ex.what() << std::endl;
    }


    logout.close();
    return 0;
}