class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        
        vector<vector<int>> interval = { {0, 0} };
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                interval.back().back() = i;
            } else {
                interval.push_back(vector<int>{i, i});
            }
        }
        
        for (auto& v : interval) {
            const int l = v[0], r = v[1];
            if (l == r) {
                ans.push_back(to_string(nums[l]));
            } else {
                ans.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
            }
        }
        
        return ans;
    }
};
