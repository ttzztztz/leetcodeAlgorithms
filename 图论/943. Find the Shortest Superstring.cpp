class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        const int N = A.size(), mask = (1 << N) - 1;
        vector<vector<int>> f(1 << N, vector<int>(N, 999999)), h(1 << N, vector<int>(N, -1));
        vector<vector<int>> g(N, vector<int>(N, 0));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    g[i][j] = A[i].size();
                    continue;
                }
                g[i][j] = A[j].size();
                for (int k = min(A[i].size(), A[j].size()); k >= 1; k--) {
                    if (A[i].substr(A[i].size() - k, k) == A[j].substr(0, k)) {
                        g[i][j] = A[j].size() - k;
                        break;
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++) f[1 << i][i] = g[i][i];
        
        for (int i = 1; i <= mask; i++) {
            for (int j = 0; j < N; j++) {
                if (!(i & (1 << j))) continue;
                
                for (int k = 0; k < N; k++) {
                    if (j == k || !(i & (1 << k))) continue;
                    if (f[i ^ (1 << j)][k] + g[k][j] < f[i][j]) {
                        f[i][j] = f[i ^ (1 << j)][k] + g[k][j];
                        h[i][j] = k;
                    }
                }
                
            }
        }
        
        int state = mask, j = 0, min_len = numeric_limits<int>::max();
        for (int i = 0; i < N; i++) {
            if (f[mask][i] < min_len) {
                min_len = f[mask][i];
                j = i;
            }
        }
        
        string answer;
        while (state) {
            int prev = h[state][j];
            if (prev == -1) answer = A[j] + answer;
            else answer = A[j].substr(A[j].size() - g[prev][j]) + answer;
            
            state ^= 1 << j;
            j = prev;
        }
        return answer;
    }
};
