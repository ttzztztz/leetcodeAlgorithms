class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        if (nums.empty()) return K == 0;
        
        const int n = nums.size();
        int repeat = 1, cur = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                repeat++;
            } else {
                repeat = 1;
            }
            
            cur = max(cur, repeat);
        }
        
        return cur * K <= nums.size();
    }
};
