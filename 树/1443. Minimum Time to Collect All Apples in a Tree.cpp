class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        edge = vector<vector<int>>(n, vector<int>{});
        for (const auto& e : edges) edge[e[0]].push_back(e[1]), edge[e[1]].push_back(e[0]);
        for (const bool b : hasApple) if (b) appleCount++;
        
        auto answer = dfs(hasApple, 0, -1);
        return answer.first;
    }
private:
    vector<vector<int>> edge;
    int appleCount = 0;
    pair<int, int> dfs(const vector<bool>& hasApple, int u, int parent) { // totalDist, appleCount
        int totalDist = 0, appleCount = 0;
        if (hasApple[u]) appleCount++;
        
        for (int v : edge[u]) {
            if (v == parent) continue;
            
            auto child = dfs(hasApple, v, u);
            if (child.second > 0) {
                appleCount += child.second;
                totalDist += child.first + 2;
            }
        }
        
        return {totalDist, appleCount};
    }
};
