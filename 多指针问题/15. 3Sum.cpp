class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        const int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                const int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back(vector<int>{ nums[i], nums[j], nums[k] });
                }

                if (sum <= 0) {
                    while (j + 1 < k && nums[j] == nums[j + 1]) j++;
                    j++;
                } else {
                    while (j < k - 1 && nums[k] == nums[k - 1]) k--;
                    k--;
                }
            }
            while (i + 1 < n && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};