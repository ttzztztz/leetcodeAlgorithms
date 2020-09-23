#include <list>

class LFUCache {
public:
    LFUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if (cap == 0 || !storage.count(key)) return -1;
        int val, freq;
        list<int>::iterator it;

        return _get(key);
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        
        if (storage.count(key)) { // exist
            int val, freq;
            list<int>::iterator it;
            _get(key);
            
            tie(val, freq, it) = storage[key];
            storage[key] = {value, freq, it};
        } else { // not exist
            if (storage.size() + 1 > cap) {
                clean();
            }
            
            if (2 >= freq_collection.size()) freq_collection.resize(2);
            freq_collection[1].push_back(key);
            auto new_it = --freq_collection[1].end();
            
            storage[key] = { value, 1, new_it };
            min_freq = 1;
        }
    }
private:
    typedef tuple<int, int, list<int>::iterator> Data;
    unordered_map<int, Data> storage;
    vector<list<int>> freq_collection;
    int min_freq = numeric_limits<int>::max();
    int cap;
    
    int _get(int key) {
        int val, freq;
        list<int>::iterator it;

        tie(val, freq, it) = storage[key];
        freq_collection[freq].erase(it);
        if (freq + 1 >= freq_collection.size()) freq_collection.resize(freq + 2);
        freq_collection[freq + 1].push_back(key);
        auto new_it = --freq_collection[freq + 1].end();
        storage[key] = { val, freq + 1, new_it };
        
        if (min_freq == freq && freq_collection[min_freq].empty()) {
            min_freq = freq + 1;
        } 
        
        return val;
    }
    
    void clean() {
        auto& v = freq_collection[min_freq];
        auto remove_it = freq_collection[min_freq].begin();
        const int key = *remove_it;
            
        v.erase(remove_it);
        storage.erase(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
