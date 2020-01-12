#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int T = 0;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        int N = 0, Q = 0, answer = 0;
        cin >> N >> Q;
        string str;
        cin >> str;
        vector<vector<int>> prefixSum(N + 1, vector<int>(26, 0));

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 26; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + (str[i - 1] == j + 'A');
            }
        }

        for (int i = 0; i < Q; i++) {
            int L, R;
            cin >> L >> R;

            const int len = R - L + 1;
            vector<int> appear(26, 0);
            for (int j = 0; j < 26; j++) {
                appear[j] = prefixSum[R][j] - prefixSum[L - 1][j];
            }

            int oddNumber = 0;
            if (len % 2 == 1) oddNumber = 1;

            for (int j = 0; j < 26; j++) {
                if (appear[j] % 2 == 1) {
                    oddNumber--;
                }

                if (oddNumber < 0) break;
            }

            if (oddNumber >= 0) answer++;
        }
        printf("Case #%d: %d\n", _, answer);
    }
    return 0;
}