class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        const int n = nums.size();
        
        vector<vector<int>> tmp;
        for (int i = 0; i < n; i++) for (int j = 0; j < nums[i].size(); j++) {
            const int t = i + j;
            while (t >= tmp.size()) tmp.push_back({});
            tmp[t].push_back(nums[i][j]);
        }
        
        for (auto& v : tmp) {
            for (int i = v.size() - 1; i >= 0; i--) ans.push_back(v[i]);
        }
        return ans;
    }
};