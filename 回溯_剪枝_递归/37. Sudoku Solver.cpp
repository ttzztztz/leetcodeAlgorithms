class Solution {
public:
    int N = 9;
    int ones[520], bitPos[520];
    int row[9], col[9], table[3][3];

    int lowbit(int x) {
        return x & (-x);
    }

    void init() {
        memset(ones, 0, sizeof(ones));
        memset(bitPos, 0, sizeof(bitPos));

        for (int i = 0; i < N; i++) {
            row[i] = (1 << N) - 1;
            col[i] = (1 << N) - 1;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                table[i][j] = (1 << N) - 1;
            }
        }

        for (int i = 0; i < N; i++) {
            bitPos[1 << i] = i;
        }

        for (int i = 0; i < (1 << N); i++) {
            int cnt = 0;
            int copyI = i;
            while (copyI) {
                cnt++;
                copyI -= lowbit(copyI);
            }
            ones[i] = cnt;
        }
    }

    void changeState(int i, int j, int number) {
        row[i] ^= 1 << number;
        col[j] ^= 1 << number;
        table[i / 3][j / 3] ^= 1 << number;
    }

    int initBoard(const vector<vector<char>>& board) {
        int needFill = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') {
                    needFill++;
                } else {
                    const int number = board[i][j] - '1';
                    changeState(i, j, number);
                }
            }
        }
        return needFill;
    }

    int getIntersection(int i, int j) {
        return row[i] & col[j] & table[i / 3][j / 3];
    }

    bool dfs(vector<vector<char>>& board, int remain) {
        if (remain == 0) {
            return true;
        }

        int x = 0, y = 0, t = 999;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.' && ones[getIntersection(i, j)] < t) {
                    t = ones[getIntersection(i, j)], x = i, y = j;
                }
            }
        }

        for (int i = getIntersection(x, y); i; i ^= lowbit(i)) {
            const int digit = bitPos[lowbit(i)];

            board[x][y] = '1' + digit;
            changeState(x, y, digit);

            if (dfs(board, remain - 1)) {
                return true;
            }

            changeState(x, y, digit);
            board[x][y] = '.';
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        init();
        int needFill = initBoard(board);
        dfs(board, needFill);
    }
};