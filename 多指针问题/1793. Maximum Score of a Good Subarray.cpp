class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        int ans = nums[k], mi = nums[k];
        int i = k, j = k;
        while (i > 0 || j < n - 1) {
            if (i == 0) j++;
            else if (j == n - 1) i--;
            else if (nums[i - 1] < nums[j + 1]) j++;
            else i--; // nums[i - 1] >= nums[j + 1]
            
            mi = min(mi, min(nums[i], nums[j]));
            ans = max(ans, mi * (j - i + 1));
        }
        return ans;
    }
};
