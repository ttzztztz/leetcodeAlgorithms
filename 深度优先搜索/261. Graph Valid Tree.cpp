class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        e = vector<vector<int>>(n);
        visited = vector<bool>(n, false);
        for (const auto& ed : edges) {
            e[ed[0]].push_back(ed[1]);
            e[ed[1]].push_back(ed[0]);
        }

        if (!dfs(0, -1)) return false;
        for (const bool & b : visited) if (!b) return false; // not connected
        return true;
    }
private:
    vector<vector<int>> e;
    vector<bool> visited;
    bool dfs(int u, int parent) {
        visited[u] = true;

        for (int v : e[u]) {
            if (v == parent) continue;

            if (visited[v]) return false;
            visited[v] = true;
            if (!dfs(v, u)) return false;
        }
        return true;
    }
};