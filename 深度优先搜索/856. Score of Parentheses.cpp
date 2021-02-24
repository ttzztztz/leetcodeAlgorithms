class Solution {
public:
    int scoreOfParentheses(string S) {
        return dfs(S, 0, S.size() - 1);
    }
private:
    int dfs(const string& str, int l, int r) {
        if (l + 1 == r) return 1;
        if (l >= r) return 0;
        
        int balance = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] == '(') balance++;
            else balance--;
            
            if (balance == 0) {
                return max(1, 2 * dfs(str, l + 1, i - 1)) + dfs(str, i + 1, r);
            }
        }
        
        return 0; // never reach this branch
    }
};