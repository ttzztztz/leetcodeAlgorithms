class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string labels) {
        this->labels = labels;
        
        emptyState = vector<int>(26, 0);
        answer = vector<int>(n, 0);
        edges = vector<vector<int>>(n, vector<int>{});
        
        for (const auto& p : e) {
            edges[p[0]].push_back(p[1]);
            edges[p[1]].push_back(p[0]);
        }
        
        dfs(0, -1);
        return answer;
    }
private:
    vector<int> emptyState, answer;
    vector<vector<int>> edges;
    string labels;
    vector<int> dfs(int u, int parent) {
        vector<int> cur = emptyState;
        cur[labels[u] - 'a']++;
        
        for (int v : edges[u]) {
            if (v == parent) continue;
            
            vector<int> f = dfs(v, u);
            for (int x = 0; x < f.size(); x++) cur[x] += f[x];
        }
        
        answer[u] = cur[labels[u] - 'a'];
        return std::move(cur);
    }
};
