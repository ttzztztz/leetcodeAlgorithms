class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int n = nums.size();
        
        vector<int> f(n + 1, n + 5);
        f[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                f[i] = min(f[i], 1 + f[i + j]);
            }
        }
        return f[0];
    }
};