#include <iostream>
#include <cstring>

//#define DEBUG 1

using namespace std;

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        int N = 0;
        cin >> N;
        string s;
        cin >> s;
        int number[N + 1], prefixSum[N + 1];
        memset(prefixSum, 0, sizeof(prefixSum));

        for (int i = 1; i <= s.length(); i++) {
            number[i] = s[i - 1] - '0';
            prefixSum[i] = prefixSum[i - 1] + number[i];
        }

        int floodBreakNumber = N / 2, minBreak = 0x7fffffff;
        const int leftStart = 1, rightEnd = N;

        for (int leftLength = 0; leftLength <= floodBreakNumber; leftLength++) {
            int leftEnd = leftStart + leftLength - 1;
            int rightStart = rightEnd - (floodBreakNumber - leftLength) + 1;

            int leftSum = prefixSum[leftEnd] - prefixSum[leftStart - 1];
            int rightSum = prefixSum[rightEnd] - prefixSum[rightStart - 1];

#ifdef DEBUG
            cout << (leftSum + rightSum) << endl;
#endif
            minBreak = std::min(minBreak, leftSum + rightSum);
        }

#ifdef DEBUG
        cout << "Sum" << prefixSum[N] << endl;
#endif

        printf("Case #%d: %d \n", _, prefixSum[N] - minBreak);
    }

    return 0;
}