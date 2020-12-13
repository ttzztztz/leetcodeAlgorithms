class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);
        
        int cur = 0;
        for (int i = 1; i < n; i++) cur += nums[i] - nums[0];
        ans[0] = cur;
        for (int i = 1; i < n; i++) {
            cur -= (n - i) * (nums[i] - nums[i - 1]);
            cur += i * (nums[i] - nums[i - 1]);
            
            ans[i] = cur;
        }
        
        return ans;
    }
};
