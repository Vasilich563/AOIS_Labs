//Author: Vodohleb04
#include <iostream>
#include <string>
#include <math.h>
#include "HashTable.h"


int main()
{
    //auto a = std::string("aboba");
    auto a = "aboba";
    std::cout << 10 % 5 << std::endl << 3 % 128 << std::endl;
    HashTable* b = new HashTable(a);
    delete b;
    return 0;
}
