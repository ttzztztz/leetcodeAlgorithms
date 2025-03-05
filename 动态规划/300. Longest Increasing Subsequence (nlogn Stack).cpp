class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(f.begin(), f.end(), nums[i]);
            if (it == f.end()) {
                f.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return f.size();
    }
};