#include "HashTable.h"

using namespace std;


unsigned long HashTable::hashFunction(const char * str)
{
    unsigned long hash = 0;
    if (str)
    {
        hash = (unsigned long)(*str);
        std::cout<<hash<<'\t'<<*str<<'\t'<<(unsigned long)(*str)<<'\n';
        str++;
    }
    for(; *str; str++)
    {
        hash = hash * (unsigned long)HASH_FUNCTION_P + (unsigned long)(*str);
        std::cout<<hash<<'\t'<<*str<<'\t'<<(unsigned long)(*str)<<'\n';
    }
    hash %= (unsigned long)(HASH_FUNCTION_MOD);
    std::cout<<"#\t"<<hash<<"\t#\n";
    return hash;
}

unsigned long HashTable::hashFunction(string str)
{
    return this->hashFunction(str.c_str());
}

HashTable::HashTable(string expr)
{
}

HashTable::HashTable(const char* expr)
{
    this->hashFunction(expr);
}

HashTable::HashTableElement::HashTableElement(unsigned long hash_id, std::string key, std::string data)
{

}

HashTable::HashTableElement::HashTableElement(unsigned long hash_id, const char* key, const char* data)
{

}

HashTable::HashTableElement::HashTableElement(const HashTable::HashTableElement& other)
{

}

HashTable::HashTableElement& HashTable::HashTableElement::operator=(const HashTable::HashTableElement& other)
{

}

bool HashTable::HashTableElement::operator==(const HashTable::HashTableElement& other)
{

}

bool HashTable::HashTableElement::operator!=(const HashTable::HashTableElement& other)
{

}

std::string& HashTable::HashTableElement::getData()
{

}

std::string& HashTable::HashTableElement::getKey()
{

}

void HashTable::HashTableElement::setData(std::string new_data)
{

}

void HashTable::HashTableElement::setData(const char* new_data)
{

}

unsigned long HashTable::HashTableElement::getHashId()
{
    
}