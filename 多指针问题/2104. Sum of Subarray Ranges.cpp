class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        typedef long long ll;
        const int n = nums.size();
        
        ll ans = 0;
        for (int l = 0; l < n; l++) {
            ll mx = nums[l], mi = nums[l];
            for (int r = l; r < n; r++) {
                mx = max<ll>(mx, nums[r]);
                mi = min<ll>(mi, nums[r]);
                
                ans += mx - mi;
            }
        }
        return ans;
    }
};
