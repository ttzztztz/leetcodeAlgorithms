#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> position, color;
vector<vector<int>> pet, f, g;

void init() {
    position = color = vector<int>(1005, 0);
    f = g = vector<vector<int>>(1005, vector<int>(1005, 1e9));
    pet = vector<vector<int>>(1005, vector<int>{});
}

int main() {
    int T = 0;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        init();
        int N, K, answer = 1e9;
        cin >> N >> K;

        for (int i = 0; i < N; i++) {
            cin >> position[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> color[i];

            pet[color[i]].push_back(position[i]);
        }

        for (int i = 1; i <= 1000; i++) {
            sort(pet[i].begin(), pet[i].end());
        }

        f[0][0] = g[1001][0] = 0;
        for (int i = 1; i <= 1000; i++) {
            for (int j = 0; j <= K; j++) {
                f[i][j] = f[i - 1][j];

                for (int k = 0; k < pet[i].size() && k + 1 <= j; k++) {
                    f[i][j] = min(f[i][j], f[i - 1][j - k - 1] + 2 * pet[i][k]);
                }
            }
        }

        for (int i = 1000; i >= 1; i--) {
            for (int j = 0; j <= K; j++) {
                g[i][j] = g[i + 1][j];

                for (int k = 0; k < pet[i].size() && k + 1 <= j; k++) {
                    g[i][j] = min(g[i][j], g[i + 1][j - k - 1] + 2 * pet[i][k]);
                }
            }
        }

        for (int i = 1; i <= 1000; i++) {
            for (int j = 0; j < pet[i].size() && j + 1 <= K; j++) {
                for (int k = 0; k + j + 1 <= K; k++) {
                    answer = min(answer,
                                 f[i - 1][k] + g[i + 1][K - j - 1 - k] + pet[i][j]);
                }
            }
        }

        printf("Case #%d: %d\n", _, answer);
    }
    return 0;
}