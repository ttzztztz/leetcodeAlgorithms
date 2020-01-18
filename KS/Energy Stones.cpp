#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Good {
public:
    int s, e, l;

    Good() : s(0), e(0), l(0) {};

    Good(int _s, int _e, int _l) : s(_s), e(_e), l(_l) {};
};

int main() {
    int T;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        int N, totalS = 0, answer = 0;
        cin >> N;
        vector<Good> goodList;
        for (int i = 0; i < N; i++) {
            int S, E, L;
            cin >> S >> E >> L;
            goodList.emplace_back(S, E, L);
            totalS += S;
        }

        vector<vector<int>> dp(105, vector<int>(10005, 0));
        sort(goodList.begin(), goodList.end(), [](const Good &$1, const Good &$2) -> bool {
            return $1.s * $2.l < $2.s * $1.l;
        });

        for (int i = 1; i <= N; i++) {
            const Good &g = goodList[i - 1];

            for (int j = 0; j <= totalS; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= g.s) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i - 1][j - g.s] + max(0, g.e - (j - g.s) * g.l));
                }

                answer = max(answer, dp[i][j]);
            }
        }

        printf("Case #%d: %d\n", _, answer);
    }
    return 0;
}