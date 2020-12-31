class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int n = board.size(), m = board[0].size();
        const int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
        const int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt_live = 0;
                
                for (int k = 0; k < 8; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (!point_valid(nx, ny)) continue;
                    
                    if ((board[nx][ny] & 1) == 1) cnt_live++;
                }
                
                if ((board[i][j] & 1) == 0 && cnt_live == 3) {
                    board[i][j] |= 1 << 1;
                } else if ((board[i][j] & 1) == 1 && (cnt_live == 2 || cnt_live == 3)) {
                    board[i][j] |= 1 << 1;
                }
                // else if ((board[i][j] & 1) == 1 && cnt_live <= 1) {
                //     board[i][j] ^= 1 << 1;
                // } else if ((board[i][j] & 1) == 1 && cnt_live >= 4) {
                //     board[i][j] ^= 1 << 1;
                // }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};
