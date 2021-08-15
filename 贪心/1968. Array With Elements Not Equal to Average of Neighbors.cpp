class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int l = 0, r = nums.size() - 1; l <= r; l++, r--) {
            if (l == r) {
                ans.push_back(nums[l]);
            } else {
                ans.push_back(nums[l]);
                ans.push_back(nums[r]);
            }
        }
        return ans;
    }
};