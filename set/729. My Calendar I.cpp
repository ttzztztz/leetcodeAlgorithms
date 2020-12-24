class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        end--;
        if (intervals.empty()) {
            intervals.emplace(start, end);
            return true;
        }
        
        auto it = intervals.upper_bound({start, end});
        if (it != intervals.begin()) --it;
        while (it != intervals.end()) {
            if (max(start, it->first) <= min(end, it->second)) return false;
            it++;
        }
        intervals.emplace(start, end);
        return true;
    }
private:
    set<pair<int, int>> intervals;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */