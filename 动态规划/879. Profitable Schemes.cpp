const int MOD = 1000000007;

class Solution {
public:
    int G, P, N;
    long long dfs(vector<vector<vector<long long>>>& dp, vector<int>& group, vector<int>& profit, int i, int p, int g) {
        p = std::min(p, 101), g = std::min(g, 101);
        if (i == N) {
            return (p >= P && g <= G) ? 1 : 0;
        }
        if (dp[i][p][g] != -1) {
            return dp[i][p][g];
        }

        long long answer = 0;
        answer = (answer + dfs(dp, group, profit, i + 1, p + profit[i], g + group[i])) % MOD;
        answer = (answer + dfs(dp, group, profit, i + 1, p, g)) % MOD;
        return dp[i][p][g] = answer;
    }

    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<long long>>> dp(105, vector<vector<long long>>(105, vector<long long>(105, -1)));
        this->G = G, this->P = P, this->N = group.size();

        return dfs(dp, group, profit, 0, 0, 0);
    }
};