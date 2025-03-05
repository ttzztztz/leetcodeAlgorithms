class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int n = nums.size();
        int lt = 0, gt = n - 1, cur = 0;
        while (cur <= gt) {
            if (nums[cur] == 0) {
                swap(nums[cur], nums[lt]);
                cur++, lt++;
            } else if (nums[cur] == 1) {
                cur++;
            } else { // nums[cur] == 2
                swap(nums[cur], nums[gt]);
                gt--;
            }
        }
    }
};