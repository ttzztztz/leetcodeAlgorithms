class Solution {
public:
    int countTriplets(vector<int>& A) {
        int answer = 0;
        const int MAX_MASK = (1 << 16) - 1, N = A.size(), MAX_DIGIT = 16;
        vector<int> B(MAX_MASK + 100, 0);

        for (int i = 0; i < N; i++) {
            B[A[i]]++;
        }

        for (int i = 0; i < MAX_DIGIT; i++) {
            for (int j = 0; j <= MAX_MASK; j++) {
                if (j & (1 << i)) {
                    B[j] += B[j ^ (1 << i)];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                answer += B[(~(A[i] & A[j])) & MAX_MASK];
            }
        }

        return answer;
    }
};