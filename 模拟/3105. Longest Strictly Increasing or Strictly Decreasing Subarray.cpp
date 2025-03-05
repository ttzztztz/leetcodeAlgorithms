class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int ans = 0;
        const int n = nums.size();

        for (int i = 0; i < n; i++) {
            int cur = 1;
            while (i + 1 < n && nums[i] < nums[i + 1]) i++, cur++;
            ans = max(ans, cur);
        }

        for (int i = 0; i < n; i++) {
            int cur = 1;
            while (i + 1 < n && nums[i] > nums[i + 1]) i++, cur++;
            ans = max(ans, cur);
        }

        return ans;
    }
};