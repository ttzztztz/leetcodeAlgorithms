class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        const int n = nums.size();

        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            while (i + 1 < n && nums[i] < nums[i + 1]) {
                cur += nums[i + 1];
                i++;
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};