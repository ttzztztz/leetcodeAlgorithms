class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) {
            all.push_back(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (all.empty()) return -1;
        const int t = *all.begin();
        all.pop_front();
        used.insert(t);
        return t;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !used.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (used.count(number)) {
            used.erase(number);
            all.push_back(number);
        }
    }
private:
    unordered_set<int> used;
    list<int> all;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
