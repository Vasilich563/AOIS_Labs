#pragma once

#ifndef _HASH_TABLE_
#define _HASH_TABLE_
#define HASH_FUNCTION_P 129
#define HASH_FUNCTION_MOD 9.22337e+18

#include <vector>
#include <forward_list>
#include <string>
#include <iostream>

class HashTable
{
private:

    unsigned long hashFunction(std::string str);
    unsigned long hashFunction(const char* str);

public:

    HashTable(std::string expr);
    HashTable(const char* expr);
};

#endif //!_HASH_TABLE_