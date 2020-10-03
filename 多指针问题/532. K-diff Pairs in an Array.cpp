class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (int l = 0, r = 1; r < n; r++) {
            while (r + 1 < n && nums[r + 1] == nums[r]) r++;
            
            while (l < r && nums[r] - nums[l] > k) l++;
            if (l < r && nums[r] - nums[l] == k) ans++;
            while (l + 1 < r && nums[l + 1] == nums[l]) l++;
        }
        return ans;
    }
};
