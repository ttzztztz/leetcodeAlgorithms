class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int dp[A.size() + 1][B.size() + 1];
        int answer = 0;
        std::memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    answer = std::max(answer, dp[i][j]);
                }
            }
        }

        return answer;
    }
};