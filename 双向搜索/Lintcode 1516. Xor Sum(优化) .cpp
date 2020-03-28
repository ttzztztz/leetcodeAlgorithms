class Solution {
public:
    /**
     * @param arr: the arr 
     * @param target: the target
     * @return: the sum of paths 
     */
    long long xorSum(vector<vector<int>> &arr, int target) {
        N = arr.size(), M = arr[0].size();
        f = vector<unordered_map<int, long long>>(N);
        
        dfs_reverse(arr, N - 1, M - 1, 0);
        return dfs(arr, 0, 0, target);
    }
private:
    int N, M;
    vector<unordered_map<int, long long>> f;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    void dfs_reverse(const vector<vector<int>> &arr, int u, int v, int current) {
        if (u + v == (N + M) / 2) {
            f[u][current ^ arr[u][v]]++;
            return;
        }
        
        if (pointValid(u - 1, v)) {
            dfs_reverse(arr, u - 1, v, current ^ arr[u][v]);
        }
        if (pointValid(u, v - 1)) {
            dfs_reverse(arr, u, v - 1, current ^ arr[u][v]);
        }
    }
    
    long long dfs(const vector<vector<int>> &arr, int u, int v, int current) {
        if (u + v == (N + M) / 2) {
            return f[u][current];
        }
        
        long long answer = 0;
        if (pointValid(u + 1, v)) answer += dfs(arr, u + 1, v, current ^ arr[u][v]);
        if (pointValid(u, v + 1)) answer += dfs(arr, u, v + 1, current ^ arr[u][v]);
        return answer;
    }
};
