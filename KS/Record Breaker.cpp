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

int main() {
    int T;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        int N;
        cin >> N;
        vector<int> v;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        multiset<int> tmp;
        for (int i = 0; i < N; i++) {
            const bool b1 = tmp.empty() || v[i] > *tmp.rbegin();
            const bool b2 = i == N - 1 || v[i] > v[i + 1];

            tmp.insert(v[i]);
            if (b1 && b2) answer++;
        }

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}