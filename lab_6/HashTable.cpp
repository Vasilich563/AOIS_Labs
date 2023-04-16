#include "HashTable.h"

using namespace std;


std::ostream& operator<<(std::ostream& out, const HashTable& hash_table)
{
    for(int i = 0; i < hash_table.size(); i++)
    {
        if(hash_table.table[i].empty())
            continue;
        if(hash_table.collisionsAtIndex(i))
        {
            out << "Collision of elements with hash ";
            bool first_element_flag = true;
            for(auto element : hash_table.table[i])
            {
                if (first_element_flag){
                    first_element_flag = false;
                    out << element.getHash() << "\n";
                }
                out << "\tKey: " << element.getKey() << "\t data: " << element.getData() << "\n";
            }
        }
        else
            out << *(hash_table.table[i].begin()) << "\n";
    }
    return out;
}


HashTable::HashTableElement::HashTableElement()
{
    this->hash = -1;
    this->key = nullptr;
    this->data = nullptr;
}

HashTable::HashTableElement::HashTableElement(unsigned long hash, std::string key, std::string data)
{
    this->hash = hash;
    this->key = key;
    this->data = data;
}

HashTable::HashTableElement::HashTableElement(const HashTable::HashTableElement& other)
{
    this->hash = other.hash;
    this->key = other.key;
    this->data = other.data;
}

HashTable::HashTableElement& HashTable::HashTableElement::operator=(const HashTable::HashTableElement& other)
{
    this->hash = other.hash;
    this->key = other.key;
    this->data = other.data;
    return *this;
}

bool HashTable::HashTableElement::operator==(const HashTable::HashTableElement& other)
{
    return this->hash == other.hash;
}

bool HashTable::HashTableElement::operator!=(const HashTable::HashTableElement& other)
{
    return this->hash != other.hash;
}

std::string& HashTable::HashTableElement::getData()
{
    if (empty())
    {
        throw domain_error("Invelid element");
    }
    return this->data;
}

std::string& HashTable::HashTableElement::getKey()
{
    if (empty())
    {
        throw domain_error("Invelid element");
    }
    return this->key;
}

void HashTable::HashTableElement::setData(std::string data)
{
    if (empty())
    {
        throw domain_error("Invelid element");
    }
    this->data = data;
}

void HashTable::HashTableElement::setData(const char* data)
{
    if (empty())
    {
        throw domain_error("Invelid element");
    }
    this->data = string(data);
}

unsigned long HashTable::HashTableElement::getHash()
{
    if (empty())
    {
        throw domain_error("Invelid element");
    }
    return this->hash;
}

bool HashTable::HashTableElement::empty()
{
    return this->hash == -1;
}

size_t HashTable::countUsedIndexes()
{
    size_t used_counter = 0;
    for (auto elements_chain : table)
    {
        if(!elements_chain.empty())
        {
            used_counter++;
        }
    }
    return used_counter;
}

void HashTable::emplaceElementIntoTable(HashTableElement new_element)
{
    bool rehashSizeFlag = (countUsedIndexes() / size()) >= double(REHASH_SIZE_COEFFICIENT);
    bool rehashAmountFlag = (elements_amount / size()) >= double(REHASH_ELEMENTS_AMOUNT_COEFFICIENT);
    if(rehashSizeFlag || rehashAmountFlag)
    {
        rehashTable();
    }
    int id = new_element.getHash() % size();
    table[id].push_front(new_element);
    elements_amount++;
}

void HashTable::rehashTable()
{
    auto buffer = this->table;
    table = vector<forward_list<HashTableElement>>(buffer.size() * 2);
    elements_amount = 0;
    for(auto elements_chain : buffer)
    {
        for(auto element : elements_chain)
        {
            if(!element.empty())
            {
                emplaceElementIntoTable(element);
            }
        }
    }
    buffer.clear();
}

unsigned long HashTable::hashFunction(const char * key)
{
    unsigned long hash = 0;
    for(; *key; key++)
    {
        hash = (hash * (unsigned long)HASH_FUNCTION_P + (unsigned long)(*key))%(unsigned long)(HASH_FUNCTION_MOD);
    }
    std::cout<<"#\t"<<hash<<"\t#\n";
    return hash;
}

unsigned long HashTable::hashFunction(string key)
{
    return this->hashFunction(key.c_str());
}

HashTable::HashTable()
{
    table = vector<forward_list<HashTableElement>>(int(BASIC_TABLE_SIZE));
}

HashTable::HashTable(const HashTable& other)
{
    this->table = other.table;
    this->elements_amount = other.elements_amount;
}

HashTable& HashTable::operator=(const HashTable& other)
{
    this->table = other.table;
    this->elements_amount = other.elements_amount;
    return *this;
}

size_t HashTable::size()
{
    return table.size();
}

size_t HashTable::size() const
{
    return table.size();
}

size_t HashTable::elementsAmount()
{
    return elements_amount;
}

size_t HashTable::elementsAmount() const
{
    return elements_amount;
}

bool HashTable::collisionsAtIndex(int index)
{
    if(index < 0 || index >= size())
    {
        throw out_of_range("Index out of range");
    }
    size_t counter = 0;
    for(auto element : table[index])
    {
        counter++;
    }
    return counter > 1;
}

bool HashTable::collisionsAtIndex(int index) const
{
    if(index < 0 || index >= size())
    {
        throw out_of_range("Index out of range");
    }
    size_t counter = 0;
    for(auto element : table[index])
    {
        counter++;
    }
    return counter > 1;
}

void HashTable::addElement(const char* key, const char* value)
{
    emplaceElementIntoTable(
        HashTableElement(
            hashFunction(key),
            string(key),
            string(value)
        )
    );
}

void HashTable::addElement(const char* key, std::string value)
{
    emplaceElementIntoTable(
        HashTableElement(
            hashFunction(key),
            string(key),
            value
        )
    );
}

void HashTable::addElement(std::string key, const char* value)
{
    emplaceElementIntoTable(
        HashTableElement(
            hashFunction(key),
            key,
            string(value)
        )
    );
}

void HashTable::addElement(std::string key, std::string value)
{
    emplaceElementIntoTable(
        HashTableElement(
            hashFunction(key),
            key,
            value
        )
    );
}