class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        edges = vector<vector<int>>(n + 1);
        inform_time = informTime;
        for (int i = 0; i < n; i++) {
            if (manager[i] == -1) continue;
            edges[manager[i]].push_back(i);
        }
        
        dfs(headID, inform_time[headID]);
        return ans;
    }
private:
    vector<vector<int>> edges;
    vector<int> inform_time;
    int ans = 0;
    
    void dfs(int root, int dist) {
        ans = max(ans, dist);
        
        for (int v : edges[root]) {
            dfs(v, dist + inform_time[v]);
        }
    }
};