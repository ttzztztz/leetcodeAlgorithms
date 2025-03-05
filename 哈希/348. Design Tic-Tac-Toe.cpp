class TicTacToe {
public:
    TicTacToe(int n) {
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        r[row][player]++;
        if (r[row][player] == n) return player;
        c[col][player]++;
        if (c[col][player] == n) return player;
        diag[row + col][player]++;
        if (diag[row + col][player] == n) return player;
        rev_diag[row - col][player]++;
        if (rev_diag[row - col][player] == n) return player;
        return 0;
    }
private:
    int n;

    unordered_map<int, unordered_map<int, int>> r, c, diag, rev_diag;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */