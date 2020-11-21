class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int n = nums.size();
        vector<int> f(n, 1);
        
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) f[i] = f[i - 1] + 1;
            else f[i] = 1;
            
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
