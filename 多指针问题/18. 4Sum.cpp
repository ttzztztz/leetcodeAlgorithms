class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n;) {
            for (int j = i + 1; j < n;) {
                const int val = target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while (l < r) {
                    if (nums[l] + nums[r] < val) {
                        while (l + 1 <= r && nums[l] == nums[l + 1]) l++;
                        l++;
                    } else if (nums[l] + nums[r] > val) {
                        while (l <= r - 1 && nums[r] == nums[r - 1]) r--;
                        r--;
                    } else {
                        ans.push_back(vector<int>{ nums[i], nums[j], nums[l], nums[r] });
                        
                        while (l + 1 <= r && nums[l] == nums[l + 1]) l++;
                        while (l <= r - 1 && nums[r] == nums[r - 1]) r--;
                        l++, r--;
                    }
                }
                while (j + 1 < n && nums[j] == nums[j + 1]) j++;
                j++;
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) i++;
            i++;
        }
        
        return ans;
    }
};