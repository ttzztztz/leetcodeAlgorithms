class Solution {
public:
    int knightDialer(int n) {
        memset(f, 0xff, sizeof f);
        
        long long answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!pointValid(i, j)) continue;
                answer += dfs(i, j, n - 1);
                answer %= MOD;
            }
        }
        return answer;
    }
private:
    const int MOD = 1e9+7;
    long long f[5][5][5005];
    const vector<vector<int>> m = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {-1,0,-1}
    };
    const int N = 4, M = 3;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M && m[i][j] != -1;
    }
    
    long long dfs(int i, int j, int n) {
        if (n == 0) return 1;
        long long& val = f[i][j][n];
        if (val != -1) return val;
        
        long long answer = 0;
        const int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
        const int dy[] = {-2, 2, -2, 2, 1, -1, 1, -1};
        for (int k = 0; k < 8; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (pointValid(nx, ny)) {
                answer += dfs(nx, ny, n - 1);
                answer %= MOD;
            }
        }
        return val = answer;
    }
};