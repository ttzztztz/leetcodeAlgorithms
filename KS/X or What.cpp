#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int lowbit(int x) {
    return x & (-x);
}

int bitCount(int x) {
    int answer = 0;
    while (x) {
        answer++;
        x -= lowbit(x);
    }
    return answer;
}

bool isOdd(int x) {
    return bitCount(x) % 2 == 1;
}

int main() {
    int T = 0;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        int N = 0, Q = 0;
        cin >> N >> Q;
        printf("Case #%d:", _);
        vector<int> numbers(N + 5, 0);
        set<pair<int, int>> oddNumber;
        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
            if (isOdd(numbers[i])) {
                oddNumber.emplace(i, numbers[i]);
            }
        }

        for (int i = 0; i < Q; i++) {
            int j, k;
            cin >> j >> k;
            if (isOdd(numbers[j])) {
                oddNumber.erase(oddNumber.find({j, numbers[j]}));
            }
            if (isOdd(k)) {
                oddNumber.emplace(j, k);
            }
            numbers[j] = k;

            int odd = oddNumber.size();
            if (odd % 2 == 0) {
                printf(" %d", N);
            } else {
                auto it1 = oddNumber.begin();
                auto it2 = oddNumber.rbegin();

                printf(" %d",
                       max(N - it1->first - 1, it2->first)
                );
            }
        }

        printf("\n");
    }
    return 0;
}
