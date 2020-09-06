class Solution {
public:
    /**
     * @param row: the couples' initial seating
     * @return: the minimum number of swaps
     */
    int minSwapsCouples(vector<int> &row) {
        const int M = row.size(), N = M / 2;
        
        init(N);
        int answer = 0;
        for (int i = 0; i < M; i += 2) {
            const int u = row[i], v = row[i + 1];
            if ((u / 2) != (v / 2)) {
                merge(u / 2, v / 2);
            }
        }
        
        unordered_set<int> tmp;
        for (int i = 0; i < N; i++) {
            const int p = findParent(i);
            if (!tmp.count(p)) {
                tmp.insert(p);
                answer += max(0, size[p] - 1);
            }
        }
        return answer;
    }
private:
    vector<int> parent, size;
    void init(int N) {
        parent = size = vector<int>(N + 5, 0);
        for (int i = 0; i <= N; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int u) {
        if (u == parent[u]) {
            return parent[u];
        } else {
            return parent[u] = findParent(parent[u]);
        }
    }
    void merge(int u, int v) {
        const int parentU = findParent(u), parentV = findParent(v);
        if (parentU != parentV) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }
};
