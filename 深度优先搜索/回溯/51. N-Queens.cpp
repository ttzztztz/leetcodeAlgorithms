class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        dfs();
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<int> state;
    int n;
    
    void dfs() {
        if (state.size() == n) {
            ans.push_back(generate());
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            state.push_back(i);
            if (valid(state.size())) dfs();
            state.pop_back();
        }
    }
    
    vector<string> generate() {
        vector<string> cur;
        for (int i = 0; i < n; i++) {
            string t(n, '.');
            t[state[i] - 1] = 'Q';
            cur.push_back(t);
        }
        return cur;
    }
    
    bool valid(int t) {
        for (int i = 0; i < t; i++) {
            for (int j = i + 1; j < t; j++) {
                if (state[i] == state[j] || abs(state[i] - state[j]) == abs(i - j)) {
                    return false;
                }
            }
        }
        return true;
    }
};