class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (i != nums[i]) {
                if (nums[nums[i]] == nums[i]) return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};