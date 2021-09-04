class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        k--;
        sort(nums.begin(), nums.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            if (lhs.size() != rhs.size()) {
                return lhs.size() > rhs.size();
            }
            return lhs > rhs;
        });
        return nums[k];
    }
};