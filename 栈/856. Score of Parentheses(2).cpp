class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0, d = 0;
        const int n = S.size();
        for (int i = 0; i < n; i++) {
            if (S[i] == '(') d++;
            else d--; // S[i] == ')'
            
            if (S[i] == '(' && S[i + 1] == ')') {
                ans += 1 << (d - 1);
            }
        }        
        return ans;
    }
};