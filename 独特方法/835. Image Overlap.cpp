class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int n = A.size();
        
        int answer = 0;
        int f[85][85];
        memset(f, 0, sizeof f);
        
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            if (A[i][j] == 0) continue;
            for (int a = 0; a < n; a++) for (int b = 0; b < n; b++) {
                if (B[a][b] == 0) continue;
                
                answer = max(answer, ++f[a - i + n][b - j + n]);
            }
        }
        return answer;
    }
};
