class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        const int N = A.size();
        if (N <= 2) {
            return 0;
        }
        vector<unordered_map<long long, int>> f(N + 1);
        long long answer = 0;
        
        f[1][(long long) A[1] - A[0]]++;
        for (int i = 2; i < N; i++) {
            for (int j = 0; j < i; j++) {
                const long long d = (long long) A[i] - A[j];
                f[i][d]++;
                
                f[i][d] += f[j][d];
                answer += f[j][d];
            }
        }
        
        return answer;
    }
};
