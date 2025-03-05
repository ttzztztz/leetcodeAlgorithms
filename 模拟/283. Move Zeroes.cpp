class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();
        int zero_cnt = 0, w_ptr = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero_cnt++;
            else nums[w_ptr] = nums[i], w_ptr++;
        }

        for (int i = 0; i < zero_cnt; i++) nums[n - 1 - i] = 0;
    }
};