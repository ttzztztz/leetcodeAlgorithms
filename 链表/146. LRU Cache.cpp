class LRUCache {
public:
    int capacity, size;
    list<int> keyList;
    unordered_map<int, pair<std::list<int>::iterator, int>> kvMap;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }

    int get(int key) {
        if (kvMap.count(key)) {
            auto it = kvMap[key].first;
            keyList.erase(it);
            keyList.push_front(key);

            kvMap[key].first = keyList.begin();
            return kvMap[key].second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        int previousValue = get(key);
        if (previousValue == -1) {
            size++;

            if (size > capacity) {
                int oldKey = keyList.back();
                keyList.pop_back();
                kvMap.erase(oldKey);
                size--;
            }

            keyList.push_front(key);
        }

        kvMap[key] = std::make_pair(keyList.begin(), value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */