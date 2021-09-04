class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int ans = nums[k - 1] - nums[0];
        for (int l = 0, r = k - 1; r < n; l++, r++) {
            ans = min(ans, nums[r] - nums[l]);
        }
        return ans;
    }
};