class Solution {
public:
    int splitArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> f(n, n + 5);
        for (int i = 0; i < n; i++) f[i] = i + 1;

        for (int i = 0; i < n; i++) {
            if (i >= 1) f[i] = f[i - 1] + 1;
    
            for (int j = 0; j < i; j++) {
                if (__gcd(nums[i], nums[j]) > 1) {
                    if (j == 0) f[i] = min(f[i], 1);
                    else f[i] = min(f[i], f[j - 1] + 1);
                }
            }
        }
        return f[n - 1];
    }
};
