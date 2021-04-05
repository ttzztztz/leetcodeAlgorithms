class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        typedef long long ll;
        ll ans = 0;
        const int n = nums1.size();
        for (int i = 0; i < n; i++) ans += 1ll * abs(nums1[i] - nums2[i]);
        ll b = ans;
        
        set<int> t(nums1.begin(), nums1.end());
        const int mod = 1e9+7;
        
        for (int i = 0; i < n; i++) {
            ll cur = b - 1ll * abs(nums1[i] - nums2[i]);

            auto it = t.lower_bound(nums2[i]);
            if (it != t.end()) {
                ll v = cur + 1ll * abs(nums2[i] - (*it));
                ans = min(ans, v);
            }
            
            if (it != t.begin()) {
                --it;
                ll v = cur + 1ll * abs(nums2[i] - (*it));
                ans = min(ans, v);
            }
        }
        
        return ans % mod;
    }
};
