class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0;
        
        int dep = 0;
        for (const char ch : S) {
            if (ch == '(') dep++;
            else { // )
                dep--;
                ans += (1 << dep);
            }
        }
        return ans;
    }
};
