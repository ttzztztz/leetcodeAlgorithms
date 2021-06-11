class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = m.lower_bound(start);
        if (it != m.end() && it->first < end) { // ... start .. first ... end ... second
            return false;
        }
        if (it != m.begin()) {
            it--;// ... first .. start ... end ... second
            if (start < it->second) {
                return false;
            }
        }
        m[start] = end;
        return true;
    }
private:
    map<int, int> m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */