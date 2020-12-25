class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;
        
        const int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0;
        while (true) {
            ans.push_back(matrix[i][j]);
            if (i == n - 1 && j == m - 1) break;
            
            if ((i + j) % 2 == 0) {
                if (j == m - 1) i++;
                else if (i == 0) j++;
                else i--, j++;
            } else { // (i + j) % 2 == 1
                if (i == n - 1) j++;
                else if (j == 0) i++;
                else i++, j--;
            }
        }
        return ans;
    }
};
