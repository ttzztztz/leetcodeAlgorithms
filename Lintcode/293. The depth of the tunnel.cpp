class Solution {
public:
    /**
     * @param matrix: the matrix in problem
     * @return: the depth of the tunnel.
     */
    int FindDepth(vector<vector<int>> &matrix) {
        N = matrix.size(), M = matrix[0].size();
        dfs(matrix, 0, 0, -1, -1);
        return answer;
    }
private:
    int answer = 0;
    int N = 0, M = 0;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    
    void dfs(vector<vector<int>> &matrix, int i, int j, int s_i, int s_j) {
        answer = max(answer, i);
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (pointValid(nx, ny) && matrix[nx][ny] && !(nx == s_i && ny == s_j)) {
                dfs(matrix, nx, ny, i, j);
            }
        }
    }
};
