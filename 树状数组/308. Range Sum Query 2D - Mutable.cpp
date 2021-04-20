class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        n_ = matrix.size(), m_ = matrix[0].size();
        matrix_ = vector<vector<int>>(n_, vector<int>(m_, 0));
        data_ = vector<vector<int>>(n_ + 1, vector<int>(m_ + 1, 0));
        for (int i = 0; i < n_; i++) {
            for (int j = 0; j < m_; j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        const int delta = val - matrix_[row][col];
        matrix_[row][col] = val;

        for (int i = row + 1; i <= n_; i += Lowbit(i)) {
            for (int j = col + 1; j <= m_; j += Lowbit(j)) {
                data_[i][j] += delta;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return Query(row2 + 1, col2 + 1) - Query(row1, col2 + 1) - Query(row2 + 1, col1) + Query(row1, col1);
    }
private:
    int Lowbit(int x) {
        return x & (-x);
    }
    int n_, m_;
    vector<vector<int>> data_, matrix_;
    
    int Query(int x, int y) {
        int ans = 0;
        for (int i = x; i; i -= Lowbit(i)) {
            for (int j = y; j; j -= Lowbit(j)) {
                ans += data_[i][j];
            }
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
