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
                out << element;  // For logout
                //out << "\tKey: " << element.getKey() << "\t data: " << element.getData() << "\n";
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
    logout << "elements_amount: " << elements_amount << "\tcountUsedIndexes: " << countUsedIndexes() << "\n";
    bool rehashSizeFlag = (countUsedIndexes() / size()) >= double(REHASH_SIZE_COEFFICIENT);
    bool rehashAmountFlag = (elements_amount / size()) >= double(REHASH_ELEMENTS_AMOUNT_COEFFICIENT);
    logout << "rehashSizeFlag " << rehashSizeFlag << (countUsedIndexes() / size()) << endl;
    logout << "rehashAmountFlag " << rehashAmountFlag << (elements_amount / size()) << endl;
    if(rehashSizeFlag || rehashAmountFlag)
    {
        rehashTable();
    }
    int id = new_element.getHash() % size();
    logout << new_element << "\tId: " << id << endl << "\tSize: "<< size() << endl;
    table[id].push_front(new_element);
    logout << "\n#\nId: " << id << endl << "\t Elements:" << endl;
    for(auto el : table[id])
    {
        logout << el << "\t";
    }
    logout << "#" << endl;
    elements_amount++;
}

void HashTable::rehashTable()
{
    logout << "rehash()" << endl;
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
    logout << *this << endl;
    buffer.clear();
}

unsigned long HashTable::hashFunction(const char * key)
{
    unsigned long hash = 0;
    for(; *key; key++)
    {
        hash = (hash * (unsigned long)HASH_FUNCTION_P + (unsigned long)(*key))%(unsigned long)(HASH_FUNCTION_MOD);
    }
    logout << "Key: " << key << "\t" << "Hash: " << hash << endl;
    return hash;
}

unsigned long HashTable::hashFunction(string key)
{
    logout << "key: " << key << '\t' << "key.c_str: " << key.c_str() << endl;
    return this->hashFunction(key.c_str());
}

HashTable::HashTable()
{
    table = vector<forward_list<HashTableElement>>(int(BASIC_TABLE_SIZE));
    logout.open("log.txt");
    if (!logout.is_open())
    {
        cout<<"Not open"<<endl;
        throw exception();
    }
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
    logout << "addElement()" <<endl;
    emplaceElementIntoTable(
        HashTableElement(
            hashFunction(key),
            key,
            value
        )
    );
}

void HashTable::removeElement(const char* key)
{
    // TODO
}

void HashTable::removeElement(string key)
{
    removeElement(key.c_str());
}

HashTable::HashTableElement& HashTable::findElement(const char* key)
{
    // TODO
    unsigned long index_to_find = hashFunction(key) % size();
    if(!table[index_to_find].empty())
    {
        if(collisionsAtIndex(index_to_find))
        {
            for (auto element : table[index_to_find])
            {
                // TODO Сравнить элементы
            }
        }
        else
        {
            return *(table[index_to_find].begin());
        }
    }
    // TODO throw exception
}

HashTable::HashTableElement& HashTable::findElement(string key)
{
    findElement(key.c_str());
}
