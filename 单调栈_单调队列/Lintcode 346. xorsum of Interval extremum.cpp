class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: The xorsum of maximun value xor minimun value of all subintervals
     */
    int XorSum(vector<int> &nums) {
        const int n = nums.size();
        vector<int> min_f(n, 0), min_g(n, 0), max_f(n, 0), max_g(n, 0);
        
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.back()] > nums[i]) stk.pop_back();
            
            if (stk.empty()) min_f[i] = -1;
            else min_f[i] = stk.back();
            
           stk.push_back(i);
        }
        
        stk.clear();
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.back()] < nums[i]) stk.pop_back();
            
            if (stk.empty()) max_f[i] = -1;
            else max_f[i] = stk.back();
            
           stk.push_back(i);
        }
        
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.back()] >= nums[i]) stk.pop_back();
            
            if (stk.empty()) min_g[i] = n;
            else min_g[i] = stk.back();
            
           stk.push_back(i);
        }
        
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.back()] <= nums[i]) stk.pop_back();
            
            if (stk.empty()) max_g[i] = n;
            else max_g[i] = stk.back();
            
           stk.push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            const long long mx = 1ll * (max_g[i] - i) * (i - max_f[i]);
            const long long mi = 1ll * (min_g[i] - i) * (i - min_f[i]);

            if ((mi + mx) % 2 == 1) ans ^= nums[i];
        }
        return ans;
    }
};
