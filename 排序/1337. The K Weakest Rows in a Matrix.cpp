class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        if (mat.empty()) return {};
        const int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>> data;
        for (int i = 0; i < n; i++) {
            const int t = accumulate(mat[i].begin(), mat[i].end(), 0);
            data.push_back({ t, i });
        }
        sort(data.begin(), data.end());
        
        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(data[i][1]);
        return ans;
    }
};