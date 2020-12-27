class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for (int i = 0; i < wells.size(); i++) {
            pipes.push_back(vector<int>{ 0, i + 1, wells[i] });
        }
        
        sort(pipes.begin(), pipes.end(), [](const auto& lhs, const auto& rhs) -> bool {
            return lhs[2] < rhs[2];
        });
        
        init(n);
        int ans = 0;
        for (auto& pipe : pipes) {
            const int u = pipe[0], v = pipe[1], w = pipe[2];
            if (find_parent(u) != find_parent(v)) {
                merge(u, v);
                ans += w;
            }
        }
        return ans;
    }
private:
    vector<int> parent_;
    void init(int n) {
        parent_ = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) parent_[i] = i;
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
