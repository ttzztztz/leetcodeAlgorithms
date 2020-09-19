class Solution {
public:
    /**
     * @param n: the number of servers
     * @param connections: connections
     * @return: Critical Connections in a Network
     */
    vector<vector<int>> criticalConnectionsinaNetwork(int n, vector<vector<int>> &connections) {
        edges = vector<vector<int>>(n + 1, vector<int>{});
        for (auto& v : connections) {
            edges[v[0]].push_back(v[1]);
            edges[v[1]].push_back(v[0]);
        }
        
        memset(dfn, 0xff, sizeof dfn);
        memset(low, 0x3f, sizeof low);
        
        dfs(0, -1);
        return ans;
    }
private:
    vector<vector<int>> edges;
    vector<vector<int>> ans;
    int dfn[100005], low[100005];
    int timestamp = 0;
    
    void dfs(int u, int p) {
        dfn[u] = low[u] = ++timestamp;
        for (int v : edges[u]) {
            if (v == p) continue;
            
            if (dfn[v] == -1) {
                dfs(v, u);
                
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], dfn[v]);
            }
            
            if (dfn[u] < low[v]) ans.push_back(vector<int>{ min(u, v), max(u, v) });
        }
    }
    
};
