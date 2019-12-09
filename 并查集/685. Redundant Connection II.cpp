class Solution {
public:
    int parent[1005];
    void init() {
        for (int i = 0; i <= 1000; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        } else {
            return parent[u] = findParent(parent[u]);
        }
    }
    void merge(int u, int v) {
        const int parentU = findParent(u), parentV = findParent(v);

        if (parentU != parentV) {
            parent[parentU] = parentV;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();

        vector<int> answer{-1, -1};
        for (const vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];

            const int parentU = findParent(u), parentV = findParent(v);
            if (parentU == parentV) {
                answer[0] = u, answer[1] = v;
            } else {
                merge(u, v);
            }
        }
        return answer;
    }
};