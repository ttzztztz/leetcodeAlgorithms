class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        const int m = l.size();
        vector<bool> ans(m, true);
        
        for (int q = 0; q < m; q++) {
            const int left = l[q], right = r[q];
            
            vector<int> cur;
            for (int t = left; t <= right; t++) cur.push_back(nums[t]);
            sort(cur.begin(), cur.end());
            
            const int d = cur[1] - cur[0];
            for (int i = 2; i < cur.size(); i++) {
                if (cur[i] - cur[i - 1] != d) {
                    ans[q] = false;
                    break;
                }
            }
        }
        
        return ans;
    }
};
