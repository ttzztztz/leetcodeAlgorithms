class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->n = n, this->m = m, this->target = target;
        memset(f, 0xff, sizeof f);
        long long answer = dfs(houses, cost, 0, 0, target);
        
        if (answer >= 99999999) return -1;
        else return answer;
    }
private:
    int n, m, target;
    long long f[105][25][105];
    long long dfs(vector<int>& houses, vector<vector<int>>& cost, int cur, int last, int remain) {
        if (cur == m) {
            if (remain == 0) return 0;
            else return 99999999;
        }
        if (remain < 0) return 99999999;
        long long& val = f[cur][last][remain];
        if (val != -1) return val;
        
        if (houses[cur] != 0) {
            if (last == houses[cur]) return val = dfs(houses, cost, cur + 1, houses[cur], remain);
            else return val = dfs(houses, cost, cur + 1, houses[cur], remain - 1);
        }
        
        long long answer = 99999999;
        for (int k = 1; k <= n; k++) {
            if (last == k) answer = min(answer, cost[cur][k - 1] + dfs(houses, cost, cur + 1, k, remain));
            else answer = min(answer, cost[cur][k - 1] + dfs(houses, cost, cur + 1, k, remain - 1));
        }
        return val = answer;
    }
};
