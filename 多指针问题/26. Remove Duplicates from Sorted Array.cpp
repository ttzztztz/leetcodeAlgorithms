class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) {
            return N;
        }

        int slowPtr = 0, fastPtr = 1;
        while (fastPtr < N) {
            if (nums[slowPtr] != nums[fastPtr]) {
                slowPtr++;
                nums[slowPtr] = nums[fastPtr];
            }
            fastPtr++;
        }
        return slowPtr + 1;
    }
};