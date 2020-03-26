class Solution {
public:
    /**
     * @param start: The start points set
     * @param end: The end points set
     * @return: Return if the graph is cyclic
     */
    bool isCyclicGraph(vector<int> &start, vector<int> &end) {
        const int maxVertex = max(*max_element(start.begin(), start.end()), *max_element(end.begin(), end.end()));
        const int N = start.size();
        
        edge = vector<vector<int>>(maxVertex + 1, vector<int>{});
        color = vector<int>(maxVertex + 1, 0);
        
        for (int i = 0; i < N; i++) {
            edge[start[i]].push_back(end[i]);
        }
        
        for (int i = 1; i <= maxVertex; i++) {
            if (dfs(i)) return true;
        }
        return false;
    }
private:
    vector<vector<int>> edge;
    vector<int> color;
    bool dfs(int u) {
        if (color[u] == 1) return false;
        
        color[u] = -1;
        for (int v : edge[u]) {
            if (color[v] == -1) return true;
            if (color[v] == 1) continue;
            
            if(dfs(v)) return true;
        }
        color[u] = 1;
        return false;
    }
};
