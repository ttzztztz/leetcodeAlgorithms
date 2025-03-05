class RandomizedSet {
public:
    RandomizedSet() {
        gen = mt19937(rd());
    }
    
    bool insert(int val) {
        if (hmap.count(val)) return false;

        hmap[val] = data.size();
        data.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!hmap.count(val)) return false;

        const int prev_idx = hmap[val];
        const int last_val = data.back();
        swap(data[data.size() - 1], data[prev_idx]);
        hmap[last_val] = prev_idx;

        data.pop_back();
        hmap.erase(hmap.find(val));
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<int> d(0, data.size() - 1);
        return data[d(gen)];
    }
private:
    vector<int> data;
    unordered_map<int, int> hmap;

    random_device rd;
    mt19937 gen;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */