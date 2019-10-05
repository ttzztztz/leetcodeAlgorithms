#include <iostream>
#include <algorithm>
#include <vector>

//#define DEBUG 1

using namespace std;

int main() {
    int dataCount = 0;
    cin >> dataCount;

    for (int dataSet = 1; dataSet <= dataCount; dataSet++) {
        vector<long long> rawData;

        unsigned long long answer = 0L;
        int N = 0, Q = 0;
        cin >> N >> Q;

        vector<long long> X(std::max(N + 1, 5), 0);
        vector<long long> Y(std::max(N + 1, 5), 0);
        vector<long long> Z(std::max(Q + 1, 5), 0);

        int A1, B1, C1, M1, A2, B2, C2, M2, A3, B3, C3, M3;
        cin >> X[1] >> X[2] >> A1 >> B1 >> C1 >> M1;
        cin >> Y[1] >> Y[2] >> A2 >> B2 >> C2 >> M2;
        cin >> Z[1] >> Z[2] >> A3 >> B3 >> C3 >> M3;

        // <-- construct

        vector<int> L(std::max(N + 1, 5), 0);
        vector<int> R(std::max(N + 1, 5), 0);
        for (int i = 3; i <= N; i++) {
            X[i] = (A1 * X[i - 1] + B1 * X[i - 2] + C1) % M1;
            Y[i] = (A2 * Y[i - 1] + B2 * Y[i - 2] + C2) % M2;
        }

        for (int i = 3; i <= Q; i++) {
            Z[i] = (A3 * Z[i - 1] + B3 * Z[i - 2] + C3) % M3;
        }


        for (int i = 1; i <= N; i++) {
            L[i] = std::min(X[i], Y[i]) + 1;
            rawData.push_back(L[i]);
            R[i] = std::max(X[i], Y[i]) + 2;
            rawData.push_back(R[i]);
        }

        std::sort(rawData.begin(), rawData.end());
        auto endIt = std::unique(rawData.begin(), rawData.end());
        const int allNumberCount = endIt - rawData.begin();

        vector<long long> appearCount(allNumberCount + 5, 0);
        vector<long long> suffixSum(allNumberCount + 5, 0);

        for (int i = 1; i <= N; i++) {
            int left = L[i], right = R[i];

            left = std::lower_bound(rawData.begin(), endIt, left) - rawData.begin();
            right = std::lower_bound(rawData.begin(), endIt, right) - rawData.begin();
            appearCount[left]++;
            appearCount[right]--;
        }

        for (int i = 1; i < allNumberCount; i++) {
            appearCount[i] += appearCount[i - 1];
        }
        for (int i = allNumberCount - 1; i >= 0; i--) {
            if (i == allNumberCount - 1) {
                suffixSum[i] = appearCount[i];
            } else {
                suffixSum[i] = suffixSum[i + 1] + appearCount[i] * (rawData[i + 1] - rawData[i]);
            }
        }

        for (long long i = 1L; i <= Q; i++) {
            long long K = Z[i] + 1L;

            if (K > suffixSum[0]) {
                continue;
            }

//            auto rightNumber = std::lower_bound(suffixSum.begin(), suffixSum.begin() + allNumberCount, K,
//                                                greater<>());
//            int rightOffset = rightNumber - suffixSum.begin();
//
////            if (*rightNumber == K) {
////                answer += 1L * i * rawData[rightOffset];
////            } else {
//
//            if (*rightNumber != K) {
//                rightNumber--;
//                rightOffset--;
//            }

            int offset = 0, leftPtr = 0, rightPtr = allNumberCount - 1;
            while (leftPtr <= rightPtr) {
                int middle = (leftPtr + rightPtr) >> 1;
                if (suffixSum[middle] >= K) {
                    leftPtr = middle + 1;
                } else {
                    rightPtr = middle - 1;
                }
            }

            offset = leftPtr - 1;

            long long oneAnswer =
                    rawData[offset] + ((suffixSum[offset] - K) / appearCount[offset]);

            answer += 1L * i * oneAnswer;
//            }
        }
        cout << "Case #" << dataSet << ": " << answer << endl;
    }
    return 0;
}

