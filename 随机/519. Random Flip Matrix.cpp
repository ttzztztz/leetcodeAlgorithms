class Solution {
public:
    Solution(int n_rows, int n_cols) {
        r = r_initial = n_rows * n_cols - 1;
        this->n_cols = n_cols;
    }
    
    vector<int> flip() {
        uniform_int_distribution<int> d(0, r);
        const int t = d(rd);
        int ans = -1;
        
        if (f.count(t)) {
            ans = f[t];
        } else {
            ans = t;
        }
        
        if (f.count(r)) {
            f[t] = f[r];
        } else {
            f[t] = r;
        }
        
        r--;
        return vector<int>{ ans / n_cols, ans % n_cols };
    }
    
    void reset() {
        r = r_initial;
        f.clear();
    }
private:
    unordered_map<int, int> f;
    int r, r_initial, n_cols;
    
    mt19937 rd{ random_device{}() };
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
