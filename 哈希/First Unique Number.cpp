class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int i : nums) add(i);
    }
    
    int showFirstUnique() {
        while (!q.empty() && used.count(q.front())) q.pop_front();
        if (q.empty()) return -1;
        else return q.front();
    }
    
    void add(int value) {
        if (used.count(value)) return;
        if (once.count(value)) {
            once.erase(value);
            used.insert(value);
            return;
        }
        q.push_back(value);
        once.insert(value);
    }
private:
    unordered_set<int> used, once;
    deque<int> q;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
