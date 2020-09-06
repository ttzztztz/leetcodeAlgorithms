class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return answer;
    }
private:
    vector<vector<int>> answer;
    vector<int> cur;
    
    void dfs(const vector<vector<int>>& graph, int u) {
        cur.push_back(u);
        
        if (u == graph.size() - 1) {
            answer.push_back(cur);
            cur.pop_back();
            return;
        }
        
        for (int v : graph[u]) {
            dfs(graph, v);
        }
        cur.pop_back();
    }
};
