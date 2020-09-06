class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        memset(f, 0xff, sizeof f);
        
        return dfs(cuts, 0, cuts.size() - 1, 0, n);
    }
private:
    long long f[105][105];
    long long dfs(vector<int>& cuts, int i, int j, int l, int r) {
        if (i == j) return r - l;
        if (i > j) return 0;
        
        long long& val = f[i][j];
        if (val != -1) return val;
        long long answer = 999999999;
        
        for (int k = i; k <= j; k++) {
            long long lft = dfs(cuts, i, k - 1, l, cuts[k]);
            long long rgt = dfs(cuts, k + 1, j, cuts[k], r);
            long long cost = r - l;
            answer = min(answer, cost + lft + rgt);
        }
        
        return val = answer;
    }
};
