class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        edge = vector<vector<int>>(n, vector<int>{});
        color = vector<int>(n, 0);
        this->destination = destination;
        
        for (const vector<int>& e : edges) {
            edge[e[0]].push_back(e[1]);
        }
        
        return dfs(source) == false;
    }
private:
    vector<vector<int>> edge;
    vector<int> color;
    int destination;
    
    bool dfs(int u) {
        color[u] = -1;
        for (int v : edge[u]) {
            if (v == destination) return false;
            if (color[v] == -1) return true;
            if (color[v] == 1 && dfs(v)) return true;
        }
        color[u] = 1;
        return false;
    }
};
