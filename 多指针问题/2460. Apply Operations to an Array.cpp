class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int l = 0, r = 0;
        while (r < n) {
            if (nums[r] != 0) {
                nums[l] = nums[r];
                l++;
            }
            r++;
        }
        for (int i = l; i < n; i++) {
            nums[i] = 0;
        }
        return nums;
    }
};