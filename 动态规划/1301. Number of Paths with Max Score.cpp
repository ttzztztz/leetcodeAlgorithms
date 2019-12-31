class Solution {
public:
    int N;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < N;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        N = board.size();
        const int MOD = 1e9+7;
        vector<vector<int>> dp_value = vector<vector<int>>(N + 5, vector<int>(N + 5, -99999));
        vector<vector<int>> dp_count = vector<vector<int>>(N + 5, vector<int>(N + 5, 0));

        dp_value[N - 1][N - 1] = 0;
        dp_count[N - 1][N - 1] = 1;

        const int dx[] = {1, 0, 1};
        const int dy[] = {0, 1, 1};

        for (int x = N - 1; x >= 0; x--) {
            for (int y = N - 1; y >= 0; y--) {
                if (board[x][y] == 'S' || board[x][y] == 'X') continue;

                for (int k = 0; k < 3; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (pointValid(nx, ny) && board[nx][ny] != 'X') {

                        if (dp_value[x][y] < dp_value[nx][ny]) {
                            dp_count[x][y] = dp_count[nx][ny];
                            dp_value[x][y] = dp_value[nx][ny];
                        } else if (dp_value[nx][ny] == dp_value[x][y]) {
                            dp_count[x][y] += dp_count[nx][ny];
                            dp_count[x][y] %= MOD;
                        }

                    }
                }

                if (board[x][y] >= '1' && board[x][y] <= '9') {
                    dp_value[x][y] += board[x][y] - '0';
                }
            }
        }

        vector<int> answer = {0, 0};
        if (dp_value[0][0] < 0) {
            answer = {0, 0};
        } else {
            answer = {dp_value[0][0], dp_count[0][0] % MOD};
        }
        return answer;
    }
};