class Solution {
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        dfs(0, 0);
        return ans;
    }
private:
    vector<string> ans;
    string cur;
    int n;
    
    void dfs(int idx, int balance) {
        if (idx == 2 * n) {
            if (balance == 0) ans.push_back(cur);
            return;
        }
        
        if (balance > 0) {
            cur += ')';
            dfs(idx + 1, balance - 1);
            cur.pop_back();
        }
        
        cur += '(';
        dfs(idx + 1, balance + 1);
        cur.pop_back();
    }
};