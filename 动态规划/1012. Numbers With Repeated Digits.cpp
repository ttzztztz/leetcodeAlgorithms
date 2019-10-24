const int MAX = 15;

class Solution {
public:
    int dp[MAX][2][2][1050][2];
    int digest[MAX], digestLen;

    int dfs(int length, int isSmall, int isZero, int state, int repeated) {
        if (length == 0) {
            return repeated == 1 ? 1: 0;
        }

        if (dp[length][isSmall][isZero][state][repeated] != -1) {
            return dp[length][isSmall][isZero][state][repeated];
        }

        int answer = 0;
        for (int i = 0; i <= 9; i++) {
            if (!isSmall && digest[length] < i) {
                break;
            }

            if (i || !isZero) {
                int newState = state, newRepeated = repeated;
                if (newState & (1 << i)) {
                    newRepeated = 1;
                } else {
                    newState |= 1 << i;
                }

                answer += dfs(
                        length - 1,
                        isSmall || digest[length] > i,
                        isZero && i == 0,
                        newState,
                        newRepeated
                );

            } else {
                answer += dfs(
                        length - 1,
                        isSmall || digest[length] > i,
                        isZero && i == 0,
                        state,
                        repeated
                );
            }
        }
        return dp[length][isSmall][isZero][state][repeated] = answer;
    }

    int numDupDigitsAtMostN(int N) {
        std::memset(dp, 0xff, sizeof(dp));
        std::memset(digest, 0, sizeof(digest));
        digestLen = 0;

        int newN = N;
        while (newN) {
            digest[++digestLen] = newN % 10;
            newN /= 10;
        }

        return dfs(digestLen, 0, 1, 0, 0);
    }
};