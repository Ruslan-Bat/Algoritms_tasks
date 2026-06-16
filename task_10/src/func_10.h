#include <vector>
#include <list>

class hash_table{
private:
    int num_elements;
    std::vector<std::list<std::pair<int, int>>> buckets;

    int get_index_bucket(const int key) const{
        return std::hash<int>{}(key) % buckets.size();
    }

public:
    hash_table(int size = 10) : buckets(size), num_elements(0) {}

    void Insert(int key, int value);
    int Get(int key);
    void Remove(int key);
    bool Contains(int key);
};