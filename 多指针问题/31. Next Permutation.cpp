class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (0 == nums.size() || 1 == nums.size()) {
            return;
        } else if (2 == nums.size()) {
            swap(nums[0], nums[1]);
            return;
        }

        int ptr1 = nums.size() - 1;
        while (ptr1 >= 1) {
            if (nums[ptr1] > nums[ptr1 - 1]) {
                break;
            }
            ptr1--;
        }

        if (ptr1 >= 1) {
            int ptr2 = nums.size() - 1;

            while (ptr2 >= 0) {
                if (nums[ptr2] <= nums[ptr1 - 1]) {
                    ptr2--;
                } else {
                    break;
                }
            }

            swap(nums[ptr1 - 1], nums[ptr2]);
            reverse(nums, ptr1);
        } else {
            reverse(nums, 0);
        }
    }
    void swap(int& x, int& y) {
        int t = x;
        x = y;
        y = t;
    }
    void reverse(vector<int>& nums, int beginOffset) {
        int endOffset = nums.size() - 1;
        while (beginOffset < endOffset) {
            swap(nums[beginOffset], nums[endOffset]);
            beginOffset++;
            endOffset--;
        }
    }
};