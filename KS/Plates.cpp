#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        int N, K, P;
        cin >> N >> K >> P;
        vector<vector<long long>> stk(N, vector<long long>{});
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                int b;
                cin >> b;
                stk[i].push_back(b);
            }
        }

        vector<vector<long long>> prefix = stk;
        for (int i = 0; i < N; i++) {
            for (int j = 1; j < K; j++) {
                prefix[i][j] += prefix[i][j - 1];
            }
        }

        vector<long long> f(P + 1);
        for (int i = 0; i < N; i++) {
            for (int V = P; V >= 0; V--) {
                for (int k = 0; k < K; k++) {
                    if (V - k - 1 >= 0) {
                        f[V] = max(f[V], f[V - k - 1] + prefix[i][k]);
                    }
                }
            }
        }

        for (int i = 0; i <= P; i++) answer = max(answer, f[i]);
        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
