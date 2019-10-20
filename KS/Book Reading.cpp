#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int testCase = 0;
    cin >> testCase;
    for (int _ = 1; _ <= testCase; _++) {
        long long answer = 0L;

        int N, M, Q;
        cin >> N >> M >> Q;
        vector<long long> R;
        unordered_map<long long, int> P;
        for (int i = 0; i < M; i++) {
            long long number = 0;
            cin >> number;
            P[number] = 1;
        }
        for (int i = 0; i < Q; i++) {
            long long number = 0;
            cin >> number;
            R.push_back(number);
        }

        vector<long long> F(100005, 0);
        for (int i = 1; i <= N; i++) {
            long long temp = 0;

            for (int j = 1; j * i <= N; j++) {
                if (!P.count(j * i)) {
                    temp++;
                }
            }

            F[i] = temp;
        }
        for (int i = 0; i < Q; i++) {
            answer += F[R[i]];
        }

        printf("Case #%d: %lld \n", _, answer);
    }
    return 0;
}