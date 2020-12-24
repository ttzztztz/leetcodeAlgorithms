class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        init(n);
        for (auto& edge : edges) {
            merge(edge[0], edge[1]);
        }
        unordered_set<int> all_parents;
        for (int i = 0; i < n; i++) {
            all_parents.insert(find_parent(i));
        }
        return all_parents.size();
    }
private:
    vector<int> parent_;
    void init(int n) {
        parent_ = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent_[i] = i;
        }
    }
    int find_parent(int u) {
        if (parent_[u] == u) return u;
        else return parent_[u] = find_parent(parent_[u]);
    }
    void merge(int u, int v) {
        const int parent_u = find_parent(u), parent_v = find_parent(v);
        if (parent_u != parent_v) {
            parent_[parent_u] = parent_v;
        }
    }
};
