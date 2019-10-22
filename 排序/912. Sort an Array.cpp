class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};