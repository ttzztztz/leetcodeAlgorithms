class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> data(101, 0);
        for (int i : nums) data[i]++;
        for (int i = 1; i <= 100; i++) {
            data[i] += data[i - 1];
        }
        
        const int n = nums.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 1) ans[i] = data[nums[i] - 1];
        }
        return ans;
    }
};