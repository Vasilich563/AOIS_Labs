//Author: Vodohleb04
#include <iostream>
#include "associative_processor.h"


std::ostream& operator<<(std::ostream& out, const std::vector<int> int_vector)
{
    out << "{";
    for(int i = 0; i < int_vector.size(); i++)
    {
        out << int_vector[i];
        if(i != int_vector.size() - 1)
        {
            out << ", ";
        }
    }
    out << "}";
    return out;
}


void task_1()
{
    std::vector<MemoryWord> matrix = makeRandomMatrix(10);
    std::fstream logout;
    logout.open("log_task1.txt", std::fstream::out);
    logout << "Matrix:\n" << matrix << std::endl;
    MemoryWord testword;
    logout << "\ntest_word:\t"<< testword << std::endl << std::endl;
    try{
        logout << "greater indexes:\t" << findGreaterIndexes(matrix, testword) << std::endl;
        MemoryWord near_from_above = findNearFromAbove(matrix, testword);
        logout << "near_from_above:\t" << near_from_above << std::endl << std::endl;
    }
    catch(std::domain_error &ex){
        logout << "Exception: " << ex.what() << std::endl;
    }
    try{
        logout << "lower indexes:\t" << findLowerIndexes(matrix, testword) << std::endl;
        MemoryWord near_from_below = findNearFromBelow(matrix, testword);
        logout << "near_from_below:\t" << near_from_below << std::endl << std::endl;
    }
    catch(std::domain_error &ex){
        logout << "Exception: " << ex.what() << std::endl;
    }
    logout.close();
}


int main()
{
    task_1();
    return 0;
}