class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!data.count(key)) return -1;

        auto [val, it] = data[key];
        time.erase(it);
        time.push_front(key);
        data[key] = { val, time.begin() };
        return val;
    }
    
    void put(int key, int value) {
        const int old_val = get(key);
        if (data.count(key)) {
            data[key] = { value, time.begin() };
            return;
        }

        if (time.size() >= capacity) {
            const int removed_key = time.back();
            time.pop_back();
            data.erase(data.find(removed_key));
        }
        time.push_front(key);
        data[key] = { value, time.begin() };
    }
private:
    int capacity;
    list<int> time;
    unordered_map<int, pair<int, list<int>::iterator>> data;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */