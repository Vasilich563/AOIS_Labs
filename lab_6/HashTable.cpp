#include "HashTable.h"

using namespace std;


unsigned long HashTable::hashFunction(const char * str)
{
    unsigned long hash = 0;
    if (str)
    {
        hash = (unsigned long)(*str);
        std::cout<<hash<<"\t"<<*str<<"\t"<<(unsigned long)(*str)<<"\n";
        str++;
    }
    for(; *str; str++)
    {
        hash = hash * (unsigned long)HASH_FUNCTION_P + (unsigned long)(*str);
        std::cout<<hash<<"\t"<<*str<<"\t"<<(unsigned long)(*str)<<"\n";
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
    /*
    auto data1 = HashTableElement(this->hashFunction(expr), expr, "data1");
    auto data2 = HashTableElement(this->hashFunction(expr), string(expr), "data2");
    auto expr1 = "abema";
    auto data3 = HashTableElement(this->hashFunction(expr1), expr1, "data3");
    auto data4 = HashTableElement(this->hashFunction(expr1), string(expr1), "data4");
    std::cout<<"data1.getData()"<<std::endl;
    std::cout<<data1.getData()<<std::endl;
    std::cout<<"data2.getData"<<std::endl;
    std::cout<<data2.getData()<<std::endl;
    std::cout<<"data3.getData"<<std::endl;
    std::cout<<data3.getData()<<std::endl;
    std::cout<<"data4.getData"<<std::endl;
    std::cout<<data4.getData()<<std::endl;
    std::cout<<"data1.getHashId"<<std::endl;
    std::cout<<data1.getHashId()<<std::endl;
    std::cout<<"data2.getHashId"<<std::endl;
    std::cout<<data2.getHashId()<<std::endl;
    std::cout<<"data3.getHashId"<<std::endl;
    std::cout<<data3.getHashId()<<std::endl;
    std::cout<<"data4.getHashId"<<std::endl;
    std::cout<<data4.getHashId()<<std::endl;
    std::cout<<"data1.getKey"<<std::endl;
    std::cout<<data1.getKey()<<std::endl;
    std::cout<<"data2.getKey"<<std::endl;
    std::cout<<data2.getKey()<<std::endl;
    std::cout<<"data3.getKey"<<std::endl;
    std::cout<<data3.getKey()<<std::endl;
    std::cout<<"data4.getKey"<<std::endl;
    std::cout<<data4.getKey()<<std::endl;
    std::cout<<"data1 == data1"<<std::endl;
    std::cout<<(data1 == data1)<<std::endl;
    std::cout<<"data1 == data2"<<std::endl;
    std::cout<<(data1 == data2)<<std::endl;
    std::cout<<"data3 == data1"<<std::endl;
    std::cout<<(data3 == data1)<<std::endl;
    std::cout<<"data3 == data4"<<std::endl;
    std::cout<<(data3 == data4)<<std::endl;
    std::cout<<"data1 != data1"<<std::endl;
    std::cout<<(data1 != data1)<<std::endl;
    std::cout<<"data1 != data2"<<std::endl;
    std::cout<<(data1 != data2)<<std::endl;
    std::cout<<"data3 != data1"<<std::endl;
    std::cout<<(data3 != data1)<<std::endl;
    std::cout<<"data3 != data4"<<std::endl;
    std::cout<<(data3 != data4)<<std::endl;
    data1.setData("abema");
    std::cout<<"data1.setData(abema)"<<std::endl;
    std::cout<<data1.getData()<<std::endl;
    data1.setData(string("abema blyat"));
    std::cout<<"data1.setData(abema blyat)"<<std::endl;
    std::cout<<data1.getData()<<std::endl;
    std::cout<<"data2 = data1;"<<std::endl;
    data3 = data1;
    std::cout<<"data1.getData"<<std::endl;
    std::cout<<data1.getData()<<std::endl;
    std::cout<<"data2.getData"<<std::endl;
    std::cout<<data3.getData()<<std::endl;
    std::cout<<"data1.getHashId"<<std::endl;
    std::cout<<data1.getHashId()<<std::endl;
    std::cout<<"data2.getHashId"<<std::endl;
    std::cout<<data3.getHashId()<<std::endl;
    std::cout<<"data1.getKey"<<std::endl;
    std::cout<<data1.getKey()<<std::endl;
    std::cout<<"data2.getKey"<<std::endl;
    std::cout<<data3.getKey()<<std::endl;*/
}

HashTable::HashTableElement::HashTableElement(unsigned long hash_id, std::string key, std::string data)
{
    this->hash_id = hash_id;
    this->key = key;
    this->data = data;
}

HashTable::HashTableElement::HashTableElement(unsigned long hash_id, const char* key, const char* data)
{
    this->hash_id = hash_id;
    this->key = string(key);
    this->data = string(data);
}

HashTable::HashTableElement::HashTableElement(const HashTable::HashTableElement& other)
{
    this->hash_id = other.hash_id;
    this->key = other.key;
    this->data = other.data;
}

HashTable::HashTableElement& HashTable::HashTableElement::operator=(const HashTable::HashTableElement& other)
{
    this->hash_id = other.hash_id;
    this->key = other.key;
    this->data = other.data;
    return *this;
}

bool HashTable::HashTableElement::operator==(const HashTable::HashTableElement& other)
{
    return this->hash_id == other.hash_id;
}

bool HashTable::HashTableElement::operator!=(const HashTable::HashTableElement& other)
{
    return this->hash_id != other.hash_id;
}

std::string& HashTable::HashTableElement::getData()
{
    return this->data;
}

std::string& HashTable::HashTableElement::getKey()
{
    return this->key;
}

void HashTable::HashTableElement::setData(std::string data)
{
    this->data = data;
}

void HashTable::HashTableElement::setData(const char* data)
{
    this->data = string(data);
}

unsigned long HashTable::HashTableElement::getHashId()
{
    return this->hash_id;
}