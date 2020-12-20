class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int n = nums.size();
        
        deque<int> q;
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && i - q.front() > k) q.pop_front();
            
            if (q.empty()) f[i] = nums[i - 1];
            else f[i] = f[q.front()] + nums[i - 1];
            
            while (!q.empty() && f[q.back()] <= f[i]) q.pop_back();
            q.push_back(i);
        }
        
        return f[n];
    }
};
