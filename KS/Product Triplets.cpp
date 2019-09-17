#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        int N = 0;
        cin >> N;
        int arr[N + 1];
        long long answer = 0L;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        sort(arr + 1, arr + N + 1);
        int occurCount[200005];
        memset(occurCount, 0, sizeof(occurCount));

        for (int i = N; i >= 1; i--) {
            for (int j = 1; j < i; j++) {
                if (arr[i] == 0 || arr[i] == 1 || arr[j] == 0 || arr[j] == 1) {
                    continue;
                }

                if (1L * arr[i] * arr[j] <= 200000L) {
                    answer += occurCount[arr[i] * arr[j]];
                }
            }
            occurCount[arr[i]]++;
        }

        // <- process 0

        // <- use 3x0
        answer += 1L * occurCount[0] * (occurCount[0] - 1) * (occurCount[0] - 2) / 6;
        // <- use 2x0
        answer += 1L * occurCount[0] * (occurCount[0] - 1) / 2 * (N - occurCount[0]);

        // <- process 1

        // <- use 3x1
        answer += 1L * occurCount[1] * (occurCount[1] - 1) * (occurCount[1] - 2) / 6;
        // <- use 1x1
        for (int i = 2; i <= 200000; i++) {
            answer += 1L * occurCount[i] * (occurCount[i] - 1) / 2 * occurCount[1];
        }

        printf("Case #%d: %lld \n", _, answer);
    }
    return 0;
}