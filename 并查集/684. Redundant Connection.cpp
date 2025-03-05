class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        n = edges.size();
        init();

        for (const vector<int>& edge : edges) {
            const int u = edge[0];
            const int v = edge[1];

            if (find_parent(u) == find_parent(v)) {
                ans = { u, v };
                break;
            }

            merge(u, v);
        }

        return ans;
    }
private:
    int n;
    vector<int> parent;

    void init() {
        parent = vector<int>(n + 1, -1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find_parent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find_parent(parent[u]);
    }

    void merge(int u, int v) {
        const int parent_u = find_parent(u);
        const int parent_v = find_parent(v);

        parent[parent_u] = parent_v;
    }
};