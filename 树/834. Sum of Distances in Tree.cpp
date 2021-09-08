class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        this->n = n;
        ans = children_cnt = vector<int>(n);
        edge = vector<vector<int>>(n);
        for (auto& e : edges) {
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        
        dfs1(0, 0, -1);
        dfs2(0, -1);
        return ans;
    }
private:
    vector<int> ans, children_cnt;
    vector<vector<int>> edge;
    int n;
    
    int dfs1(int root, int dist, int parent) {
        ans[0] += dist;
        
        children_cnt[root] = 1;
        for (int v : edge[root]) {
            if (v == parent) continue;
            children_cnt[root] += dfs1(v, dist + 1, root);
        }
        return children_cnt[root];
    }
    
    void dfs2(int root, int parent) {
        for (int v : edge[root]) {
            if (v == parent) continue;
            ans[v] = ans[root] - children_cnt[v] + (n - children_cnt[v]);
            dfs2(v, root);
        }
    }
};