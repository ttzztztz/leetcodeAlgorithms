class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n = nums.size();
        int ans = 0;
        for (int l = 0, r = 0, cnt_0 = 0; r < n; r++) {
            cnt_0 += (nums[r] == 0);
            while (cnt_0 > k) {
                cnt_0 -= (nums[l] == 0);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};