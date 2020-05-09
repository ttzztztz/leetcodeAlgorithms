class Solution {
public:
    bool canPartition(vector<int>& nums) {
        memset(dp, 0xff, sizeof dp);
        return f(nums, 0, 0);
    }
private:
    int dp[105][40005];
    bool f(vector<int>& nums, int index, int balance) {
        if (index == nums.size()) return balance == 0;
        int& memo = dp[index][balance + 20001];
        if (memo != -1) return memo;
        
        if (f(nums, index + 1, balance + nums[index])) {
            return memo = true;
        }
        
        if (f(nums, index + 1, balance - nums[index])) {
            return memo = true;
        }
        
        return memo = false;
    }
};
