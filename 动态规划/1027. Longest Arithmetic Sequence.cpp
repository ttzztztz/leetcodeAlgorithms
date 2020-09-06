class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        const int N = A.size();
        vector<vector<int>> f(N + 1, vector<int>(20005, 1));
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                const int d = A[i] - A[j] + 10000;
                f[i][d] = max(f[i][d], f[j][d] + 1);
                answer = max(answer, f[i][d]);
            }
        }
        return answer;
    }
};