class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        
        for (int i = n - 1, cnt = 1; i >= 0; i--, cnt++) {
            while (i - 1 >= 0 && nums[i - 1] == nums[i]) cnt++, i--;
            
            if (i >= 1) {
                ans += cnt;
            }
        }
        return ans;
    }
};