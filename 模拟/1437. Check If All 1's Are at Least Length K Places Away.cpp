class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last1 = -99999;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (i - last1 - 1 < k) return false;
                last1 = i;
            }
        }
        return true;
    }
};
