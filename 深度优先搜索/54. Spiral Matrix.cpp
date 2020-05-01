class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return answer;
        N = matrix.size(), M = matrix[0].size();
        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        
        dfs(matrix, 0, 0, 0);
        return answer;
    }
private:
    int N, M;
    vector<int> answer;
    vector<vector<bool>> visited;
    void dfs(const vector<vector<int>>& matrix, int i, int j, int dir) {
        answer.push_back(matrix[i][j]);
        visited[i][j] = true;
        
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            const int d = (dir + k) % 4;
            const int nx = i + dx[d], ny = j + dy[d];
            
            if (pointValid(nx, ny) && !visited[nx][ny]) {
                dfs(matrix, nx, ny, d);
                break;
            }
        }
        
    }
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
};
