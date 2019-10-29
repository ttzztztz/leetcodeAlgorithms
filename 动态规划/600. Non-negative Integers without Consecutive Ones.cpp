class Solution {
public:
    int dp[35][2][2];
    int digit[35], digitLen;
    int dfs(int length, int isSmall, int lastDigit) {
        if (length == 0) {
            return 1;
        }
        if (dp[length][isSmall][lastDigit] != -1) {
            return dp[length][isSmall][lastDigit];
        }

        int answer = 0;
        // <-- fill 0
        answer += dfs(
                length - 1,
                isSmall || digit[length] > 0,
                0
        );
        // <-- fill 1
        if (lastDigit != 1 && (isSmall || digit[length] == 1)) {
            answer += dfs(
                    length - 1,
                    isSmall || digit[length] > 1,
                    1
            );
        }

        return dp[length][isSmall][lastDigit] = answer;
    }
    int findIntegers(int num) {
        std::memset(dp, 0xff, sizeof(dp));
        digitLen = 0;
        int newNum = num;
        while (newNum) {
            digit[++digitLen] = (newNum & 1) ? 1 : 0;
            newNum >>= 1;
        }
        return dfs(digitLen, 0, 0);
    }
};