class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        const int N = A.size();
        vector<int> flipArr(N, 0);
        int state = 0, answer = 0;

        for (int i = 0; i < N; i++) {
            if (i >= K) {
                state ^= flipArr[i - K];
            }
            if ((A[i] ^ state) == 0) {
                answer++;

                if (i + K - 1 >= N) {
                    return -1;
                }

                flipArr[i] = 1;
                state ^= 1;
            }
        }
        return answer;
    }
};