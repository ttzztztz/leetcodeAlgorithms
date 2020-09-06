#include "iostream"
#include "vector"
#include "unordered_set"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "limits"
#include "cstring"
#include "queue"
#include "deque"

using namespace std;
vector<int> v;
int N;
int f[10005][5];

int dfs(int i, int last) {
    if (i == N) return 0;
    if (last < 0 || last >= 4) {
        int answer = 9999999;
        for (int k = 0; k < 4; k++) {
            answer = min(answer, 1 + dfs(i, k));
        }
        return answer;
    }

    int& val = f[i][last];
    if (val != -1) return val;
    int answer = 9999999;

    if (v[i] > v[i - 1]) {
        for (int x = 0; x < 4; x++) {
            if (x > last) answer = min(answer, dfs(i + 1, x));
            else answer = min(answer, 1 + dfs(i + 1, x));
        }
    } else if (v[i] == v[i - 1]) {
        answer = min(answer, dfs(i + 1, last));
    } else if (v[i] < v[i - 1]) {
        for (int x = 0; x < 4; x++) {
            if (x < last) answer = min(answer, dfs(i + 1, x));
            else answer = min(answer, 1 + dfs(i + 1, x));
        }
    }

    return val = answer;
}

int main() {
    int T;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        v.clear();
        memset(f, 0xff, sizeof f);

        cin >> N;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        int answer = N + 1;
        for (int i = 0; i < 4; i++) {
            answer = min(answer, dfs(1, i));
        }

        printf("Case #%d: %d\n", _, answer);
    }
    return 0;
}