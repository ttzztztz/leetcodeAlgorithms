class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.size() + 1], answer = 0;
        std::memset(dp, 0, sizeof(dp));

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] - 1 >= 0 && s[i - 1] == ')' && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }

            answer = std::max(answer, dp[i]);
        }

        return answer;
    }
};