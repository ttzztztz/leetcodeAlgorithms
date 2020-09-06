class Solution {
public:
    /**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
    string minWindow(string &S, string &T) {
        const int N = S.size(), M = T.size();
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, 999999));
        
        for (int i = 0; i < N; i++) dp[i][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
        
        int answerLen = 999999, answerStart = 0;
        bool findAnswer = false;
        for (int i = 1; i <= N; i++) {
            if (dp[i][M] >= 999999) continue;
            
            const int start = i - dp[i][M];
            findAnswer = true;
            if (answerLen > dp[i][M]) {
                answerLen = dp[i][M];
                answerStart = start;
            }
        }
        
        if (findAnswer) {
            return S.substr(answerStart, answerLen);
        } else {
            return "";
        }
    }
};
