#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    int T = 0;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        int N = 0, P = 0, answer = numeric_limits<int>::max();
        cin >> N >> P;
        vector<int> S(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        sort(S.begin(), S.end());

        int leftPtr = 0, rightPtr = 0, sum = 0;
        map<int, int> occurrence;
        while (rightPtr < P) {
            occurrence[S[rightPtr]]++;
            sum += S[rightPtr];

            rightPtr++;
        }

        while (rightPtr <= N) {
            auto it = occurrence.rbegin();

            answer = min(answer, it->first * P - sum);
            if (rightPtr < N) {
                if (--occurrence[S[leftPtr]] == 0) {
                    occurrence.erase(S[leftPtr]);
                }

                sum += S[rightPtr];
                sum -= S[leftPtr];
                occurrence[S[rightPtr]]++;
            }

            leftPtr++;
            rightPtr++;
        }

        printf("Case #%d: %d\n", _, answer);
    }
    return 0;
}