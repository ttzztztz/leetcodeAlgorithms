#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 12, M = (1 << 12) - 1;
int a, b;
long long dp[N][M];
bool valid[M];
vector<vector<int>> states(M, vector<int>{});

int main() {
    while ((cin >> a >> b), a || b) {
        for (int i = 0; i < 1 << a; i++) {
            int cnt = 0;
            bool is_ok = true;

            for (int j = 0; j < a; j++) {
                if (i & (1 << j)) {
                    if (cnt % 2 == 1) {
                        is_ok = false;
                        cnt = 0;
                    }
                } else {
                    cnt++;
                }
            }

            if (cnt % 2 == 1) {
                is_ok = false;
            }
            valid[i] = is_ok;
        }

        states = vector<vector<int>>(1 << a, vector<int>{});
        for (int i = 0; i < 1 << a; i++) {
            for (int j = 0; j < 1 << a; j++) {
                if ((i & j) == 0 && valid[i | j]) {
                    states[i].push_back(j);
                }
            }
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int i = 1; i <= b; i++) {
            for (int j = 0; j < 1 << a; j++) {
                for (int k : states[j]) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }

        cout << dp[b][0] << endl;
    }
    return 0;
}
