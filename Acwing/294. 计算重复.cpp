#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
char s1[N], s2[N];
int n1, n2;
long long f[N][31];

int main() {
    while (cin >> s2 >> n2 >> s1 >> n1) {
        const int len1 = strlen(s1), len2 = strlen(s2);
        // prepare f[i][0]
        bool valid = true;
        for (int i = 0; i < len1; i++) {
            int pos = i;
            f[i][0] = 0;

            for (int j = 0; j < len2; j++) {
                int cnt = 0;
                while (s1[pos] != s2[j]) {
                    pos = (pos + 1) % len1;
                    cnt++;

                    if (cnt >= len1) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) {
                    break;
                }
                pos = (pos + 1) % len1;
                f[i][0] += cnt + 1;
            }

            if (!valid) {
                break;
            }
        }
        if (!valid) {
            cout << 0 << endl;
            continue;
        }

        // dp
        for (int j = 1; j <= 30; j++) {
            for (int i = 0; i < len1; i++) {
                f[i][j] = f[i][j - 1] + f[(i + f[i][j - 1]) % len1][j - 1];
            }
        }

        // greedy get answer
        long long answer = 0;
        for (int i = 0; i < len1; i++) {
            int ptr = i;
            long long tmp = 0;
            for (int k = 30; k >= 0; k--) {
                if (f[ptr % len1][k] + ptr <= len1 * n1) {
                    tmp |= 1 << k;
                    ptr += f[ptr % len1][k];
                }
            }
            answer = max(answer, tmp);
        }
        cout << (answer / n2) << endl;
    }
    return 0;
}
