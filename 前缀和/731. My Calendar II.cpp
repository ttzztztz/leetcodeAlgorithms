class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        data[start]++, data[end]--;
        
        bool ok = true;
        int pref = 0;
        for (const auto& p : data) {
            pref += p.second;
            if (pref >= 3) {
                ok = false;
                break;
            }
        }
        
        if (!ok) {
            data[start]--, data[end]++;
        }
        
        return ok;
    }
private:
    map<int, int> data;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
