class Solution {
public:
    int minPairSum(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int l = 0, r = n - 1; l < r; l++, r--) ans = max(ans, nums[l] + nums[r]);
        return ans;
    }
};