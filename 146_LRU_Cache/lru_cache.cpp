#include <unordered_map>
#include <list>
#include <iostream>

class LRUCache {
public:
    explicit LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        if (data.count(key) == 0) {
            return -1;
        }

        auto& val = data[key];
        access_seq.splice(access_seq.cbegin(), access_seq, val);
        return val->second;
    }

    void put(int key, int value) {
        auto itr = data.find(key);
        if (itr != data.end()) {
            access_seq.splice(access_seq.cbegin(), access_seq, itr->second);
            auto& item = access_seq.front();
            item.second = value;
        } else if (data.size() >= capacity_) {
            auto lru_item = access_seq.back();
            access_seq.pop_back();
            data.erase(lru_item.first);

            access_seq.emplace_front(key, value);
            data[key] = access_seq.begin();
        } else {
            // new key will be appended
            access_seq.emplace_front(key,value);
            data[key] = access_seq.begin();
        }
    }

private:
    int capacity_;
    std::list<std::pair<int, int>> access_seq;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> data;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache lru_cache(2);

    std::cout << lru_cache.get(2) << std::endl;
    lru_cache.put(2, 6);
    std::cout << lru_cache.get(1) << std::endl;
    lru_cache.put(1, 5);
    lru_cache.put(1, 2);
    std::cout << lru_cache.get(1) << std::endl;
    std::cout << lru_cache.get(2) << std::endl;

    return 0;
}