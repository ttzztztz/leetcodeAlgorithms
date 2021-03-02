class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        typedef long long ll;
        
        const int n = nums.size();
        vector<vector<ll>> f(n + 1, vector<ll>(2, 0));
        
        f[0][0] = max(nums[0], 0);
        f[0][1] = nums[0] * nums[0];
        ll ans = f[0][1];
        
        for (int i = 1; i < n; i++) {
            f[i][0] = max(f[i - 1][0] + nums[i], 1ll * nums[i]);
            f[i][1] = max(
                f[i - 1][1] + nums[i],
                max(
                    f[i - 1][0] + nums[i] * nums[i],
                    1ll * nums[i] * nums[i])
            );
            ans = max(ans, f[i][1]);
        }
        
        return ans;
    }
};
