class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        vector<int> pref = {0};
        for (int i : nums) pref.push_back(i + pref.back());
        
        auto is_up = [&](int i, int j) -> bool {
            for (int t = i + 1; t <= j; t++) {
                if (nums[t - 1] >= nums[t]) return false;
            }
            return true;
        };
        
        for (int j = 1; j <= nums.size(); j++) {
            for (int i = 0; i < j; i++) {
                if (is_up(i, j - 1)) ans = max(ans, pref[j] - pref[i]);
            }
        }
        return ans;
    }
};
