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

using namespace std;
vector<long long> all;
long long N, D;

long long judge(long long k) {
    long long answer = k;
    for (long long i : all) {
        if (answer % i != 0) {
            const long long k = answer / i;
            answer = i * (k + 1);
        }
//        else answer = max(answer, (answer / i) + i);
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        cin >> N >> D;
        all.clear();
        for (int i = 0; i < N; i++) {
            long long tmp;
            cin >> tmp;
            all.push_back(tmp);
        }

        long long left = 1, right = D;
        while (left <= right) {
            const long long mid = (left + right) >> 1;

            if (judge(mid) <= D) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        answer = right;
        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
