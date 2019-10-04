class Solution {
public:
    int parent[65], setSize[65];
    void init() {
        for (int i = 0; i < 65; i++) {
            setSize[i] = 1;
            parent[i] = i;
        }
    }
    int query(int u) {
        if (parent[u] == u) {
            return parent[u];
        } else {
            return parent[u] = query(parent[u]);
        }
    }
    void merge(int u, int v) {
        int parentU = query(u), parentV = query(v);
        if (parentU != parentV) {
            parent[parentU] = parentV;
            setSize[parentV] += setSize[parentU];
        }
    }
    int minSwapsCouples(vector<int>& row) {
        int N = row.size(), G = row.size() / 2;
        init();
        for (int i = 0; i < N; i += 2) {
            if (row[i] / 2 != row[i + 1] / 2) {
                merge(row[i] / 2, row[i + 1] / 2);
            }
        }

        int answer = 0;
        bool visited[65];
        std::memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N / 2; i++) {
            int u = query(i);
            if (!visited[u]) {
                visited[u] = true;
                answer += setSize[u] - 1;
            }
        }
        return answer;
    }
};