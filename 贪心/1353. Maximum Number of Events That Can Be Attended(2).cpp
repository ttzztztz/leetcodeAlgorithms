class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int ans = 0;
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> heap;
        
        for (int i = 0; i < events.size(); i++) {
            int start = events[i][0], end = events[i][1];
            int nxt = numeric_limits<int>::max();
            if (i + 1 < events.size()) nxt = events[i + 1][0];

            while (!heap.empty() && heap.top() < start) heap.pop();
            heap.push(end);

            while (!heap.empty() && start < nxt) {
                if (start <= heap.top()) {
                    start++;
                    ans++;
                }

                heap.pop();
            }
        }
        return ans;
    }
};
