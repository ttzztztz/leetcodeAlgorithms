class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int n = nums.size();
        vector<int> f(n, -1), g(n, -1);
        
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            const int t = nums[i];
            
            while (!stk.empty() && nums[stk.back()] <= t) stk.pop_back();
            if (!stk.empty()) g[i] = stk.back();
            stk.push_back(i);
        }
        
        f[0] = nums[0];
        for (int i = 1; i < n; i++) {
            f[i] = min(f[i - 1], nums[i]);
        }
        
        for (int i = 0; i < n; i++) {
            // cout << f[i] << ", " << g[i] << endl;
            if (g[i] != -1 && f[g[i]] < nums[i]) return true;
        }
        return false;
    }
};
