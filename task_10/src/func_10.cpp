#include <stdexcept>
#include <vector>
#include <list>

#include "func_10.h"


void hash_table::Insert(int key, int value) {
    int index = get_index_bucket(key);
    
    for (std::pair<int,int>& pair : buckets[index]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    buckets[index].emplace_back(key, value);
    num_elements++;
}

int hash_table::Get(int key) {
    int index = get_index_bucket(key);
    
    for (std::pair<int,int>& pair : buckets[index]) {
        if (pair.first == key) {
            return pair.second; 
        }
    }
    throw std::out_of_range("Ключа нет");
}

void hash_table::Remove(int key) {
    int index = get_index_bucket(key);
    
    std::list<std::pair<int, int>>& chain = buckets[index];
    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->first == key) {
            chain.erase(it);
            num_elements--;
            return;
        }
    }
}

bool hash_table::Contains(int key) {
    int index = get_index_bucket(key);
    
    for (std::pair<int,int>& pair : buckets[index]) {
        if (pair.first == key) {
            return true;
        }
    }
    return false;
}