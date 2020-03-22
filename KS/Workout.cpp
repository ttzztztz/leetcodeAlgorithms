#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> minutes;
long long solve(long long K) {
    const int N = minutes.size();
    long long answer = 0;
    for (int i = 1; i < N; i++) {
        const long long d = minutes[i] - minutes[i - 1];
        if (d >= K) {
            answer += d / K;
            if (d % K == 0) answer--;
        }
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        minutes.clear();

        long long answer = 0;
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            minutes.push_back(tmp);
        }

        long long left = 1, right = minutes.back() - minutes.front();
        while (left <= right) {
            const long long mid = (left + right) / 2;
            if (solve(mid) <= K) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        answer = left;
        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
