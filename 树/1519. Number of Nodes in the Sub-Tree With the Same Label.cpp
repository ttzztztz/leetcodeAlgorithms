class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this->labels = labels;
        edge = vector<vector<int>>(n);
        ans = vector<int>(n, 0);
        
        for (auto& e : edges) {
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        
        dfs(0, -1);
        return ans;
    }
private:
    string labels;
    vector<vector<int>> edge;
    vector<int> ans;
    
    vector<int> dfs(int u, int parent) {
        vector<int> cnt(26, 0);
        cnt[labels[u] - 'a']++;
        
        for (auto& v : edge[u]) {
            if (v == parent) continue;
            auto next = dfs(v, u);
            for (int i = 0; i < 26; i++) cnt[i] += next[i];
        }
        
        ans[u] = cnt[labels[u] - 'a'];
        return cnt;
    }
};