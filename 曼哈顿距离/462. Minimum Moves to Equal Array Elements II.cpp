class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        
        const int t = nums[n / 2];
        int ans = 0;
        for (int i : nums) ans += abs(t - i);
        return ans;
    }
};
