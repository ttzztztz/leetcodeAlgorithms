class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size(), m = matrix[0].size();
        
        vector<int> all;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i >= 1) matrix[i][j] ^= matrix[i - 1][j];
                if (j >= 1) matrix[i][j] ^= matrix[i][j - 1];
                if (i >= 1 && j >= 1) matrix[i][j] ^= matrix[i - 1][j - 1];
                
                all.push_back(matrix[i][j]);
            }
        }
        
        const int x = n * m - k;
        nth_element(all.begin(), all.begin() + x, all.end());
        return all[x];
    }
};
