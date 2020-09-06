class Solution {
public:
    /**
     * @param arr: the arr 
     * @param target: the target
     * @return: the sum of paths 
     */
    long long xorSum(vector<vector<int>> &arr, int target) {
        N = arr.size(), M = arr[0].size();
        f = vector<vector<HashMap>>(N, vector<HashMap>(M));
        
        dfs_reversed(arr, N - 1, M - 1, arr[N - 1][M - 1]);
        return dfs(arr, 0, 0, target);
    }
private:
    int N, M;
    typedef unordered_map<int, long long> HashMap;
    vector<vector<HashMap>> f;
    void dfs_reversed(const vector<vector<int>> &arr, int u, int v, int current) {
        if (u + v < (N + M) / 2) return;
        
        f[u][v][current] += 1;
        if (pointValid(u - 1, v)) dfs_reversed(arr, u - 1, v, current ^ arr[u - 1][v]);
        if (pointValid(u, v - 1)) dfs_reversed(arr, u, v - 1, current ^ arr[u][v - 1]);
    }
    long long dfs(const vector<vector<int>> &arr, int u, int v, int target) {
        if (u + v >= (N + M) / 2 || f[u][v].count(target)) return f[u][v][target];
        
        long long cur = 0;
        if (pointValid(u + 1, v)) cur += dfs(arr, u + 1, v, target ^ arr[u][v]);
        if (pointValid(u, v + 1)) cur += dfs(arr, u, v + 1, target ^ arr[u][v]);
        return f[u][v][target] = cur;
    }
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
};
