class Solution {
public:
    int N, M;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    bool dfs(const vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int x, int y, int ptr) {
        if (ptr == word.size() - 1) {
            return board[x][y] == word[ptr];
        }
        if (board[x][y] != word[ptr]) {
            return false;
        }

        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            const int nextX = x + dx[i], nextY = y + dy[i];

            if (pointValid(nextX, nextY) && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                if (dfs(board, visited, word, nextX, nextY, ptr + 1)) {
                    return true;
                }
                visited[nextX][nextY] = false;
            }

        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return word == "";
        }
        N = board.size(), M = board[0].size();
        vector<vector<bool>> visited(N + 5, vector<bool>(M + 5, false));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] != word[0]) {
                    continue;
                }

                visited[i][j] = true;
                if(dfs(board, visited, word, i, j, 0)) {
                    return true;
                }
                visited[i][j] = false;
            }
        }

        return false;
    }
};