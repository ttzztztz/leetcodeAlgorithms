class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        const int n = nums.size();
        typedef long long ll;
        ll mod = 1e9+7;

        vector<vector<ll>> f(n + 1, vector<ll>(k + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i][0] = 1;
            for (int j = 1; j <= k; j++) {
                f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
            }
        }

        ll ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                const int len = i + 1;
                ans = (ans + nums[i] * f[len - 1][j]) % mod;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < k; j++) {
                const int len = (n - i);
                ans = (ans + nums[i] * f[len - 1][j]) % mod;
            }
        }

        return ans;
    }
};