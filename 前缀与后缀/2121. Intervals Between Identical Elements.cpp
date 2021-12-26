class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        typedef long long ll;
        const int n = arr.size();
        const int maxn = 1e5+1;
        
        vector<ll> ans(n, 0);
        vector<vector<int>> idx(maxn, vector<int>{});
        for (int i = 0; i < n; i++) idx[arr[i]].push_back(i);
        
        for (auto& nums : idx) {
            const int m = nums.size();
            vector<ll> pref(m, 0), suf(m, 0);
            
            for (int i = 1; i < m; i++) {
                // [0 1 3 5]
                pref[i] = pref[i - 1] + 1ll * i * (nums[i] - nums[i - 1]);
            }
            
            for (int i = m - 2, cnt = 1; i >= 0; i--, cnt++) {
                suf[i] = suf[i + 1] + 1ll * cnt * (nums[i + 1] - nums[i]);
            }
            
            for (int j = 0; j < m; j++) {
                ans[nums[j]] = pref[j] + suf[j];
            }
        }
        return ans;
    }
};
