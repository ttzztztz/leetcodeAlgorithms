class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<bool>> cannotFlip;
    int N, M;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (visited[x][y]) {
            return;
        }

        visited[x][y] = true;
        cannotFlip[x][y] = true;
        if (pointValid(x - 1, y) && board[x - 1][y] == 'O') {
            dfs(board, x - 1, y);
        }
        if (pointValid(x + 1, y) && board[x + 1][y] == 'O') {
            dfs(board, x + 1, y);
        }
        if (pointValid(x, y - 1) && board[x][y - 1] == 'O') {
            dfs(board, x, y - 1);
        }
        if (pointValid(x, y + 1) && board[x][y + 1] == 'O') {
            dfs(board, x, y + 1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if (0 == board.size()) {
            return;
        }

        N = board.size();
        M = board[0].size();

        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        cannotFlip = vector<vector<bool>>(N, vector<bool>(M, false));

        for (int i = 0; i < M; i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                dfs(board, 0, i);
            }
            if (board[N - 1][i] == 'O' && !visited[N - 1][i]) {
                dfs(board, N - 1, i);
            }
        }
        for (int i = 0; i < N; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(board, i, 0);
            }
            if (board[i][M - 1] == 'O' && !visited[i][M - 1]) {
                dfs(board, i, M - 1);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 'O' && !cannotFlip[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};