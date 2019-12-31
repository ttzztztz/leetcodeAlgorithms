class Solution {
public:
    vector<bool> visited;
    int N;
    bool valid(int x) {
        return x >= 0 && x < N;
    }
    bool dfs(const vector<int>& arr, int u) {
        if (arr[u] == 0) {
            return true;
        }

        visited[u] = true;
        const int nx = u + arr[u], ny = u - arr[u];

        if (valid(nx) && !visited[nx] && dfs(arr, nx)) {
            return true;
        }
        if (valid(ny) && !visited[ny] && dfs(arr, ny)) {
            return true;
        }

        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        N = arr.size();
        visited = vector<bool>(N + 5, false);

        return dfs(arr, start);
    }
};