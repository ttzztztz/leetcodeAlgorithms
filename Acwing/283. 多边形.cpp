#include <iostream>
#include <algorithm>

using namespace std;

long long dp_max[110][110], dp_min[110][110];
int N;
int number[110];
char opt[110];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        char ch;
        int n;
        cin >> ch >> n;

        number[i] = number[i + N] = n;
        opt[i] = opt[i + N] = ch;
    }

    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 110; j++) {
            dp_max[i][j] = -9999999999;
            dp_min[i][j] = 9999999999;
        }
    }

    for (int i = 1; i <= N * 2; i++) dp_max[i][i] = dp_min[i][i] = number[i];

    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len - 1 <= 2 * N; i++) {
            const int j = i + len - 1;
            long long _max = -9999999999, _min = 9999999999;

            for (int k = i; k + 1 <= j; k++) {
                if (opt[k + 1] == 't') {
                    _max = max(_max, dp_max[i][k] + dp_max[k + 1][j]);
                    _min = min(_min, dp_min[i][k] + dp_min[k + 1][j]);
                } else {
                    _max = max(_max, dp_max[i][k] * dp_max[k + 1][j]);
                    _max = max(_max, dp_min[i][k] * dp_min[k + 1][j]);

                    _min = min(_min, dp_min[i][k] * dp_min[k + 1][j]);
                    _min = min(_min, dp_min[i][k] * dp_max[k + 1][j]);
                    _min = min(_min, dp_max[i][k] * dp_min[k + 1][j]);
                    _min = min(_min, dp_max[i][k] * dp_max[k + 1][j]);
                }
            }

            dp_max[i][j] = _max;
            dp_min[i][j] = _min;
        }
    }

    long long max_answer = -9999999999;
    for (int i = 1; i + N - 1 <= 2 * N; i++) {
        const int j = i + N - 1;
        max_answer = max(max_answer, dp_max[i][j]);
    }
    cout << max_answer << endl;
    for (int i = 1; i <= N; i++) {
        if (dp_max[i][i + N - 1] == max_answer) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
