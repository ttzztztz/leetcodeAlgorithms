class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int dp[piles.size() + 2][piles.size() + 2][2];
        std::memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= piles.size(); i++) {
            dp[i][i][0] = piles[i - 1];
            dp[i][i][1] = 0;
        }
        for (int l = 2; l <= piles.size(); l++) {
            for (int i = 1; i + l - 1 <= piles.size(); i++) {
                int j = i + l - 1;

                int left = piles[i - 1] + dp[i + 1][j][1], right = piles[j - 1] + dp[i][j - 1][1];
                if (left < right) {
                    dp[i][j][0] = right;
                    dp[i][j][1] = dp[i][j - 1][0];
                } else {
                    dp[i][j][0] = left;
                    dp[i][j][1] = dp[i + 1][j][0];
                }
            }
        }

        return dp[1][piles.size()][0] > dp[1][piles.size()][1];
    }
};