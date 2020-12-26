class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        const int n = bulbs.size();
        if (n == 0) return -1;
        vector<int> pos(n + 1, 0);
        for (int i = 0; i < bulbs.size(); i++) {
            pos[bulbs[i]] = i + 1;
        }
        
        if (k == 0) {
            int ans = numeric_limits<int>::max();
            for (int i = 1; i + 1 <= n; i++) {
                ans = min(ans, max(pos[i], pos[i + 1]));
            }
            return ans;
        }
        
        deque<int> q;
        int ans = n + 5;
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && i - q.front() >= k) q.pop_front();
            while (!q.empty() && pos[q.back()] >= pos[i]) q.pop_back();
            q.push_back(i);
            
            if (i + 1 <= n && i - k >= 1) {
                if (max(pos[i + 1], pos[i - k]) < pos[q.front()]) {
                    ans = min(ans, max(pos[i + 1], pos[i - k]));
                }
            }
        }
        
        if (ans >= n + 5) return -1;
        else return ans;
    }
};
