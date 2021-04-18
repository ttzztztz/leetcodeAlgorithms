class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int n = nums.size();
        vector<int> ans(n, 0);
        int cur = 0;
        for (int i = 0; i < n; i++) cur ^= nums[i];
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int x = maximumBit - 1; x >= 0; x--) {
                if (0 == (cur & (1 << x))) {
                    t |= (1 << x);
                }
            }
            ans[i] = t;
            cur ^= nums[n - i - 1];
        }
        return ans;
    }
};