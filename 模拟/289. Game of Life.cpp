class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        const int n = board.size(), m = board[0].size();

        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        const int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
        const int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};

        const int NEXT_LIVE = 1 << 1, NEXT_DIE = 0; // 3 = 0b1?, 2 = 0b0?

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            int adjacent_live = 0;

            for (int k = 0; k < 8; k++) {
                if (!point_valid(i + dx[k], j + dy[k])) continue;

                if ((board[i + dx[k]][j + dy[k]] & 1) == 1) adjacent_live++;
            }


            if (board[i][j] == 1 && adjacent_live < 2) board[i][j] |= NEXT_DIE;
            if (board[i][j] == 1 && 2 <= adjacent_live && adjacent_live <= 3) board[i][j] |= NEXT_LIVE;
            if (board[i][j] == 1 && adjacent_live > 3) board[i][j] |= NEXT_DIE;
            if (board[i][j] == 0 && adjacent_live == 3) board[i][j] |= NEXT_LIVE;
        }

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) board[i][j] >>= 1;
    }
};