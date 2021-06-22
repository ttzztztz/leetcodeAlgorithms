class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        if (n == 0) return ans;
        ans = { { 1 } };
        for (int i = 1; i < n; i++) {
            ans.push_back(vector<int>{});
            for (int j = 0; j <= i; j++) {
                ans.back().push_back(
                    (j == i ? 0 : ans[i - 1][j])
                    + (j == 0 ? 0 : ans[i - 1][j - 1])
                );
            }
        }
        return ans;
    }
};