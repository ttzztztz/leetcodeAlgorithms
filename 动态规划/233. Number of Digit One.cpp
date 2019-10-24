const int MAX = 15, TARGET_DIGEST = 1;

class Solution {
public:
    int dp[MAX][2][MAX][2];
    int digestArr[MAX], digestLen = 0;

    int dfs(int length, int isSmall, int sum, int isZero) {
        if (length == 0) {
            return sum;
        }

        if (dp[length][isSmall][sum][isZero] != -1) {
            return dp[length][isSmall][sum][isZero];
        }

        int answer = 0;
        for (int i = 0; i <= 9; i++) {
            if (!isSmall && i > digestArr[length]) {
                break;
            }

            answer += dfs(
                    length - 1,
                    isSmall || i < digestArr[length],
                    sum + (i == TARGET_DIGEST && (i || !isZero)),
                    isZero && i == 0
            );
        }
        return dp[length][isSmall][sum][isZero] = answer;
    }

    int countDigitOne(int n) {
        std::memset(dp, 0xff, sizeof(dp));
        std::memset(digestArr, 0, sizeof(digestArr));

        int currentN = n;
        while (currentN) {
            digestArr[++digestLen] = currentN % 10;
            currentN /= 10;
        }

        return dfs(digestLen, 0, 0, 1);
    }
};