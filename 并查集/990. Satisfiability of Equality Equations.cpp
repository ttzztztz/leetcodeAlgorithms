class Solution {
public:
    int parent[30];
    void init() {
        for (int i = 0; i <= 26; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return parent[u];
        } else {
            return parent[u] = findParent(parent[u]);
        }
    }

    void merge(int u, int v) {
        int parentU = findParent(u), parentV = findParent(v);
        if (parentU != parentV) {
            parent[parentV] = parentU;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        init();

        for (const string& equation : equations) {
            if (equation[1] == '=') {
                merge(equation[0] - 'a', equation[3] - 'a');
            }
        }

        for (const string& equation : equations) {
            if (equation[1] == '!') {
                const int parentU = findParent(equation[0] - 'a'), parentV = findParent(equation[3] - 'a');

                if (parentU == parentV) {
                    return false;
                }
            }
        }

        return true;
    }
};