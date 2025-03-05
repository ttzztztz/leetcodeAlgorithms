class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        const int n = nums.size();

        int ptr1 = n - 1;
        while (ptr1 >= 1 && nums[ptr1 - 1] >= nums[ptr1]) ptr1--;
        if (ptr1 >= 1) {
            int ptr2 = n - 1;
            while (ptr1 < ptr2 && nums[ptr1 - 1] >= nums[ptr2]) ptr2--;
            swap(nums[ptr1 - 1], nums[ptr2]);
        }
        reverse(nums.begin() + ptr1, nums.end());
    }
};