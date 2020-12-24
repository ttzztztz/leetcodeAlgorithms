class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        init(N);
        sort(logs.begin(), logs.end(), [](const auto& lhs, const auto& rhs) -> bool {
            return lhs[0] < rhs[0];
        });
        
        for (auto& log : logs) {
            const int ts = log[0], u = log[1], v = log[2];
            merge(u, v);
            if (size_[find_parent(u)] == N) return ts;
        }
        
        return -1;
    }
private:
    vector<int> parent_, size_;
    void init(int n) {
        parent_ = size_ = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent_[i] = i;
            size_[i] = 1;
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
            size_[parent_v] += size_[parent_u];
        }
    }
};
