class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        this->n = matrix.size(), this->m = matrix[0].size();
        this->mat = matrix;
        
        vector<vector<int>> ans;
        const int mask = 3;
        memset(f, 0, sizeof f);
        memset(visited, 0, sizeof visited);
        
        for (int j = 0; j < m; j++) {
            dfs(0, j, 1);
            dfs(n - 1, j, 2);
        }
        for (int i = 0; i < n; i++) {
            dfs(i, 0, 1);
            dfs(i, m - 1, 2);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (f[i][j] == mask) ans.push_back(vector<int>{ i, j });
            }
        }
        return ans;
    }
private:
    int n, m;
    int f[155][155];
    bool visited[155][155][5];
    vector<vector<int>> mat;
    
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void dfs(int i, int j, int state) {
        visited[i][j][state] = true;
        f[i][j] |= state;
        
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (pointValid(nx, ny) && !visited[nx][ny][state] && mat[nx][ny] >= mat[i][j]) {
                visited[nx][ny][state] = true;
                dfs(nx, ny, state);
            }
        }
    }
};
