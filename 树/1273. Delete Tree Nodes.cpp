class Solution {
public:
    vector<vector<int>> next;
    vector<bool> valid;
    int dfs1(int u, const vector<int>& value) {
        int sum = value[u];
        for (int i = 0; i < next[u].size(); i++) {
            sum += dfs1(next[u][i], value);
        }

        if (sum == 0) {
            valid[u] = false;
        }
        return sum;
    }

    int dfs2(int u) {
        if (!valid[u]) {
            return 0;
        }

        int current = 1;
        for (int i = 0; i < next[u].size(); i++) {
            current += dfs2(next[u][i]);
        }

        return current;
    }

    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        next = vector<vector<int>>(nodes + 5, vector<int>()), valid = vector<bool>(nodes + 5, true);
        for (int i = 1; i < nodes; i++) {
            next[parent[i]].push_back(i);
        }

        dfs1(0, value);
        return dfs2(0);
    }
};