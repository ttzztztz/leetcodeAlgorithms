class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int n = nums.size();
        typedef long long ll;
        const int mod = 1e9+7;
        
        vector<ll> l(n), r(n), pref;
        pref = {0};
        for (int i : nums) pref.push_back(pref.back() + i);
        
        auto pref_sum = [&](int i, int j) -> ll {
            return pref[j + 1] - pref[i];
        };
        
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
        
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            const int left = l[i], right = r[i];
            
            ans = max(ans, nums[i] * pref_sum(left + 1, right - 1));
        }
        return ans % mod;
    }
};
