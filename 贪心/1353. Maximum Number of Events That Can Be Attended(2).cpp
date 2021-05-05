class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int n = events.size();
        
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<>> heap;
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = events[i][0], r = events[i][1];
            while (!heap.empty() && heap.top() < l) heap.pop();
            heap.push(r);
            
            int next = 1000000;
            if (i + 1 < n) next = events[i + 1][0];
            
            while (l < next && !heap.empty()) {
                const int t = heap.top();
                heap.pop();
                
                if (l <= t) ans++, l++; // 易错
            }
        }
        return ans;
    }
};