class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        if (it1 == nums.end() || *it1 != target) {
            return vector<int>{-1, -1};
        }
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        return vector<int>{it1 - nums.begin(), it2 - nums.begin() - 1};
    }
};