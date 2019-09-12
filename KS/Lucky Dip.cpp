#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int testCases = 0;
    cin >> testCases;
    for (int _ = 1; _ <= testCases; _++) {
        int N = 0, K = 0;
        cin >> N >> K;

        double expectedArr[K + 1];
        expectedArr[0] = 0.0;
        double valueArr[N + 1], sum[N + 1];
        for (int j = 1; j <= N; j++) {
            cin >> valueArr[j];
            expectedArr[0] += valueArr[j] / (double) N;
        }
        sort(valueArr + 1, valueArr + N + 1);

        sum[0] = 0;
        for (int i = 1; i <= N; i++) {
            sum[i] = sum[i - 1] + valueArr[i];
        }

        for (int i = 1; i <= K; i++) {
            double lastExpected = expectedArr[i - 1];
            double *divider = upper_bound(valueArr, valueArr + N + 1, lastExpected);
            int offset = divider - valueArr;

            expectedArr[i] = ((sum[N] - sum[offset - 1]) + (lastExpected * (offset - 1))) / N;
        }

        printf("Case #%d: %.6lf \n", _, expectedArr[K]);
    }
    return 0;
}