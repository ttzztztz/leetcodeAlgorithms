#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        int N = 0, O = 0, M = 0, L = 0;
        long long D = 0L, X1 = 0L, X2 = 0L, A = 0L, B = 0L, C = 0L;

        cin >> N >> O >> D;
        cin >> X1 >> X2 >> A >> B >> C >> M >> L;
        vector<long long> S;
        S.resize(N + 1);
        vector<long long> sum;
        sum.resize(N + 1);

        // <- generate data
        sum[0] = 0L;
        S[1] = X1 + L;
        sum[1] = sum[0] + S[1];
        S[2] = X2 + L;
        sum[2] = sum[1] + S[2];
        for (int i = 3; i <= N; i++) {
            long long newX = (A * X2 + B * X1 + C) % M;
            swap(X1, X2);
            X2 = newX;

            S[i] = newX + L;
            sum[i] = sum[i - 1] + S[i];
        }

        // <- solve problem
        long long answer = LLONG_MIN;
        multiset<long long> set;

        for (int leftPtr = 1, rightPtr = 1, oddCount = 0; leftPtr <= N; leftPtr++) {
            while (rightPtr <= N && oddCount + (S[rightPtr] % 2) <= O) {
                set.insert(sum[rightPtr]);
                if (S[rightPtr] % 2) {
                    oddCount++;
                }
                rightPtr++;
            }

            if (leftPtr < rightPtr) {
                long long findNumber = D + sum[leftPtr - 1];
                auto it = set.lower_bound(sum[leftPtr - 1] + D + 1);
                if (it != set.begin()) {
                    it--;
                    answer = std::max(answer, (*it - sum[leftPtr - 1]));
                }

                if (S[leftPtr] % 2) {
                    oddCount--;
                }
                set.erase(set.find(sum[leftPtr]));
            } else {
                rightPtr = leftPtr + 1;
                set.clear();
            }

        }
        // <- output result
        printf("Case #%d: ", _);

        if (answer == LLONG_MIN) {
            printf("IMPOSSIBLE");
        } else {
            printf("%lld", answer);
        }
        printf(" \n");
    }
    return 0;
}
