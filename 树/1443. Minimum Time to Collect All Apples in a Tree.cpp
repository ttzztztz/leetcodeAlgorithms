class Solution {
public:
    int minTime(int n, vector<vector<int>>& ed, vector<bool>& hasApple) {
        this->hasApple = hasApple;
        for (auto apple : hasApple) {
            if (apple) total_cnt++;
        }
        edges = vector<vector<int>>(n, vector<int>{});
        for (auto& e : ed) {
            edges[e[0]].push_back(e[1]);
            edges[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        return ans;
    }
private:
    vector<vector<int>> edges;
    vector<bool> hasApple;
    int total_cnt = 0;

    int ans = 0;
    int dfs(int u, int parent) {
        int total_apples = 0;
        if (hasApple[u]) total_apples++;

        for (int v : edges[u]) {
            if (v == parent) continue;

            const int apple_collected = dfs(v, u);
            total_apples += apple_collected;
            if (apple_collected > 0) {
                ans += 2;
            }
        }
        return total_apples;
    }
};