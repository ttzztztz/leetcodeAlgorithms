class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans1 = 0, ans2 = 0;
        const int n = nums.size();
        if (n <= 1) return 0;
        
        for (int i = 0; i < n; i += 2) {
            int mi = numeric_limits<int>::max();
            if (i - 1 >= 0) mi = min(mi, nums[i - 1]);
            if (i + 1 < n) mi = min(mi, nums[i + 1]);
            
            if (nums[i] >= mi) {
                ans1 += nums[i] - mi + 1;
            }
        }
        
        for (int i = 1; i < n; i += 2) {
            int mi = numeric_limits<int>::max();
            if (i - 1 >= 0) mi = min(mi, nums[i - 1]);
            if (i + 1 < n) mi = min(mi, nums[i + 1]);
            
            if (nums[i] >= mi) {
                ans2 += nums[i] - mi + 1;
            }
        }
        
        return min(ans1, ans2);
    }
};