class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) all.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (all.empty()) return -1;
        const int t = *all.begin();
        all.erase(all.begin());
        return t;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return all.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        all.insert(number);
    }
private:
    set<int> all;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
