class Solution {
public:
    /**
     * @param A: the A array
     * @param B: the B array
     * @return: return the maxium inner product of B and C
     */
    long long getMaxInnerProduct(vector<int> &A, vector<int> &B) {
        N = A.size(), K = B.size();
        memset(f, 0xff, sizeof f);
        
        return dfs(A, B, 0, N - 1);
    }
private:
    int N, K;
    long long f[2005][2005];
    long long dfs(vector<int> &A, vector<int> &B, int i, int j) {
        const int cur = j - i + 1, used = N - cur;
        if (used == K) return 0;
        if (f[i][j] != -1) return f[i][j];
        
        long long answer = numeric_limits<long long>::min();
        answer = max(answer, 1ll * B[used] * 1ll * A[i] + dfs(A, B, i + 1, j));
        answer = max(answer, 1ll * B[used] * 1ll * A[j] + dfs(A, B, i, j - 1));
        return f[i][j] = answer;
    }
};
