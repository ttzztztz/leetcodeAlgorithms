class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> used;
        
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << n); i++) {
            vector<int> cur;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    cur.push_back(nums[j]);
                }
            }
            
            if (!used.count(cur)) {
                used.insert(cur);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
