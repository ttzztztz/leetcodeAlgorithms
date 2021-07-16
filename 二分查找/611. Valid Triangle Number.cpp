class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == 0) continue;
                
                auto it = lower_bound(nums.begin(), nums.end(), nums[i] + nums[j]);
                ans += it - (nums.begin() + j) - 1;
            }
        }
        return ans;
    }
};