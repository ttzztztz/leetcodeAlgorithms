class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memset(f, 0xff, sizeof f);
        return dfs(A, B, 0, 0);
    }
private:
    int f[505][505];
    int dfs(vector<int>& A, vector<int>& B, int i, int j) {
        const int N = A.size(), M = B.size();
        if (i >= N || j >= M) return 0;
        if (f[i][j] != -1) return f[i][j];
        
        int answer = 0;
        if (A[i] == B[j]) answer = max(answer, 1 + dfs(A, B, i + 1, j + 1));
        answer = max(answer, dfs(A, B, i + 1, j));
        answer = max(answer, dfs(A, B, i, j + 1));
        return f[i][j] = answer;
    }
};
