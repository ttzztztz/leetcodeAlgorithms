class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m + 1][n + 1];
        std::memset(dp, 0, sizeof(dp));
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];

            int number1Count = 0, number0Count = 0;
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == '0') {
                    number0Count++;
                } else if (str[j] == '1') {
                    number1Count++;
                }
            }

            for (int a = m; a >= 0; a--) {
                for (int b = n; b >= 0; b--) {
                    if (a >= number0Count && b >= number1Count) {
                        dp[a][b] = std::max(dp[a][b], dp[a - number0Count][b - number1Count] + 1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};