class Solution {
public:
    /**
     * @param height: the given height
     * @param width: the given width
     * @return: the number of paths you can reach the end
     */
    int uniquePath(int height, int width) {
        f = vector<vector<long long>>(height + 5, vector<long long>(width + 5, -1));
        N = height, M = width;
        return dfs(0, 0);
    }
private:
    vector<vector<long long>> f;
    int N, M;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    long long dfs(int i, int j) {
        const int MOD = 1e9+7;
        
        if (i == 0 && j == M - 1) return 1;
        if (f[i][j] != -1) return f[i][j];
        
        long long answer = 0;
        const int dx[] = {1, 0, -1};
        
        for (int k = 0; k < 3; k++) {
            if (!pointValid(i + dx[k], j + 1)) continue;
            
            answer += dfs(i + dx[k], j + 1);
            answer %= MOD;
        }
        
        return f[i][j] = answer;
    }
};
