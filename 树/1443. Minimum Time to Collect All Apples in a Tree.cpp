class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        edge = vector<vector<int>>(n);
        has_apple = hasApple;
        for (auto& e : edges) {
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        
        auto [have, cost] = dfs(0, -1);
        
        if (have) return cost - 2;
        else return 0;
    }
private:
    vector<vector<int>> edge;
    vector<bool> has_apple;
    
    pair<bool, int> dfs(int u, int parent) {
        bool have = false;
        int cost = 2;
        if (has_apple[u]) have = true;
        
        for (int v : edge[u]) {
            if (v == parent) continue;
            
            auto [_have, _cost] = dfs(v, u);
            if (_have) {
                have = true;
                cost += _cost;
            }
        }
        return { have, cost };
    }
};