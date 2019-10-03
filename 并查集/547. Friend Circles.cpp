class Solution {
public:
    int parent[205], answer;
    void init() {
        for (int i = 0; i < 205; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (u == parent[u]) {
            return u;
        } else {
            return parent[u] = findParent(parent[u]);
        }
    }
    void merge(int u, int v) {
        int parentU = findParent(u), parentV = findParent(v);
        if (parentU != parentV) {
            parent[parentU] = parentV;
            answer--;
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        if (M.size() == 0) {
            return 0;
        }
        init();
        answer = M.size();
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[i].size(); j++) {
                if (M[i][j] == 1) {
                    merge(i, j);
                }
            }
        }

        return answer;
    }
};