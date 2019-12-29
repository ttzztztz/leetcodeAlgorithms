class Solution {
public:
    vector<vector<int>> graph;
    unordered_map<int, pair<int, int>> dp;
    pair<int, int> dfs(int u, const vector<int>& quiet) {
        if (dp.count(u)) {
            return dp[u];
        }

        int minValue = quiet[u], minIndex = u;

        for (int v : graph[u]) {
            int currentValue, currentIndex;

            tie(currentIndex, currentValue) = dfs(v, quiet);
            if (currentValue < minValue) {
                minValue = currentValue;
                minIndex = currentIndex;
            }
        }
        return dp[u] = {minIndex, minValue};
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        const int N = quiet.size();
        vector<int> answer = vector<int>(N, -1);
        graph = vector<vector<int>>(N, vector<int>{});
        for (const vector<int>& rich : richer) {
            graph[rich[1]].push_back(rich[0]);
        }

        for (int i = 0; i < N; i++) {
            answer[i] = dfs(i, quiet).first;
        }
        return answer;
    }
};