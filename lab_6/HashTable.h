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

    class HashTableElement
    {
    private:

        unsigned long hash_id;

        std::string data;

        std::string key;

    public:

        HashTableElement(unsigned long hash_id, std::string key, std::string data);

        HashTableElement(unsigned long hash_id, const char* key, const char* data);

        HashTableElement(const HashTableElement& other);

        HashTableElement& operator= (const HashTableElement& other);

        bool operator== (const HashTableElement& other);

        bool operator != (const HashTableElement& other);

        std::string& getData();

        void setData(std::string new_data);

        void setData(const char* data);

        std::string& getKey();

        unsigned long getHashId();

    };

    unsigned long hashFunction(std::string str);
    unsigned long hashFunction(const char* str);

public:

    HashTable(std::string expr);
    HashTable(const char* expr);
};

#endif //!_HASH_TABLE_