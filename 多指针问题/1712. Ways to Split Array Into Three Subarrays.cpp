class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const int mod = 1e9+7;
        typedef long long ll;
        ll ans = 0;
        const int n = nums.size();
        vector<ll> pref = {0};
        for (int i : nums) pref.push_back(pref.back() + i);
        
        auto sum = [&](int i, int j) -> int {
            return pref[j + 1] - pref[i];
        };
        
        for (int p1 = 0, p2 = 0, p3 = 0; p1 + 2 < n; p1++) {
            const int s1 = sum(0, p1);
            p2 = max(p2, p1 + 1);
            while (p2 < n - 1 && s1 > sum(p1 + 1, p2)) p2++;
            p3 = max(p3, p2 + 1);
            while (p3 < n && s1 <= sum(p1 + 1, p3 - 1) && sum(p1 + 1, p3 - 1) <= sum(p3, n - 1)) p3++;
            
            ans = (ans + max(0, p3 - p2 - 1)) % mod;
        }
        
        return ans;
    }
};
