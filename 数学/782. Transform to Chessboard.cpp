class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        const int N = board.size();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) return -1;
            }
        }
        
        int rowCount = 0, colCount = 0, row1 = 0, col1 = 0;
        for (int i = 0; i < N; i++) {
            rowCount += board[i][0] == i % 2;
            row1 += board[i][0] == 1;
            
            colCount += board[0][i] == i % 2;
            col1 += board[0][i] == 1;
        }
        
        if (row1 != N / 2 && row1 != (N + 1) / 2) return -1;
        if (col1 != N / 2 && col1 != (N + 1) / 2) return -1;
        
        if (N % 2 == 1) {
            if (rowCount % 2 == 1) rowCount = N - rowCount;
            if (colCount % 2 == 1) colCount = N - colCount;
        } else {
            rowCount = min(rowCount, N - rowCount);
            colCount = min(colCount, N - colCount);
        }
        return (rowCount + colCount) / 2;
    }
};
