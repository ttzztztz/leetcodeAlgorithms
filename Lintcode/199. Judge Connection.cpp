class Solution {
public:
    /**
     * @param arr: the arr
     * @param k: the k
     * @return: if all instances of value k in arr are connected
     */
    bool judgeConnection(vector<vector<int>> &arr, int k) {
        if (arr.empty()) return false;
        N = arr.size(), M = arr[0].size();
        memset(visited, 0, sizeof visited);
        
        int tmp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && arr[i][j] == k) {
                    tmp++;
                    dfs(i, j, k, arr);
                }
            }
        }
        return tmp == 1;
    }
private:
    int N, M;
    bool visited[1005][1005];
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    void dfs(int i, int j, int m, vector<vector<int>> &arr) {
        visited[i][j] = true;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (pointValid(nx, ny) && arr[nx][ny] == m && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(nx, ny, m, arr);
            }
        }
    }
};
