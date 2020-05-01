class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        this->n = n;
        answer = vector<vector<int>>(n, vector<int>(n, -1));
        dfs(0, 0, 0, 1);
        return answer;
    }
private:
    vector<vector<int>> answer;
    int n;
    void dfs(int i, int j, int dir, int num) {
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        answer[i][j] = num;
        
        for (int k = 0; k < 4; k++) {
            const int d = (k + dir) % 4;
            const int nx = i + dx[d], ny = j + dy[d];
            
            if (pointValid(nx, ny) && answer[nx][ny] == -1) {
                dfs(nx, ny, d, num + 1);
                break;
            }
        }
    }
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
};
