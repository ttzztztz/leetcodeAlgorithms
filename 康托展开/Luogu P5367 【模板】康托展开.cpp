#include <iostream>

using namespace std;

const int MAX = 1e6 + 5;
const long long MOD = 998244353;

long long frac[MAX], arr[MAX];
int bit[MAX];

int lowbit(int x) {
    return x & (-x);
}

int query(int x) {
    int answer = 0;
    while (x) {
        answer += bit[x];
        x -= lowbit(x);
    }
    return answer;
}

void inc(int x, int y) {
    while (x && x <= MAX) {
        bit[x] += y;
        x += lowbit(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    frac[0] = frac[1] = 1;
    for (int i = 2; i <= N; i++) {
        frac[i] = (frac[i - 1] * i) % MOD;
    }

    for (int i = 1; i <= N; i++) inc(i, 1);

    long long answer = 0;
    for (int i = 1; i < N; i++) {
        int sum = query(arr[i]) - 1;
        answer += sum * frac[N - i];
        answer %= MOD;
        inc(arr[i], -1);
    }
    cout << (answer + 1) % MOD << endl;
    return 0;
}
