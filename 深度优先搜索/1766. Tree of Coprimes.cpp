class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edg) {
        this->nums = nums;
        this->n = nums.size(), this->ans = vector<int>(n);
        this->edges = vector<vector<int>>(n + 1);
        for (auto& e : edg) {
            this->edges[e[1]].push_back(e[0]);
            this->edges[e[0]].push_back(e[1]);
        }
        this->path = vector<vector<int>>(51);
        
        dfs1(0, -1);
        dfs(0, -1);
        return ans;
    }
private:
    int n;
    vector<vector<int>> edges;
    unordered_map<int, int> nodeToDfsOrder;
    unordered_map<int, int> dfsToNodeOrder;
    vector<int> ans, nums;
    int idx = 0;
    
    void dfs1(int u, int parent) {
        nodeToDfsOrder[u] = idx;
        dfsToNodeOrder[idx] = u;
        
        idx++;
        for (int v : edges[u]) {
            if (parent == v) continue;
            dfs1(v, u);
        }
    }
    
    void dfs(int u, int parent) {
        int t = -1;
        for (int i = 1; i <= 50; i++) {
            if (!path[i].empty() && __gcd(i, nums[u]) == 1) {
                t = max(t, path[i].back());
            }
        }
        if (t == -1) ans[u] = -1;
        else ans[u] = dfsToNodeOrder[t];

        path[nums[u]].push_back(nodeToDfsOrder[u]);
        for (int v : edges[u]) {
            if (parent == v) continue;
            dfs(v, u);
        }
        path[nums[u]].pop_back();
    }
    
    vector<vector<int>> path;
};
