class Solution {
public:
    int minFlipsMonoIncr(string S) {
        n_ = S.size();
        s_ = S;
        memo_ = vector<vector<int>>(n_, vector<int>(2, -1));
        
        return dfs(0, 0);
    }
private:
    vector<vector<int>> memo_;
    int n_;
    string s_;
    
    int dfs(int idx, int state) {
        if (idx == n_) return 0;
        int& val = memo_[idx][state];
        if (val != -1) return val;
        
        int ans = n_ + 5;
        if (state == 0) {
            if (s_[idx] == '0') {
                ans = min(ans, dfs(idx + 1, 0));
            } else { // s_[idx] == '1'
                ans = min(dfs(idx + 1, 1), 1 + dfs(idx + 1, 0));
            }
        } else { // state == 1
            if (s_[idx] == '0') {
                ans = min(ans, 1 + dfs(idx + 1, 1));
            } else { // s_[idx] == '1'
                ans = min(ans, dfs(idx + 1, 1));
            }
        }
        return val = ans;
    }
};
