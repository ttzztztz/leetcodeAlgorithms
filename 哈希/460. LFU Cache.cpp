#include <list>

class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity) {}
    int get(int key) {
        if (cap == 0) return -1;
        // cout << "get " << key << endl;
        if (kv.count(key)) {
            auto& val = kv[key];
            freq_map[val.freq].erase(val.it);
            freq_map[val.freq + 1].push_back(key);
            val.it = --freq_map[val.freq + 1].end();
            if (val.freq == min_freq && freq_map[val.freq].empty()) {
                min_freq++;
            }
            val.freq++;
            return val.data;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        // cout << "put " << key << ", " << value << endl;
        if (kv.count(key)) {
            auto& val = kv[key];
            freq_map[val.freq].erase(val.it);
            freq_map[val.freq + 1].push_back(key);
            val.it = --freq_map[val.freq + 1].end();
            if (val.freq == min_freq && freq_map[val.freq].empty()) {
                min_freq++;
            }
            val.freq++;
            val.data = value;
        } else {
            if (kv.size() == cap) {
                int clean_key = freq_map[min_freq].front();
                kv.erase(clean_key);
                freq_map[min_freq].pop_front();
            }

            Value val(value);
            freq_map[val.freq].push_back(key);
            val.it = --freq_map[val.freq].end();
            kv[key] = val;
            min_freq = 1;
        }
    }
private:
    class Value {
    public:
        int data, freq;
        list<int>::iterator it;
        
        Value() : data(0), freq(1) {};
        Value(int d) : data(d), freq(1) {};
    };

    unordered_map<int, list<int>> freq_map;
    unordered_map<int, Value> kv;
    int min_freq = 1;
    int cap;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */