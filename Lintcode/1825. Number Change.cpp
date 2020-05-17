class Solution {
public:
    /**
     * @param k: integer k
     * @return: minimum number of operations that change 0 to k
     */
    int numberChange(int k) {
        memset(f, 0xff, sizeof f);
        return dfs(k, 0);
    }
private:
    int f[100005];
    int dfs(const int k, int u) {
        if (u == k) return 0;
        if (u > k) return 9999999;
        if (f[u] != -1) return f[u];
        
        int answer = 9999999;
        
        answer = min(answer, 1 + dfs(k, u + 1));
        if (u > 0) answer = min(answer, 1 + dfs(k, 2 * u));
        
        return f[u] = answer;
    }
};
