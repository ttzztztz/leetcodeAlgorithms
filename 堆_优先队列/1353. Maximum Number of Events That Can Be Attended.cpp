class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int N = events.size();
        sort(events.begin(), events.end());
        int ptr = 0, answer = 0;
        priority_queue<int, vector<int>, greater<>> heap;
        
        int _max = -1, _min = 999999;
        for (const vector<int>& event : events) {
            _min = min(_min, event[0]);
            _max = max(_max, event[1]);
        }
        
        for (int i = _min; i <= _max; i++) {
            while (ptr < N && events[ptr][0] <= i) {
                heap.push(events[ptr][1]);
                ptr++;
            }
            while (!heap.empty() && heap.top() < i) {
                heap.pop();
            }
            
            if (!heap.empty()) {
                heap.pop();
                answer++;
            }
        }
        return answer;
    }
};
