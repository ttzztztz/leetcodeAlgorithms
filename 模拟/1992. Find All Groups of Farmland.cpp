class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        if (land.empty()) return ans;
        
        const int n = land.size(), m = land[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (land[i][j] == 1 && !visited[i][j]) {
                int r = i, c = j;
                while (r + 1 < n && c < m && land[r + 1][c] == 1) r++;
                while (r < n && c + 1 < m && land[r][c + 1] == 1) c++;
                
                ans.push_back(vector<int>{ i, j, r, c });
                fill_visited(visited, i, j, r, c);
            }
        }
        return ans;
    }
private:
    void fill_visited(vector<vector<bool>>& visited, int i, int j, int r, int c) {
        for (int a = i; a <= r; a++) for (int b = j; b <= c; b++) {
            visited[a][b] = true;
        }
    }
};