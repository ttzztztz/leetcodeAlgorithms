#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

const int INF = 10005, MAX = 105;
int dp[MAX][MAX][MAX];
int helper[MAX][MAX];

int main() {
    int T;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        int N, K;
        cin >> N >> K;
        int offset = 0;

        vector<int> A(N + 1, 0);
        vector<int> allNumber;

        unordered_map<int, int> mapNumberToId;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            if (!mapNumberToId.count(A[i])) {
                mapNumberToId[A[i]] = offset++;
                allNumber.push_back(A[i]);
            }
        }

        memset(dp, 0x3f, sizeof(dp));
        memset(helper, 0x3f, sizeof(helper));
        // init
        for (int k = 0; k < offset; k++) {
            if (A[1] == allNumber[k]) {
                dp[1][0][k] = 0;
                helper[1][0] = 0;
            } else {
                dp[1][0][k] = 1;
            }
        }

        // transfer
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= min(K, i - 1); j++) {
                for (int k = 0; k < offset; k++) {
                    if (j == 0) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    } else {
                        dp[i][j][k] = min(dp[i - 1][j][k], helper[i - 1][j - 1]);
                    }

                    dp[i][j][k] += (allNumber[k] != A[i]);
                    helper[i][j] = min(helper[i][j], dp[i][j][k]);
                }
            }
        }

        // answer
        int answer = INF;
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < offset; k++) {
                answer = min(answer, dp[N][j][k]);
            }
        }
        printf("Case #%d: %d\n", _, answer);
    }

    return 0;
}