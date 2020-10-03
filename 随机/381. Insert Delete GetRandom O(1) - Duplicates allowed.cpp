class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ans = h.count(val);
        data.push_back(val);
        h[val].insert(data.size() - 1);
        return !ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool ans = h.count(val);
        
        if (ans) {
            const int last_idx = data.size() - 1;
            const int last_key = data[last_idx];
            
            if (last_key == val) {
                data.pop_back();
                h[val].erase(last_idx);
            } else {
                const int idx = *(h[val].begin());
                h[last_key].erase(last_idx);
                h[val].erase(idx);
                h[last_key].insert(idx);
                
                swap(data[idx], data[last_idx]);
                data.pop_back();
            }
            
            if (h[val].empty()) h.erase(val);
        }
        return ans;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        const int n = data.size() - 1;
        mt19937 rd{ random_device{}() };
        uniform_int_distribution<int> d(0, n);
        
        const int idx = d(rd);
        return data[idx];
    }
private:
    vector<int> data;
    unordered_map<int, unordered_set<int>> h;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
