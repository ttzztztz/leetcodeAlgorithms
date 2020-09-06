class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        data[start]++;
        data[end]--;
        
        int answer = 0, cur = 0;
        for (auto& p : data) {
            cur += p.second;
            answer = max(answer, cur);
        }
        return answer;
    }
private:
    map<int, int> data;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
