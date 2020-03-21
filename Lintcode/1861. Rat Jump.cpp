class Solution {
public:
    /**
     * @param arr: the steps whether have glue
     * @return: the sum of the answers
     */
    int ratJump(vector<int> &arr) {
        const int N = arr.size();
        f = vector<vector<int>>(N + 1, vector<int>(2, -1));
        return dfs(0, 1, arr);
    }
private:
    vector<vector<int>> f;
    int dfs(int u, int times, const vector<int>& arr) {
        const int N = arr.size();
        
        if (u >= N) return 1;
        if (arr[u] == 1) return 0;
        if (u == N - 1) return arr[u] == 1 ? 0 : 1;
        
        const int MOD = 1e9+7;
        if (f[u][times] != -1) return f[u][times];
        
        long long answer = 0;
        answer += dfs(u + 1, times ^ 1, arr);
        answer %= MOD;
        
        if (times == 1) { // odd
            answer += dfs(u + 2, times ^ 1, arr);
        } else { // even
            answer += dfs(u + 3, times ^ 1, arr);
        }
        answer %= MOD;
        
        answer += dfs(u + 4, times ^ 1, arr);
        answer %= MOD;
        
        return f[u][times] = answer;
    }
};
