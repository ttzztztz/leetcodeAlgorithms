class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        const int n = nums.size();
        vector<int> f(n + 1, 0), g(n + 1, 0);
        // f -> odd, g -> even
        for (int i = 1; i <= n; i++) {
            const int idx = i - 1;
            if (idx % 2 == 1) {
                f[i] = f[i - 1] + nums[idx];
                g[i] = g[i - 1];
            } else {
                f[i] = f[i - 1];
                g[i] = g[i - 1] + nums[idx];
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            const int left = f[i - 1] + g[n] - g[i];
            const int right = g[i - 1] + f[n] - f[i];
            
            if (left == right) ans++;
        }
        return ans;
    }
};
