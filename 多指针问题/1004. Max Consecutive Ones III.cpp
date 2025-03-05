class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n = nums.size();
        int ans = 0;
        vector<int> cnt(2, 0);
        for (int l = 0, r = 0; r < n; r++) {
            cnt[nums[r]]++;
            while (cnt[0] > k) {
                cnt[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};