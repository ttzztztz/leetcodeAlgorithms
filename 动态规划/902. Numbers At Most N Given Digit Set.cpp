const int MAX = 15;

class Solution {
public:
    vector<int> prepare;
    int dp[MAX][2][2];
    int digest[MAX], digestLength;
    int dfs(int length, int isZero, int isSmall) {
        if (length == 0) {
            return isZero ? 0 : 1;
        }

        if (dp[length][isZero][isSmall] != -1) {
            return dp[length][isZero][isSmall];
        }
        int answer = 0;

        for (int i : prepare) {
            if (i == 0 && !isZero) {
                continue;
            }

            if (!isSmall && i > digest[length]) {
                break;
            }

            answer += dfs(
                    length - 1,
                    isZero && i == 0,
                    isSmall || i < digest[length]
            );
        }

        return dp[length][isZero][isSmall] = answer;
    }
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        std::memset(dp, 0xff, sizeof(dp));

        prepare.push_back(0);
        for (int i = 0; i < D.size(); i++) {
            prepare.push_back(D[i][0] - '0');
        }

        digestLength = 0;
        int newN = N;
        while (newN) {
            digest[++digestLength] = newN % 10;
            newN /= 10;
        }

        return dfs(digestLength, 1, 0);
    }
};