class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int odd_col = 0, even_col = 0;
        vector<int> row(n, 0), col(m, 0);
        for (auto& index : indices) {
            row[index[0]]++;
            col[index[1]]++;
        }
        
        int ans = 0;
        for (int i : col) {
            odd_col += (i % 2 == 1);
            even_col += (i % 2 == 0);
        }
        
        for (int i : row) {
            if (i % 2 == 0) ans += odd_col;
            else ans += even_col;
        }
        return ans;
    }
};