class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        const int N = costs.size();
        memset(f, 0xff, sizeof f);
        return dfs(costs, 0, N / 2, N / 2);
    }
private:
    int f[105][105][105];
    int dfs(vector<vector<int>>& costs, int i, int a_left, int b_left) {
        const int N = costs.size();
        if (a_left < 0 || b_left < 0) return 99999999;
        if (i == N) return 0;
        if (f[i][a_left][b_left] != -1) return f[i][a_left][b_left];
        
        int answer = 99999999;
        answer = min(answer, costs[i][0] + dfs(costs, i + 1, a_left - 1, b_left));
        answer = min(answer, costs[i][1] + dfs(costs, i + 1, a_left, b_left - 1));
        return f[i][a_left][b_left] = answer;
    }
};
