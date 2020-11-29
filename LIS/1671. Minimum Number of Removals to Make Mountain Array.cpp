class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int n = nums.size();
        vector<int> f(n, 0), g(n, 0);
        
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || stk.back() < nums[i]) {
                stk.push_back(nums[i]);
            } else {
                auto it = lower_bound(stk.begin(), stk.end(), nums[i]);
                *it = nums[i];
            }
            
            f[i] = stk.size();
        }
        
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            if (stk.empty() || stk.back() < nums[i]) {
                stk.push_back(nums[i]);
            } else {
                auto it = lower_bound(stk.begin(), stk.end(), nums[i]);
                *it = nums[i];
            }
            
            g[i] = stk.size();
        }
        
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            if (f[i] >= 2 && g[i] >= 2) ans = min(ans, n - (f[i] + g[i] - 1));
        }
        return ans;
    }
};
