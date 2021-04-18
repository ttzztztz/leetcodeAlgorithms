class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = 0, last = nums[0];
        const int n = nums.size();
        for (int i = 1; i < n; i++) {
            const int t = max(nums[i], last + 1);
            ans += t - nums[i];
            last = t;
        }
        return ans;
    }
};