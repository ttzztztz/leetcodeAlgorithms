class Solution {
public:
    vector<int> color;
    vector<vector<int>> edge;
    bool dfs(int u, int parent, int col) {
        color[u] = col;
        
        for (int v : edge[u]) {
            if (v == parent) continue;
            
            if (color[v] == -1) {
                dfs(v, u, !col);
            } else if (color[v] == col) {
                return false;
            }
        }
        
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        color = vector<int>(N + 5, -1);
        edge = vector<vector<int>>(N + 5, vector<int>{});
        
        for (const vector<int>& dislike : dislikes) {
            edge[dislike[0]].push_back(dislike[1]);
            edge[dislike[1]].push_back(dislike[0]);
        }
        
        for (int u = 1; u <= N; u++) {
            if (color[u] == -1 && !dfs(u, 0, 1)) {
                return false;
            }
        }
        return true;
    }
};
