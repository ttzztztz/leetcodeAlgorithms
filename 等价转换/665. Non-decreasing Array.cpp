class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return true;
        
        bool changed = false;
        if (nums[0] > nums[1]) changed = true;
        
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (changed) {
                    return false;
                } else {
                    if (nums[i - 1] <= nums[i + 1]) {
                        nums[i] = nums[i + 1];
                    } else {
                        nums[i + 1] = nums[i];
                    }
                    changed = true;
                }
            }
        }
        
        return true;
    }
};
