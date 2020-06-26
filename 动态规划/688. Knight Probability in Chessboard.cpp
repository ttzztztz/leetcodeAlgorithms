class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double f[N + 5][N + 5][K + 5];
        memset(f, 0, sizeof f);
        f[r][c][0] = 1.0;
        
        const int dx[] = {2, -2, 1, -1, 2, -2, 1, -1};
        const int dy[] = {1, -1, 2, -2, -1, 1, -2, 2};
        for (int k = 1; k <= K; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int m = 0; m < 8; m++) {
                        const int nx = i + dx[m], ny = j + dy[m];
                        
                        if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                            f[i][j][k] += f[nx][ny][k - 1] / 8.0;
                        }
                    }
                }
            }
        }
        
        double answer = 0.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                answer += f[i][j][K];
            }
        }
        return answer;
    }
};
