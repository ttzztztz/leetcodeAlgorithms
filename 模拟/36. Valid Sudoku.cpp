class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    const int d = board[i][j] - '0';
                    if (t & (1 << d)) return false;
                    t |= (1 << d);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int j = 0; j < n; j++) {
                if (board[j][i] != '.') {
                    const int d = board[j][i] - '0';
                    if (t & (1 << d)) return false;
                    t |= (1 << d);
                }
            }
        }
        
        for (int a = 0; a < n; a += 3) for (int b = 0; b < n; b += 3) {
            int t = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[a + i][b + j] != '.') {
                        const int d = board[a + i][b + j] - '0';
                        if (t & (1 << d)) return false;
                        t |= (1 << d);
                    }
                }
            }
        }
        return true;
    }
};
