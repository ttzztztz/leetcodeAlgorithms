class Solution {
public:
    int dp[10];
    int A9(int m) {
        if (m >= 10) {
            return 0;
        } else if (dp[m]) {
            return dp[m];
        } else {
            return dp[m] = dp[m - 1] * (9 - m + 1);
        }
    }

    int countNumbersWithUniqueDigits(int n) {
        std::memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = 9;

        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 10;
        }

        int answer = 10;
        for (int i = 2; i <= n && i <= 10; i++) {
            answer += 9 * A9(i - 1);
        }
        return answer;
    }
};