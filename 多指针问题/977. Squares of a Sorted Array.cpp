class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        const int n = nums.size();
        int j = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int i = j - 1;
        
        while (i >= 0 && j < n) {
            const int lhs = nums[i] * nums[i], rhs = nums[j] * nums[j];
            if (lhs < rhs) {
                ans.push_back(lhs);
                i--;
            } else {
                ans.push_back(rhs);
                j++;
            }
        }
        
        while (i >= 0) {
            ans.push_back(nums[i] * nums[i]);
            i--;
        }
        
        while (j < n) {
            ans.push_back(nums[j] * nums[j]);
            j++;
        }
        
        return ans;
    }
};
