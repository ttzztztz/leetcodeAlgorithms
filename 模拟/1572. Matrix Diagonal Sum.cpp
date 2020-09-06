class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        const int n = mat.size();
        bool visited[105][105];
        memset(visited, 0, sizeof visited);
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i][i]) {
                visited[i][i] = true;
                answer += mat[i][i];
            }
        }
        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                answer += mat[i][j];
            }
        }
        return answer;        
    }
};
