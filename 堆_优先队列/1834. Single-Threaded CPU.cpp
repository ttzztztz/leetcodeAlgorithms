class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int n = tasks.size();
        vector<int> ans;
        typedef pair<int, int> pii;
        
        priority_queue<pii, vector<pii>, greater<>> heap;
        for (int i = 0; i < n; i++) tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        
        
        typedef long long ll;
        ll t = 0;
        int ptr = 0;
        while (!heap.empty() || ptr < n) {
            while (ptr < n && heap.empty() && t <= tasks[ptr][0]) { // idle
                heap.emplace(tasks[ptr][1], tasks[ptr][2]);
                t = tasks[ptr][0];
                ptr++;
            }
            
            while (ptr < n && tasks[ptr][0] <= t) { // busy
                heap.emplace(tasks[ptr][1], tasks[ptr][2]);
                ptr++;
            }
            
            if (!heap.empty()) {
                auto [process, idx] = heap.top();
                heap.pop();
                t += process;
                ans.push_back(idx);
            }
        }
        return ans;
    }
};