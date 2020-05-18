#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

const int LIM = 1e7;
int f[2 * LIM + 20];

int main() {
    int T;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        int N;
        cin >> N;

        vector<int> all(N);
        for (int i = 0; i < N; i++) {
            cin >> all[i];
        }

        memset(f, 0, sizeof f);
        int cur = LIM;
        f[cur]++;

        for (int right = 0; right < N; right++) {
            cur += all[right];
            for (int i = 0; cur - i * i >= 0; i++) {
                const long long h = i * i;
                answer += f[cur - h];
            }
            f[cur]++;
        }

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}