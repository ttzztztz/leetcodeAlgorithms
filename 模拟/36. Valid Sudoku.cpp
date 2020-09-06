class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = 9;
        vector<vector<bool>> row(9, vector<bool>(10, 0)), col(9, vector<bool>(10, 0)), table(9, vector<bool>(10, 0));

        const int startX[] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
        const int startY[] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
        for (int i = 0; i < 9; i++) {
            for (int x = startX[i]; x < startX[i] + 3; x++) {
                for (int y = startY[i]; y < startY[i] + 3; y++) {
                    if (board[x][y] != '.') {
                        const int num = board[x][y] - '0';

                        if (col[y][num] == true) {
                            return false;
                        } else {
                            col[y][num] = true;
                        }

                        if (row[x][num] == true) {
                            return false;
                        } else {
                            row[x][num] = true;
                        }

                        if (table[i][num] == true) {
                            return false;
                        } else {
                            table[i][num] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};