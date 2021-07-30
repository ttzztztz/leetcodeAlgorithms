class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if (raw.count(key)) {
            inc(key, -raw[key]);
        }
        raw[key] = val;
        inc(key, raw[key]);
    }
    
    int sum(string prefix) {
        return cnt[prefix];
    }
private:
    unordered_map<string, int> raw;
    unordered_map<string, int> cnt;
    
    void inc(string key, int val) {
        while (!key.empty()) {
            cnt[key] += val;
            key.pop_back();
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
