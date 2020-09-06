class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(f, 0xff, sizeof f);
        N = grid.size(), M = grid[0].size();
        return dfs(grid, 0, 0, M - 1);
    }
private:
    int f[75][75][75];
    int N, M;
    bool valid(int j) {
        return j >= 0 && j < M;
    }
    int dfs(const vector<vector<int>>& grid, int i, int j, int k) {
        if (i == N) return 0;
        if (f[i][j][k] != -1) return f[i][j][k];
        
        int answer = grid[i][j];
        if (j != k) answer += grid[i][k];
        
        int tmp = 0;
        const int dy[] = {-1, 0, 1};
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                const int nj = j + dy[a], nk = k + dy[b];
                if (valid(nj) && valid(nk)) tmp = max(tmp, dfs(grid, i + 1, nj, nk));
            }
        }
        
        return f[i][j][k] = answer + tmp;
    }
};
