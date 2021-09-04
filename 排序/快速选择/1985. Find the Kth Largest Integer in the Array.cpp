class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        k--;
        nth_element(
            nums.begin(),
            nums.begin() + k,
            nums.end(),
            [&](const auto& lhs, const auto& rhs) -> bool {
                if (lhs.size() != rhs.size()) {
                    return lhs.size() > rhs.size();
                }
                return lhs > rhs;
            }
        );
        
        return nums[k];
    }
};