class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i = next(nums, i, 1)) {
            const int target = -nums[i];
            for (int j = i + 1, k = n - 1; j < k; j = next(nums, j, 1)) {
                while (j < k && nums[j] + nums[k] >= target) {
                    if (nums[j] + nums[k] == target) {
                        ans.push_back({ nums[i], nums[j], nums[k] });
                    }
                    k = next(nums, k, -1);
                }
            }
        }
        return ans;
    }
private:
    int next(const vector<int>& nums, int k, int step) {
        const int n = nums.size();
        const int prev_num = nums[k];

        int i = k;
        while (0 <= i && i < n) {
            if (nums[i] != prev_num) break;
            i += step;
        }
        return i;
    }
};