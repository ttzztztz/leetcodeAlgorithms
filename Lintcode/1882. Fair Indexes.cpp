class Solution {
public:
    /**
     * @param A: an array of integers
     * @param B: an array of integers
     * @return: return a integer indicating the number of fair indexes.
     */
    int CountIndexes(vector<int> &A, vector<int> &B) {
        vector<long long> f{0}, g{0};
        const int N = A.size();
        for (int i = 0; i < N; i++) {
            f.push_back(1ll * f[i] + 1ll * A[i]);
            g.push_back(1ll * g[i] + 1ll * B[i]);
        }
        
        int answer = 0;
        for (int i = 1; i <= N - 1; i++) {
            const long long a = f[i], b = f[N] - f[i];
            const long long c = g[i], d = g[N] - g[i];
            
            if (a == b && b == c && c == d) answer++;
        }
        return answer;
    }
};
