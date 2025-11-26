class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // f[i] = max(val, f[i - 1] + val)

        long long ans = numeric_limits<int>::min(), last = numeric_limits<int>::min();
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            last = max<long long>(nums[i], nums[i] + last);
            ans = max(ans, last);
        }

        return ans;
    }
};