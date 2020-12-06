class Solution {
public:
    int longestValidParentheses(string s) {
        const int n = s.size();
        vector<int> stk;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            const char ch = s[i];
			
            if (s[i] == '(') {
                stk.push_back(i);
            } else { // s[i] == ')'
                if (!stk.empty() && s[stk.back()] == '(') {
                    stk.pop_back();
                    if (stk.empty()) ans = max(ans, i + 1);
                    else ans = max(ans, i - stk.back());
                } else {
                    stk.push_back(i);
                }
            }
        }
        return ans;
    }
};
