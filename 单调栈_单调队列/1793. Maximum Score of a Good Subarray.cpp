class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> f(n), g(n), stk;
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.back()] >= nums[i]) {
                stk.pop_back();
            }
            
            if (stk.empty()) f[i] = -1;
            else f[i] = stk.back();
            
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.back()] >= nums[i]) {
                stk.pop_back();
            }
            
            if (stk.empty()) g[i] = n;
            else g[i] = stk.back();
            
            stk.push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = f[i] + 1;
            int r = g[i] - 1;
            
            if (l <= k && k <= r) {
                // cout << i << "," << f[i] << "," << g[i] << endl;
                ans = max(ans, nums[i] * (r - l + 1));
            }
        }
        // cout << endl;
        return ans;
    }
};
