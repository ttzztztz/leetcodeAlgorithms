class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans = numeric_limits<int>::min();
        
        const int n = nums.size();
        vector<int> f(n, 0);
        deque<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && i - q.front() > k) q.pop_front();
            
            if (q.empty()) f[i] = 0;
            else f[i] = f[q.front()];
            
            f[i] = max(nums[i], f[i] + nums[i]);
            while (!q.empty() && f[q.back()] <= f[i]) q.pop_back();
            
            ans = max(ans, f[i]);
            q.push_back(i);
        }
        return ans;
    }
};