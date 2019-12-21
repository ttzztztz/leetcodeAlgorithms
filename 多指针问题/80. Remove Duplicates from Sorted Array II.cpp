class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 2) {
            return N;
        }

        int slowPtr = 1, fastPtr = 2;
        while (fastPtr < N) {
            if (nums[fastPtr] != nums[slowPtr - 1]) {
                slowPtr++;
                nums[slowPtr] = nums[fastPtr];
            }
            fastPtr++;
        }
        return slowPtr + 1;
    }
};