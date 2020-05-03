class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        const int n = mat.size(), m = mat[0].size();
        
        vector<int> current;
        for (int i = 0; i < m; i++) current.push_back(mat[0][i]);
        
        for (int i = 1; i < n; i++) {
            vector<int> next;
            
            for (int s : current) {
                for (int j = 0; j < m; j++) {
                    next.push_back(s + mat[i][j]);
                }
            }
            
            sort(next.begin(), next.end());
            if (next.size() > k) next.resize(k);
            current = next;
        }
        
        return current[k - 1];
    }
};
