class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int answer = 0;
        const int N = A.size(), M = A[0].size();
        vector<int> flipRow(N, 0);
        
        for (int j = 0; j < M; j++) {
            int temp = 0;
            if (j == 0) {
                for (int i = 0; i < N; i++) {
                    if (A[i][0] == 0) {
                        flipRow[i] = 1;
                    }
                }
                temp = N;
            } else {
                int _0count = 0, _1count = 0;
                for (int i = 0; i < N; i++) {
                    if (A[i][j] ^ flipRow[i] == 1) _1count++;
                    else _0count++;
                }
                temp = max(_0count, _1count);
            }
            
            answer += temp * (1 << (M - j - 1));
        }
        
        return answer;
    }
};
