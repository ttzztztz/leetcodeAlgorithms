class Solution {
public:
    /**
     * @param nums: 
     * @return: Find the maxmum range value. A range value is defined as the minimum value times the sum of all values in a range.
     */
    int maxRange(vector<int> &nums) {
        const int n = nums.size();
        vector<int> l(n), r(n), pref(n + 1, 0);
        
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + nums[i - 1];
        auto sum = [&](int i, int j) -> int {
            return pref[j + 1] - pref[i];
        };
        
        int ans = 0;
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.back()] >= nums[i]) stk.pop_back();
            
            if (stk.empty()) l[i] = -1;
            else l[i] = stk.back();
            
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.back()] >= nums[i]) stk.pop_back();
            
            if (stk.empty()) r[i] = n;
            else r[i] = stk.back();
            
            stk.push_back(i);
        }
        stk.clear();
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, nums[i] * sum(l[i] + 1, r[i] - 1));
        }
        
        return ans;
    }
};
