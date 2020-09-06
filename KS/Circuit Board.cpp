#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int T = 0;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        int R, C, K, answer = 1;
        cin >> R >> C >> K;

        vector<vector<int>> data(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> data[i][j];
            }
        }

        vector<vector<int>> max_len(R, vector<int>(C, 1));
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int maxVal = data[i][j], minVal = data[i][j];
                for (int len = 0; len + j < C; len++) {
                    maxVal = max(maxVal, data[i][j + len]);
                    minVal = min(minVal, data[i][j + len]);

                    if (maxVal - minVal <= K) {
                        max_len[i][j] = len + 1;
                    } else {
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int currLen = max_len[i][j];
                int height = 1;
                while (i + height - 1 < R) {
                    currLen = min(currLen, max_len[i + height - 1][j]);
                    answer = max(answer, currLen * height);
                    height++;
                }
            }
        }

        printf("Case #%d: %d\n", _, answer);
    }
    return 0;
}