class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        vector<int> solve;
        int p = 0, q = 1, N = A.size();

        double left = 0.0, right = 1.0;
        while (left <= right) {
            double middle = (left + right) / 2.0;
            int answer = 0;
            p = 0, q = 1;

            for (int leftPtr = 0, rightPtr = 0; leftPtr < N; leftPtr++) {
                while (rightPtr < N && (double)A[leftPtr] * 1.0 > (double)A[rightPtr] * 1.0 * middle) {
                    rightPtr++;
                }

                answer += N - rightPtr;
                if (rightPtr < N && p * A[rightPtr] < A[leftPtr] * q) {
                    p = A[leftPtr], q = A[rightPtr];
                }
            }

            if (answer > K) {
                right = middle;
            } else if (answer < K) {
                left = middle;
            } else {
                solve.push_back(p);
                solve.push_back(q);

                return solve;
            }
        }

        solve.push_back(p);
        solve.push_back(q);
        return solve;
    }
};