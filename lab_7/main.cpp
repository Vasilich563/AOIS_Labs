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
    std::vector<MemoryWord> memory_words = makeRandomMatrix(16);
    std::fstream logout;
    logout.open("log_task1.txt", std::fstream::out);
    logout << "Matrix:\n" << memory_words << std::endl;
    MemoryWord task1_word;
    logout << "\ntest_word:\t"<< task1_word << std::endl << std::endl;
    try{
        logout << "greater indexes:\t" << findGreaterIndexes(memory_words, task1_word) << std::endl;
        MemoryWord near_from_above = findNearFromAbove(memory_words, task1_word);
        logout << "near_from_above:\t" << near_from_above << std::endl << std::endl;
    }
    catch(std::domain_error &ex){
        logout << "Exception: " << ex.what() << std::endl;
    }
    try{
        logout << "lower indexes:\t" << findLowerIndexes(memory_words, task1_word) << std::endl;
        MemoryWord near_from_below = findNearFromBelow(memory_words, task1_word);
        logout << "near_from_below:\t" << near_from_below << std::endl << std::endl;
    }
    catch(std::domain_error &ex){
        logout << "Exception: " << ex.what() << std::endl;
    }
    logout.close();
}

void task_2()
{
    std::vector<MemoryWord> memory_words = makeRandomMatrix(16);
    std::fstream logout;
    logout.open("log_task2.txt", std::fstream::out);
    logout << "Matrix:\n" << memory_words << std::endl;

    MemoryWord task2_word;
    logout << "\ntest_word:\t"<< task2_word << std::endl << std::endl;

    logout << "Accordance result:\t" << findAccordence(memory_words, task2_word) << std::endl;

    logout.close();
}


int main()
{
    task_1();
    task_2();
    return 0;
}