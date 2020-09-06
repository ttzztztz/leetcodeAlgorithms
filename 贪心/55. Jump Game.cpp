class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 1) return true;
        
        int further = 0;
        for (int i = 0; i < N; i++) {
            if (further < i) return false;
            further = max(further, i + nums[i]);
        }
        return true;
    }
};
